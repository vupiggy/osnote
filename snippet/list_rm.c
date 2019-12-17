typedef struct list_node_s {
	struct list_node_s *next;
	unsigned long value;
} list_node;

list_node *
list_lookup_by_key(list_node *head, unsigned long key)
{
	while (head) {
		if (head->value == key)
			return head;
		head = head->next;
	}

	return NULL;
}

list_node *
list_rm_by_key(list_node **head, unsigned long key)
{
	list_node **cur = head;
	list_node *del_head = NULL;

	while (*curr) {
		if (*curr->value == key) {
			list_node *tmp = *curr;
			*curr = tmp->next;
			tmp->next = del_head;
			del_head = tmp;
		} else
			curr = &(*curr)->next;
	}

	return del_head;
}
