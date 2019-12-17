bool isMirror(TreeNode *tree0, TreeNode *tree1) {
	if (tree0 == NULL && tree1 == NULL)
		return true;
	if ((tree0 == NULL && tree1 != NULL) ||
			(tree0 != NULL && tree1 == NULL))
		return false;
	return tree0->val == tree1->val && 
		isMirror(tree0->left, tree1->right) && 
		isMirror(tree0->right, tree1->left);
}
bool isSymmetric(TreeNode *root) {
	return root == NULL ? true : isMirror(root->left, root->right);
}
