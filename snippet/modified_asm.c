asm volatile ("movl %%gs:%P1, %0"
	      : "=r" (out) : "i" (40) : "memory");
