ListNode *insertionSortList(ListNode *head) {
	if(head == NULL || head->next == NULL)
		return head;
	
	ListNode	*p	= head->next;
	ListNode	*pstart = new ListNode(0);
	ListNode	*pend	= head;
	
	pstart->next = head; //为了操作方便，添加一个头结点
	while(p != NULL) {
		ListNode *tmp = pstart->next, *pre = pstart;
		while(tmp != p && p->val >= tmp->val) {
			tmp = tmp->next;
			pre = pre->next;
		}
		if(tmp == p)
			pend = p;
		else {
			pend->next = p->next;
			p->next = tmp;
			pre->next = p;
		}
		p = pend->next;
	}
	head = pstart->next;
	delete pstart;
	return head;
}

