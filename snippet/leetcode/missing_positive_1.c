#include <unistd.h>

int int_compare(const void * v1, const void *v2)
{
	return *(int *)v1 - *(int *)v2;
}

int
First_missing_positive(int *array, int sz)
{
	int n = 1;
	int i;
	
	qsort(array, sz, sizeof(int), int_compare);
	for (i = 0; i < sz; i++) {
		if (array[i] >= n) {
			if (array[i] > n)
				break;
			n++;
		}
	}
	
	return n;
}
