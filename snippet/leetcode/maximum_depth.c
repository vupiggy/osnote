int maxDepth(TreeNode *root) {
	int dl, dr;
	if (root == NULL) return 0;
	dl = maxDepth(root->left);
	dr = maxDepth(root->right);
	return 1 + (dl > dr ? dl : dr);
}
