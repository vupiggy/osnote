int
inorder_travel(bin_tree *root, visit_function fn)
{
	struct stack stk = { NULL };

	while (root || !stack_empty(&stk)) {
		if (root) {
			if (stack_push(&stk, root) < 0)
				return -1;
			root = root->left;
		} else {
			root = stack_pop(&stk);
			fn(root);
			root = root->right;
		}
	}
}
