void
preorder_travel(bin_tree *tree, visit fn)
{
	if (tree == NULL)
		return;
	fn(tree);
	preorder_travel(tree->left);
	preorder_travel(tree->right);
}
void
inorder_travel(bin_tree *tree, visit fn)
{
	if (tree == NULL)
		return;	
	bin_tree_travel(tree->left);
	fn(tree);
	bin_tree_travel(tree->right);
}
void
postorder_travel(bin_tree *tree, visit fn)
{
	if (tree == NULL)
		fn(tree);	
	bin_tree_travel(tree->left);
	bin_tree_travel(tree->right);
	fn(tree);;
}
