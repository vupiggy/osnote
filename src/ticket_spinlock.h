/* include/asm-x86/spinlock.h (linux 2.6.25) */
static inline void __raw_spin_lock(raw_spinlock_t *lock)
{
	int tmp, inc = 0x00010000;

	__asm__ __volatile__ (
		"lock ; xaddl %0, %1\n"
		"movzwl %w0, %2\n\t"
		"shrl $16, %0\n\t"
		"1:\t"
		"cmpl %0, %2\n\t"
		"je 2f\n\t"
		"rep ; nop\n\t"
		"movzwl %1, %2\n\t"
		/* don't need lfence here, because loads are in-order */
		"jmp 1b\n"
		"2:"
		:"+Q" (inc), "+m" (lock->slock), "=r" (tmp)
		:
		:"memory", "cc");
}
static inline void __raw_spin_unlock(raw_spinlock_t *lock)
{
  	__asm__ __volatile__(
		UNLOCK_LOCK_PREFIX "incw %0"
		:"+m" (lock->slock)::"memory", "cc");
}
