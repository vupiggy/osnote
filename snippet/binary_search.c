int
bin_search(int *array, int len, int target)
{
	int l = 0, u = len - 1, m;

	while (l <= u) {
		m = (l + u) / 2;
		
		if (target == array[m])
			return m;
		else if (target < array[m])
			u = m - 1;
		else
			l = m + 1;
	}

	return -1;
}

int
bin_search(int *array, int l, int u, int target)
{
	int m;
	if (l > u)
		return -1;

	m = (l + u) / 2;
	if (target == array[m])
		return m;
	else if (target < array[m])
		return bin_search(array, l, m - 1, target);
	return bin_search(array, m + 1, u, target);
}
