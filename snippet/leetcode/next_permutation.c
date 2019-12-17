#include <stdio.h>
#include <stdlib.h>

static void
swap(int *array, int l, int r)
{
	int tmp = array[l];
	array[l] = array[r];
	array[r] = tmp;
}

static void
reverse(int *array, int l, int u)
{
	while (l < u) {
		swap(array, l, u);
		l++;
		u--;
	}
}

int *
next_permutation(int *p, int n)
{
	int i, j = n - 1;

	if (n == 0)
		return NULL;
	if (n == 1)
		return p;

	for (i = n - 1; i > 0; i--) {
		if (p[i - 1] < p[i]) {
			while (p[j] <= p[i - 1]) j--;
			swap(p, j, i - 1);
			break;
		}
	}
	
	reverse(p, i, n - 1);
	return p;
}

static inline unsigned int
factorial(unsigned int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int
the_first(int *num, unsigned int *n, int *k)
{
	unsigned int f = factorial(*n - 1);
	int res = num[*k / f];
	*k = *k % f;
	(*n)--;
	return res;
}

int
main(int argc, char **argv)
{
	int	 n;
	int	 i, j;
	int	*a;

	if (argc < 3) {
		fprintf(stderr, "Usage: next_permutation <n> <k>\n");
		return -1;
	}

	n = atoi(argv[1]);
	a = malloc(sizeof(*a) * n);

	for (i = 0; i < n; i++)
		a[i] = i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	i = j = atoi(argv[2]);
	
	while (i-- > 0) {
		next_permutation(a, n);
	}

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
