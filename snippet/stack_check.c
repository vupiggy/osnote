int func(int *ptr)
{
	int i;

	if (ptr == NULL) {
		ptr = &i;
		return func(ptr);
	}
	return ptr > &i; /* >: downward, otherwise upward */
}

#define DOWNWARD	1
#define UPWARD		0

int stack_growth(void)
{
	return func(NULL) ? DOWNWARD : UPWARD;
}
