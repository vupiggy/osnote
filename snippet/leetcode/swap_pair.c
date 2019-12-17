list_t *swapPairs(list_t *head) {
        list_t **phead = &head;

	/* 最后一个不成对的节点就不用管了 */
        while (*phead && (*phead)->next) {
		list_t *next = (*phead)->next;
		list_t *prev = (*phead);
		
		prev->next = next->next;
		next->next = prev;
		*phead	   = next;
		phead	   = &prev->next; /* was &next->next->next ;) */
        }
        return head;
}
