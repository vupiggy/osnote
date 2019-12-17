static int _sum(tree_node *root, int sum)
{
    if(root == NULL)
	    return 0;
    
    if (root->left == NULL && root->right == NULL)
	    return sum * 10 + root.val;
    
    return _sum(root->left, sum * 10 + root->val) +
	   _sum(root->right, sum * 10 + root->val);
}

int sum(tree_node *root)
{
    return _sum(root, 0);
}
