void connect(TreeLinkNode *root)
{
	TreeLinkNode *pre;
	if(root == NULL) return;
	
	queue<TreeLinkNode*> myqueue;
	myqueue.push(root);
	myqueue.push(NULL); // NULL作为队列中每层节点之间的间隔
	
	pre = NULL;
	while(myqueue.empty() == false) {
		TreeLinkNode *p = myqueue.front();
		myqueue.pop();
		if(p != NULL) {
			if (p->left)  myqueue.push(p->left);
			if (p->right) myqueue.push(p->right);
		} else if (!myqueue.empty())
			myqueue.push(NULL);
		if (pre != NULL)
			pre->next = p;
		pre = p;
	}
}
