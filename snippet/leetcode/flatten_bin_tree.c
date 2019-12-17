/* 中序递归 (left -> ...) -> root -> (right -> ...) */
static void
flatten_binary_tree(bst_t *root, bst_t **head, bst_t **tail)
{
	bst_t	*left_head  = root, *left_tail;
	bst_t	*right_head, *right_tail = root;
	
	if (root == NULL)
		return;
	if (root->left) {
		flatten_binary_tree(root->left, &left_head, &left_tail);
		left_tail->right = root;
		left_tail->left	 = NULL;
	}
	if (root->right) {
		flatten_binary_tree(root->right, &right_head, &right_tail);
		root->right = right_head;
		root->left  = NULL;
	}
	*head = left_head;
	*tail = right_tail;
}

/* 先序递归 root -> (left -> ...) -> (right -> ...) */
static void
flatten_binary_tree(bst_t *root, bst_t **head, bst_t **tail)
{
	bst_t	*left_head  = NULL, *left_tail  = root;
	bst_t	*right_head = NULL, *right_tail = root;
	
	if (root == NULL)
		return;
	if (root->left)
		flatten_binary_tree(root->left, &left_head, &left_tail);
	if (root->right)
		flatten_binary_tree(root->right, &right_head, &right_tail);

	if (left_head) {
		root->right = left_head;
		root->left  = NULL;
	}
	if (right_head) {
		left_tail->right = right_head;
		left_tail->left	 = NULL;
	}	
	*head = root;
	*tail = right_tail;
}

