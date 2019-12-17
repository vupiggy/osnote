/* include/asm-x86_64/spinlock.h (2.6.11) */
#define LOCK_SECTION_START(extra)               \
        ".subsection 1\n\t"                     \
        extra                                   \
        ".ifndef " LOCK_SECTION_NAME "\n\t"     \
        LOCK_SECTION_NAME ":\n\t"               \
        ".endif\n"
#define LOCK_SECTION_END                        \
        ".previous\n\t"
#define spin_lock_string			\
	"\n1:\t"				\
	"lock ; decb %0\n\t"			\
	"js 2f\n"				\
	LOCK_SECTION_START("")			\
	"2:\t"					\
	"rep;nop\n\t"				\
	"cmpb $0,%0\n\t"			\
	"jle 2b\n\t"				\
	"jmp 1b\n"				\
	LOCK_SECTION_END

#define spin_unlock_string			\
	"movb $1,%0"				\
	:"=m" (lock->lock) : : "memory"

static inline void _raw_spin_lock(spinlock_t *lock)
{
	__asm__ __volatile__(
		spin_lock_string
		:"=m" (lock->lock) : : "memory");
}

static inline void _raw_spin_unlock(spinlock_t *lock)
{
	__asm__ __volatile__(
		spin_unlock_string
	);
}

/* kernel/spinlock.c (2.6.11) */
void __lockfunc _spin_lock(spinlock_t *lock)
{
	preempt_disable();
	_raw_spin_lock(lock);
}

void __lockfunc _spin_unlock(spinlock_t *lock)
{
	_raw_spin_unlock(lock);
	preempt_enable();
}

/* include/linux/spinlock.h (2.6.11) */
#define spin_lock(lock)		_spin_lock(lock)
#define spin_unlock(lock)	_spin_unlock(lock)
