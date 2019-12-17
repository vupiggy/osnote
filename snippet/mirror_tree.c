bintree_t* mirror_recursive(bintree_t *root)  
{
	bintree_t *tmp;

	/* termination */
	if (root == NULL)
		return NULL;  

	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	
	root->left = mirror_recursive(root->left);
	root->right = mirror_recursive(root->right); 
  
	return root;
}  

static bintree_t *
mirror_iterative(bintree_t *root)
{
	struct stack stk = { NULL };

	while (root || !stack_is_empty(&stk)) {
		if (root) {
			/* preorder: visit_fn(root); */
			bintree_t *tmp = root->left;
			root->left = root->right;
			root->right = tmp;
			
			/* check return value, can be NULL! */
			stack_push(&stk, root);
			root = root->left;
		} else
			root = stack_pop(&stk)->right;
	}

	return root;
}
