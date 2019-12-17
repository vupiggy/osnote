int counting_sort(int *src, int *dst, int sz, int k)
{
	int	 i;
	int	*counts = malloc(sizeof(*counts) * k);

	if (counts == NULL) {
		perror("malloc");
		return -1;
	}

	for (i = 0; i < sz; i++)
		counts[src[i]]++;

	for (i = 1; i < k; i++)
		counts[i] = counts[i] + counts[i - 1];
	/* counts[i]: <= i 的元素个数 */

	for (i = sz - 1; i >=0; i--) {
		dst[counts[src[i]]] = src[i];
		counst[src[i]]--;
	}

	return 0;
}
