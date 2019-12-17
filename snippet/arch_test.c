static int
is_little_endian(void)
{
#if 0
	union {
		int	i;
		char	c[4];
	} u = { 0 };
	u.i = 1;
	return u.c[0];
#else
	int i = 1;
	return *(char *)&i;
#endif
}

static int
stack_growth(void)
{
	static char	*addr = NULL;
	char		 dummy;

	if (addr == NULL) {
		addr = &dummy;
		return stack_growth();
	}

	return addr - &dummy;
}

int
main(void)
{
	printf("%s-endian machine with ",
	       is_little_endian() > 0 ? "little" : "big");
	printf("%s growing stack\n",
	       stack_growth() > 0 ? "downward" : "upward");

	return 0;
}
