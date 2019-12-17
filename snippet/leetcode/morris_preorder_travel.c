int
morris_preorder_travel(bin_tree *root, visit_function fn)
{
	bin_tree *pred;
	
	while (root) {
		if (root->left) {
			pred = root->left;
			while (pred->right && pred->right != root)
				pred = pred->right;
			if (!pred->right) {
				fn(root);
				pred->right = root;
				root = root->left;
			} else {
				pred->right = NULL;
				root = root->right;
			}
		} else {
			fn(root);
			root = root->right;
		}
	}
}
