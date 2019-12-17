static struct list_t *
split_list(struct list_t *head)
{
	struct list_t **head1 = &head, *head2 = head;

	while (head2 && head2->next) {
		head2 = head2->next->next;
		head1 = &(*head1)->next;
	}

	head2 = *head1;
	*head1 = NULL;
	
	return head2;
}

static struct list_t *
merge_list(struct list_t *list1, struct list_t *list2)
{
	struct list_t *head = list1;
	
	while (list1 && list2) {
		struct list_t *tmp = list1->next;

		list1->next = list2;
		list1 = list2;
		list2 = tmp;
	}

	return head;
}

static struct list_t *
reverse_list(struct list_t *head)
{
	struct list_t *new_head = NULL, *next;

	while (head) {
		next	   = head->next;
		head->next = new_head;
		new_head   = head;
		head	   = next;
	}

	return new_head;
}

static void
reorder_list(struct list_t *head)
{
	struct list_t *head1 = head, *head2;

	head2 = split_list(head);
	head2 = reverse_list(head2);
	if (head1 != head2) /* only one node in the original list */
		merge_list(head1, head2);
}
