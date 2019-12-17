list_t *rotate_list(list_t *head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
		return head;
	
        /* 找到倒数第k个节点 new_head，
	 * prev是其前驱(k  = k % 链表长度)
	 */
        list_t *new_head = head, *prev = NULL, *p = head;
	
        for (int i = 1; i < k; i++) {
		p = p->next;
		if (p == NULL)
			p = head; /* 回绕 */
        }
        
        while (p->next) {
		prev = new_head;
		new_head = new_head->next;
		p = p->next;
        }
        if (prev == NULL)
		return head; /* k恰好等于链表的长度的整数倍 */
	
        p->next = head;
        prev->next = NULL;
        return new_head;
}


