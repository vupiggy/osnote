#define LOCK_PREFIX_HERE \
		".section .smp_locks,\"a\"\n"	\
		".balign 4\n"			\
		".long 671f - .\n" /* offset */	\
		".previous\n"			\
		"671:"
#define LOCK_PREFIX 		LOCK_PREFIX_HERE "\n\tlock; "
#define UNLOCK_LOCK_PREFIX 	LOCK_PREFIX

#define __xchg_op(ptr, arg, op, lock)				\
	({							\
		__typeof__ (*(ptr)) __ret = (arg);		\
		asm volatile (lock #op "l %q0, %1\n"		\
			 : "+r" (__ret), "+m" (*(ptr))		\
			 : : "memory", "cc"); })

#define __xadd(ptr, inc, lock)	__xchg_op((ptr), (inc), xadd, lock)
#define xadd(ptr, inc)		__xadd((ptr), (inc), LOCK_PREFIX)

#define ACCESS_ONCE(x)		(*(volatile typeof(x) *)&(x))

#if (CONFIG_NR_CPUS < 256)
typedef u8  __ticket_t;
typedef u16 __ticketpair_t;
#else
typedef u16 __ticket_t;
typedef u32 __ticketpair_t;
#endif

/*
 * x86 little endian:
 *
 * |<---        head_tail        --->|
 * +----------------+----------------+
 * |      tail      |      head      |
 * +----------------+----------------+
 * |<---         tickets         --->|
 *
 *
 * +----------------+----------------+
 * |      tail    |1|      head      | inc
 * +----------------+----------------+
 *
 * tail: ticket, head: turn
 * lock: tail <- tail + 1; unlock: head <- head + 1
 * ticket == turn: succeeded, otherwise spinning wait
 */
typedef struct arch_spinlock {
	union {
		__ticketpair_t head_tail;
		struct __raw_tickets {
			__ticket_t head, tail;
		} tickets;
	};
} arch_spinlock_t;

static __always_inline void arch_spin_lock(arch_spinlock_t *lock)
{
	register struct __raw_tickets inc = { .tail = 1 };

	inc = xadd(&lock->tickets, inc);
	if (likely(inc.head == inc.tail))
		goto out;

	inc.tail &= ~TICKET_SLOWPATH_FLAG;
	for (;;) {
		if (inc.head == inc.tail)
			break;
		cpu_relax();
		inc.head = ACCESS_ONCE(lock->tickets.head);
	}
out:	barrier();	/* make sure nothing creeps before the lock is taken */
}

#if (NR_CPUS < 256)
static __always_inline void __ticket_spin_unlock(arch_spinlock_t *lock)
{
	asm volatile(UNLOCK_LOCK_PREFIX "incb %0"
		     : "+m" (lock->head_tail)
		     :
		     : "memory", "cc");
}
#else
static __always_inline void __ticket_spin_unlock(arch_spinlock_t *lock)
{
	asm volatile(UNLOCK_LOCK_PREFIX "incw %0"
		     : "+m" (lock->head_tail)
		     :
		     : "memory", "cc");
}
#endif

static __always_inline void arch_spin_unlock(arch_spinlock_t *lock)
{
	__ticket_spin_unlock(lock);
}
