static int
find_root(int *array, int val, int l, int u)
{
	for (; l <= u; l++)
		if (array[l] == val)
			break;
	BUG_ON(l > u);
	
	return l;
}

/* build a binary tree from in-order and post-order traversal */
bin_tree *
build_tree(int *in_order,   int in_start, int in_end,
	   int *post_order, int po_start, int po_end)
{
	bin_tree *root;
	int root_pos;
	int left_len;

	if (in_start < in_end)
		return NULL;

	root = malloc(sizeof(*root));
	if (root == NULL)
		return NULL;

	root->data  = post_order[po_end];
	root_pos    = find_root(in_order, root->data, in_start, in_end);
	left_len    = root_pos - in_start;
	
	root->left  = build_tree(in_order, in_start, root_pos - 1,
				 post_order, po_start, po_start + left_len - 1);
	/* errno  is  thread  safe  since  it  is  not  a  simple  value
	 * anymore. If  too paranoid,  return a  poison pointer  such as
	 * 0xdeadbeef or 0xbaddcafe.
	 */
	if (errno == ENOMEM)
		goto err;
	
	root->right = build_tree(in_order, root_pos + 1, in_end,
				 post_order, po_start + left_len, po_end - 1);
	if (errno == ENOMEM)
		goto err;

	return root;
	
free_left_tree:
	/* TODO: Free the whole left tree */
	;

free_root:
	free(root);
	return NULL;
}

/* build a binary tree from in-order and pre-order traversal */
bin_tree *
build_tree(int *in_order,  int i_start, int i_end,
	   int *pre_order, int p_start, int p_end)
{
	bin_tree *root;
	int root_pos;
	int left_len;

	if (i_start < i_end)
		return NULL;
	
	root = malloc(sizeof(*root));
	if (root == NULL)
		return NULL;
	
	root->data = pre_order[p_start];
	root_pos   = find_root(in_order, i_start, i_end);
	left_len   = root_pos - i_start;
	
	root->left = build_tree(in_order,  i_start, root_pos - 1,
				pre_order, p_start + 1, p_start + left_len);
	if (errno == ENOMEM)
		goto err;

	root->right = build_tree(in_order, root_pos + 1, i_end,
				 pre_order, p_start + left_len + 1, pend);
	if (errno == ENOMEM)
		goto err;

	return root;

err:
	free(root);
	return NULL;
}
