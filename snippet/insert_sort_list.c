list *
insert_sort_list(list *head)
{
	list_t **plist = &head;

	while (*plist) {
		list_t **curr;

		for (curr = &head;
		     curr != plist && (*curr)->val < (*plist)->val;
		     curr = &(*curr)->next);

		if (curr == plist)		
			plist = &(*plist)->next;
		else {
			list_t *tmp = *plist;
			*plist = tmp->next;

			tmp->next = *curr;
			*curr = tmp;
		}
	}

	return head;
}

