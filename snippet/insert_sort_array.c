void insert_sort(int *array, int len)
{
	int i, j;
	for (i = 1; i < len - 1; i++)
		for (j = i; j > 0 && array[j] < array[j - 1]; j--)
			swap_entry(array, j, j - 1);
}
