public List<Integer> preorderTraversal(TreeNode root)
{
    if (root == null)
	return null;
    
    List<Integer> nodes = new List<Integer>;
    Stack stack;

    while (root != null && !stack.empty()) {
	if (root != null) {
	    nodes.add(new Integer(root.val));
	    stack.push(root);
	    root = root.left;
	} else {
	    root = stack.pop().right;
	}
    }

    return res;
}
