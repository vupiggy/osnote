typedef struct list_node {
	int			 val;
	struct list_node	*next;
} list;

list *
reverse_list(list *head)
{
	list *new_head = NULL, *cur;

	while (head) {
		cur	   = head->next;
		head->next = new_head;
		new_head   = head;
		head	   = cur;
	}

	return new_head;
}
