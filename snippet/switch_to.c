#define switch_to(prev,next,last) \
	asm volatile(SAVE_CONTEXT						\
	     "movq %%rsp,%P[threadrsp](%[prev])\n\t" /* save RSP */		\
	     "movq %P[threadrsp](%[next]),%%rsp\n\t" /* restore RSP */		\
	     "call __switch_to\n\`t"						\
	     ".globl thread_return\n"						\
	     "thread_return:\n\t"						\
	     "movq %%gs:%P[pda_pcurrent],%%rsi\n\t"				\
	     "movq %P[thread_info](%%rsi),%%r8\n\t"				\
	     LOCK "btr  %[tif_fork],%P[ti_flags](%%r8)\n\t"			\
	     "movq %%rax,%%rdi\n\t"						\
	     "jc   ret_from_fork\n\t"						\
	     RESTORE_CONTEXT							\
	     : "=a" (last)							\
	     : [next] "S" (next), [prev] "D" (prev),				\
	       [threadrsp] "i" (offsetof(struct task_struct, thread.rsp)),	\
	       [ti_flags] "i" (offsetof(struct thread_info, flags)),		\
	       [tif_fork] "i" (TIF_FORK),					\
	       [thread_info] "i" (offsetof(struct task_struct, thread_info)),	\
	       [pda_pcurrent] "i" (offsetof(struct x8664_pda, pcurrent))	\
	     : "memory", "cc" __EXTRA_CLOBBER)
