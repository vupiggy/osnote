int
lomuto_partition(int64_t *array, int lo, int hi)
{
	int i;
	int64_t t = array[hi];

	for (i = lo - 1; lo < hi; lo++)
		if (array[lo] < t)
			swap_entry(array, lo, ++i);
	swap_entry(array, hi, ++i);

	return i;
}

int
hoare_partition(int64_t *a, int lo, int hi)
{
	int i = lo, j = hi + 1;
	int v = a[lo];
	while (1) {
		while (a[++i] < v) if (i == hi) break;
		while (a[--j] > v) if (j == lo) break;
		if (i >= j) break;
		swap_entry(a, i, j);
	}
	swap_entry(a, lo, j);
	return j;
}

static int
_thekth_smallest(int64_t *array, int l, int u, int k)
{
	int p;

	while (u > l) {
		int len;
		p = hoare_partition(array, l, u);
		len = p - l + 1;
		
		if (k == len)
			return array[p];
		if (k > len) {
			k -= len;
			l = p + 1;
		} else
			u = p - 1;
	}

	return array[l];
}

static int
thekth_smallest(int64_t *array, int len, int k)
{
	return _thekth_smallest(array, 0, len - 1, k);
}
