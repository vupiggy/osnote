static list_t *
ring_check(list_t *list)
{
	list_t *slow,  *fast;
	for (slow = list, fast = list;
	     fast != NULL && fast->next != NULL && slow != fast;
	     slow = slow->next, fast = fast->next->next) ;

	/* true: there is ring, false: there isn't.
	 * 
	 * return fast != NULL && fast->next != NULL;
	 */

	if (fast == NULL || fast->next == NULL)
		return NULL; 
	
	slow = list;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

