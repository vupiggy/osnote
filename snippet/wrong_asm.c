asm volatile ("movl %%gs:%1, %0"
	      : "=r" (out) : "i" (40) : "memory");
