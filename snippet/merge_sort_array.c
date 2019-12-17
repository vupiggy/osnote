static int
merge(int64_t *array, int l, int mid, int u)
{
	int64_t *left_subarray, *right_subarray;
	int size_left = mid - l + 1;
	int size_right = u - mid;
	int index_left = 0, index_right = 0, index_main = l;

	if ((left_subarray = malloc(sizeof(*array) * size_left)) == NULL)
		return -1;
	if ((right_subarray = malloc(sizeof(*array) * size_right)) == NULL) {
		free(left_subarray);
		return -1;
	}
	memcpy(left_subarray, array + l, size_left * sizeof(*array));
	memcpy(right_subarray, array + mid + 1, size_right * sizeof(*array));

	while (index_left < size_left && index_right < size_right) {
		if (left_subarray[index_left] <= right_subarray[index_right]) {
			array[index_main] = left_subarray[index_left];
			index_left++;
		} else {
			array[index_main] = right_subarray[index_right];
			index_right++;
		}
		index_main++;
	}

	/* Copy the rest in left or right subarray */
	if (index_left == size_left)
		memcpy(array + index_main, right_subarray + index_right,
		       (u - index_main + 1) * sizeof(*array));
	else
		memcpy(array + index_main, left_subarray + index_left,
		       (u - index_main + 1) * sizeof(*array));

	free(left_subarray);
	free(right_subarray);
	return 0;
}

static int
merge_sort(int64_t *array, int l, int u)
{
	int mid;
	
	if (l == u)
		return 0;

	mid = (u + l) / 2;
	merge_sort(array, l, mid);
	merge_sort(array, mid + 1, u);
	return merge(array, l, mid, u);
}
