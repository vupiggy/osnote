int
postorder_travel(bin_tree *root, visit_function fn)
{
	struct stack stk = { NULL };
	bin_tree *prev = NULL;

	while (root || !stack_empty(&stk)) {
		if (root) {
			if (stack_push(&stk, root) < 0)
				return -1;
			root = root->left;
			prev = NULL;
		} else if (prev != stack_top(&stk)->right) {
			root = stack_top(&stk)->right;
			prev = NULL;
		} else {
			prev = stack_pop(&stk);
			fn(prev);
		}
	}
}
