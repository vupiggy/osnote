int depthOfBalancedTree(TreeNode root)
{
    if (root == null)
	return 0;
    
    int dl = depthOfBalancedTree(root.left);
    int dr = depthOfBalancedTree(root.right);
    if (dl == -1 || dr == -1 || Math.abs(dl - dr) > 1)
            return -1;

    return 1 + (dl > dr ? dl : dr);
}

bool isTreeBalanced(TreeNode root)
{
    return depthOfBalancedTree(root) >= 0;
}
