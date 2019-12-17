/*    v = a[u]
 *
 *    +--------------+---+-------+---+
 *    |              | p |       | u |
 *    +--------------+---+-------+---+
 *    a[p] 是最后一个小于等于 u 的元素，所以最后需要将 u 翻到前面来。
 */
static int
lomuto_partition(int *array, int l, int u)
{
	int p, t;
	
	p = rand_in_range(l, u);
	swap_entry(array, p, u);

	t = array[u];
	for (p = l - 1; l < u; l++)
		if (array[l] < t)
			swap_entry(array, l, ++p);
	swap_entry(array, u, ++p);
	return p;
}

/*    v = a[u]
 *
 *    +--------------+---+-------+---+
 *    |              |i,j|       | u |
 *    +--------------+---+-------+---+
 *    a[i/j] == u，无所谓是否swap或返回谁
 *
 *    +----------+---+---+-------+---+
 *    |          | j | i |       | u |
 *    +----------+---+---+-------+---+
 *    a[j] < v, a[i] > u  => 循环结束需要 swap(a, i, u)，最后返回 i，
 */
static int
hoare_partition(int *a, int l, int u)
{
	int i = l - 1, j = u;
	int v;
	
	swap_entry(array, u, rand_in_range(l, u));
	v = a[u];
	
	while (1) {
		while (a[++i] < v)
			if (i == u) break;
		while (a[--j] > v )
			if (j == l) break;
		if (i >= j) break;
		swap_entry(a, i, j);
	}
	swap_entry(a, u, i);
	return i;
}

void
qsort(int *array, int l, int u)
{
	int p;
	if (l < u) {
#if 1
		p = hoare_partition(array, l, u);
#else
		p = lmuto_partition(array, l, u);
#endif
		qsort(array, l, p - 1);
		qsort(array, p + 1, u);
	}
}
