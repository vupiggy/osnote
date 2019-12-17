/* Binary Search */
int search_insert(int *array, int sz, int target)
{
  	int l = 0;
	int u = sz - 1;

	if (array == NULL || sz == 0)
		return 0;

	/* 当循环结束时，如果没有找到目标元素，那么 l 一定停在恰好比目标
	 * 大的索引上， r 一定停在恰好比目标小的索引
	 */
	while(l <= u) {
		int m = (l + u) / 2;
		
		if (array[m] == target)
			return m;
		
		if (array[m] < target)
			l = m + 1;
		else
			r = m - 1;
	}
	return l;
}
