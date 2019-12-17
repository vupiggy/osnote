list_t *
partition(list_t *head, int x)
{
	list_t *pl = NULL, *pge = NULL;
	list_t *pl_head = NULL, *pge_head = NULL;	
	for (; head; head = head->next;) {
		if(head->val < x) {
			if(pl != NULL) {
				pl->next = p;
				pl = pl->next;
			} else {
				pl = p;
				pl_head = p;
			}
		} else {
			if(pge != NULL) {
				pge->next = p;
				pge = pge->next;
			} else {
				pge = p;
				pge_head = p;
			}
		}
	}         
	if(pge != NULL)
		pge->next = NULL;
	if(pl_head != NULL) {
		pl->next = pge_head;
		return pl_head;
	}	
	return pge_head;
}
