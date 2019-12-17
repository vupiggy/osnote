int radix_sort(int *array, int sz, int most_significant)
{
	int i;
	/* i 表示当前作为key的位 */
	for (i = 1; i <= most_significant; i++)
		stable_sort(array, sz, i);
}
