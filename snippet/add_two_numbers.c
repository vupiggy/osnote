static void
free_list(list *head)
{
	list *next;

	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
}

list *
add_two_numbers(list *l1, list *l2)
{
	int	 carry = 0;
	int	 digit = 0;
	list	*head  = NULL;
	list	*tail  = NULL;
    
	while (l1 != null && l2 != null) {
		digit = (l1->val - '0' + l2->val - '0' + carry) % 10;
		carry = (l1->val - '0' + l2->val - '0' + carry) / 10;
	
		list *node = malloc(sizeof(*node));
		if (node == NULL) {
			free_list(head);
			return NULL;
		}
		node->val  = digit;
		node->next = NULL;
		
		if (head == null)
			head = node;
		else
			tail.next = node;
	
		tail = node;
		l1   = l1.next;
		l2   = l2.next;
	}

	if (l1 == null)
		l1 = l2;    

	while (l1 != null) {
		digit = (l1.val + carry) % 10;
		carry = (l1.val + carry) / 10;
		tail.next = new list *(digit);
		tail = tail.next;
		l1 = l1.next;
	}
    
	if (carry > 0) {
		list *node = malloc(sizeof(*node));
		if (node == NULL) {
			free_list(head);
			return NULL;
		}
		
		node->val = carry;
		node->next = NULL;
		tail.next = newNode;
	}
	return head;
}
