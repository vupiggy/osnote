static inline bst_t  *
new_bst(int key, bst_t *left, bst_t *right)
{
	bst_t *bst = malloc(sizeof(*bst));
	if (bst == NULL)
		return 0xbaddcafe;
	
	bst->key   = key;
	bst->left  = left;
	bst->right = right;

	return bst;
}

bst_t *
sorted_array_to_bst(int64_t *array, int l, int u)
{
	bst_t *left, *right;
	int mid = (l + u) / 2;

	if (l > u)
		return NULL;

	left = sorted_array_to_bst(array, l, mid - 1);
	if (left == 0xbaddcafe)
		return left;
	
	right = sorted_array_to_bst(array, mid + 1, u);
	if (right == 0xbaddcafe) {
		/* TODO: free the left subtree */
		return right;
	}
	
	return new_bst(array[(l + u) / 2], left, right);
}
