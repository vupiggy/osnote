static int
remove_duplicates(int *array, int n)
{
	int i;
	int end; /* 目前最后无重元素，end 和 i 之间就是重复的元素 array[end] */

	for (i = 0, end = 0; i < n - 1; i++) {
		if (array[i] == array[end])
			continue;
		array[++end] = array[i];
	}

	return end + 1; /* index -> length */
}
