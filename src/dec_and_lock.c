#include <linux/spinlock.h>
#include <asm/atomic.h>

/* NOTE NOTE NOTE! This is _not_ equivalent to
 *	if (atomic_dec_and_test(&atomic)) {
 *		spin_lock(&lock);
 *		return 1;
 *	}
 *	return 0;
 * because the spin-lock and the decrement must be "atomic".
 */
int _atomic_dec_and_lock(atomic_t *atomic, spinlock_t *lock)
{
	int counter;
	int newcount;
repeat:
	counter = atomic_read(atomic);
	newcount = counter-1;
	/* 大部分线程因为 dec 不到 0, 走快速通道, 不执行无谓的锁操作 */
	if (!newcount)
		goto slow_path;

	asm volatile("lock; cmpxchgl %1,%2"
		     :"=a" (newcount) /* cmpxchg 指令输出 */
		      /*     src                dst
		       *      |                  |
		       *      V                  V */
		     :"r" (newcount), "m" (atomic->counter), "0" (counter));

	/* 如果上面的 cmpxchg 指令失败, 它会修改 rax, 即 newcout 和 couter 不再相等 */
	if (newcount != counter)
		goto repeat;
	return 0;

	/* 有“可能“ dec 到 0 的线程竞争锁 */
slow_path:
	spin_lock(lock);
	if (atomic_dec_and_test(atomic))
		return 1;
	spin_unlock(lock);
	return 0;
}
