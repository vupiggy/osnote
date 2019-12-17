bool isValidBST(TreeNode *root)
{
	// 注意题目要求是 less than和greater than;
	stack<TreeNode*> S;
	TreeNode *pre = NULL, *p = root;
	
	while (p || S.empty() == false) {
		if (p) {
			S.push(p);
			p = p->left;
		} else if (S.empty() == false) {
			p = S.top();
			S.pop();
			/* The previously popped is predecessor */
			if (pre && p->val <= pre->val)
				return false;
			pre = p;
			p = p->right;
		}
	}
	return true;
}
