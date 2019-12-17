#define __build_read_lock_ptr(rw, helper)			\
	asm volatile(LOCK "subl $1,(%0)\n\t"			\
		     "js 2f\n"					\
		     "1:\n"					\
		     LOCK_SECTION_START("")			\
		     "2:\tcall " helper "\n\t"			\
		     "jmp 1b\n"					\
		     LOCK_SECTION_END				\
		     ::"a" (rw) : "memory")

#define RW_LOCK_BIAS		 0x01000000
#define RW_LOCK_BIAS_STR	"0x01000000"

#define __build_write_lock_ptr(rw, helper)			\
	asm volatile(LOCK "subl $" RW_LOCK_BIAS_STR ",(%0)\n\t" \
		     "jnz 2f\n"					\
		     "1:\n"					\
		     LOCK_SECTION_START("")			\
		     "2:\tcall " helper "\n\t"			\
		     "jmp 1b\n"					\
		     LOCK_SECTION_END				\
		     ::"a" (rw) : "memory")

#define _raw_read_unlock(rw)					\
	asm volatile("lock ; incl %0" :"=m" ((rw)->lock) : : "memory")
#define _raw_write_unlock(rw)					\
	asm volatile("lock ; addl $" 				\
		     RW_LOCK_BIAS_STR ",%0":"=m" 		\
		     ((rw)->lock) : : "memory")
