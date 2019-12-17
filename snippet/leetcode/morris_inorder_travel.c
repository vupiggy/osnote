int
morris_inorder_travel(bin_tree *root, visit_function *fn)
{
	bin_tree *pred;
	
	while (root) {
		if (root->left) {
			pred = root->left;
			while (pred->right && pred->right != root)
				pred = pred->right;
			
			if (!pred->right) {
				pred->right = root;
				root = root->left;
			} else {
				pred->right = NULL;
				fn(root);
				root = root->right;
			}				
		} else {
			fn(root);
			root = root->right;
		}
	}
}
