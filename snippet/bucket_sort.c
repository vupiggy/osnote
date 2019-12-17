/* assume array[x] \in [0, 1) */
void buicket_sort(double *array, int sz)
{
	list_t *buckets = malloc(sz * sizeof(*buckets));
	int i;

	for (i = 0; i < sz - 1; i++)
		init_list(buckets[i]);

	for (i = 0; i < sz - 1; i++)
		insert_into(array[i], buckets[sz * array[i]]);

	for (i = 0; i < sz - 1; i++)
		sort_list(buckets[i]);

	concatenate_lists(buckets, sz);
}
