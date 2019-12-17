#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

static int64_t
factorial(int sz)
{
	if (sz == 0)
		return 1;
	return factorial(sz - 1) * sz;
}

static inline void
swap(int *array, int l, int u)
{
	int tmp = array[l];
	array[l] = array[u];
	array[u] = tmp;
}

static inline int
find(int *array, int start, int end, int target)
{
	for (; start <= end; start++)
		if (array[start] == target)
			return 1;
	
	return 0;
}

static void
_permute(int ***p, int *num, int start, int end)
{
	int i;

	if (start == end) {
		memcpy(**p, num, (end + 1) * sizeof(*num));
		(*p)++;
		return;
	}
	
	for (i = start; i <= end; i++) {
		if (i == start || !find(num, start, i - 1, num[i])) {
			swap(num, start, i);
			_permute(p, num, start + 1, end);
			swap(num, start, i);
		}
	}
}

int **
permute(int *num, int sz)
{
	int	**p, **q;
	int64_t	  len = factorial(sz), i;

	p = malloc(sizeof(*p) * len);
	if (p == NULL)
		return NULL;

	if (sz == 0) {
		memset(p, 0, sizeof(*p) * len);
		return p;
	}
	
	for (i = 0; i < len; i++) {
		p[i] = malloc(sizeof(*p[i]) * sz);
		if (p[i] == NULL) {
			while (i > 0)
				free(p[i - 1]);
			return NULL;
		}
	}
	
	q = p;
	_permute(&q, num, 0, sz - 1);
	
	return p;
}     

int
main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int **p;
	int i, j;
	int len = sizeof(a) / sizeof(a[0]);

	if ((p = permute(a, len)) == NULL)
		return -1;

	for (i = 0; i < factorial(len); i++) {
		for (j = 0; j < len; j++)
			printf("%d ", p[i][j]);
		printf("\n");
	}

	return 0;
}
