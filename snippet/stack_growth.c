int func(int *ptr)
{
	int i;

	/* 终止条件 */
	if (ptr != NULL)
		return ptr > &i; /* >: downward, otherwise upward */

	ptr = &i;
	return func(ptr);
}

#define DOWNWARD	1
#define UPWARD		0

int stack_growth(void)
{
	return func(NULL) ? DOWNWARD : UPWARD;
}
