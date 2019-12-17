int
zigzag_travel(bin_tree *root, visit_function fn)
{
	struct stack stks[2] = { {NULL}, {NULL} };
	int level = 0;

	if (root == NULL)
		return 0;
	
	stack_push(&stks[0], root);

	while (!stack_empty(&stk0) || !stack_empty(&stk1)) {
		bin_tree *child0, *child1;
		int left_to_right = (level % 2 == 0);
		
		root = stack_pop(&stks[level % 2]);
		fn(root);
		
		child0 = left_to_right ? root->left : root->right;
		child1 = left_to_right ? root->right : root->left;

		if (child0)
			stack_push(&stks[(level + 1) % 2], child0);
		if (child1)
			stack_push(&stks[(level + 1) % 2], child1);
		
		if (stack_empty(&stk[level % 2]))
			level++;
	}

	return 0;
}
