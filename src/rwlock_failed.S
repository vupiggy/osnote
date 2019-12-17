#ifdef CONFIG_SMP
/* Support for read/write spinlocks. */
	.text
/* rax:	pointer to rwlock_t */	
ENTRY(__write_lock_failed)
	lock
	addl $RW_LOCK_BIAS,(%rax) /* undo the subl in the caller */
1:	rep			  /* pause */
	nop
	cmpl $RW_LOCK_BIAS,(%rax)
	jne 1b			  /* spin if failed */
	lock 
	subl $RW_LOCK_BIAS,(%rax)
	jnz  __write_lock_failed
	ret
/* rax:	pointer to rwlock_t */	
ENTRY(__read_lock_failed)
	lock
	incl (%rax)		  /* undo the subl in the caller */
1:	rep
	nop
	cmpl $1,(%rax)
	js 1b
	lock
	decl (%rax)
	js __read_lock_failed
	ret
#endif
