struct int64_list *
locate_middle(struct int64_list *head)
{
	struct int64_list *head1 = head, *head2 = head;

	while (head2 && head2->next /* stop at size / 2 + 1 */
	       /* && head2->next->next stop at size / 2 */) {
		head2 = head2->next->next;
		head1 = head1->next;
	}

	return head1;
}

struct int64_list *
remove_middle(struct int64_list *head)
{
	struct int64_list **head1 = &head, *head2 = head;

	while (head2 && head2->next /* stop at size / 2 + 1 */
	       && head2->next->next /* stop at size / 2 */) {
		head2 = head2->next->next;
		head1 = &(*head1)->next;
	}

	*head1 = (*head1)->next;

	return *head1;
}
