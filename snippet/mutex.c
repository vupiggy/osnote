typedef struct mutex_struct {
	int		 lock_flag;
	spinlock_t	 guard_lock;
	queue_t		 wait_q;
} mutex_t;

void lock_init(mutex_t *m) {
	m->lock_flag = 0;
	spinlock_init(&m->guard_lock);
	queue_init(&m->wait_q);
}

void lock(mutex_t *m)
{
	spin_lock(&m->guard_lock);
	
	if (m->flag == 0) {
		m->lock_flag = 1; // lock is acquired
		spin_unlock(&m->guard_lock);
	} else {
		queue_add(&m->q, gettid());
		spin_unlock(&m->guard_lock);
		/* unpark() can signal here */
		park();
	}
}
void unlock(lock_t *m) {
	spin_lock(&m->guard_lock);

	if (queue_empty(m->q))
		m->lock_flag = 0;
	else /* 注意：不修改 lock_flag，为即将被唤醒的线程 hold 住 */
		unpark(queue_remove(&m->wait_q));

	spin_unlock(&m->guard_lock);
}
