bst_t *
_list_to_bst(list_t **head, int l, int u)
{
	int	 m;
	bst_t	*left, *right;
	bst_t	*root;

	if (l > u)
		return NULL;

	m     = (l + u) / 2;
	left  = _list_to_bst(head, l, m - 1);
	root  = new_bst((*head)->val, NULL, NULL);
	*head = (*head->val);
	right = _list_to_bst(head, m + 1, u);
	
	root->left  = left;
	root->right = right;
	return root;
}

bst_t *
list_to_bst(list_t *head)
{
	int	 len;
	list_t	*list = head;
	
	for (len = 0; head; head = head->next, len++);
	return len == 0 ? NULL : _list_to_bst(&list, 0, len - 1);
}
