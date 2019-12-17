bool isIntersect(list_t *h1,list_t *h2)
{
	if(h1 == NULL || h2 == NULL)
		return false;
	
	while(h1->next != NULL)
		h1 = h1->next;

	while(h2->next != NULL)
		h2 = h2->next;

	if(h1 == h2)
		return true;
	
	return false;
}
