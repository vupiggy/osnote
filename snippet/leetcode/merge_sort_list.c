static struct list_t *
merge_sorted_list_iterative(struct list_t *l0, struct list_t *l1)
{
	/* 用一个排头兵解决链表头问题，否则需要在循环开始前确定尾指针是
	 * 哪一个并且移动对应链表头，看起来不美。
	 */
	struct int64_list *head;
	struct int64_list **tailp = &head, *h0 = l0, *h1 = l1;

	if (h0 == NULL) return h1;
	if (h1 == NULL) return h0;

	while (h0 && h1)  {
		if (h0->data < h1->data) {
			*tailp = h0;
			h0 = h0->next;
			tailp = &(*tailp)->next;
		} else {
			*tailp = h1;
			h1 = h1->next;
			tailp = &(*tailp)->next;
		}
	}
	
	return head;
}

static list_t *
merge_sorted_list_recursive(list_t *list0, list_t *list1)
{
	list_t *head;
	
	if (list0 == NULL) return list1;
	if (list1 == NULL) return list0;

	/* 取两个表头中小者作为新表头，它的下一个节点由递归函数决定 */
	if (list0->val < list1->val) {
		head = list0;
		head->next =
			merge_sorted_list_recursive(list0->next, list1);
	} else {
		head = list1;
		head->next =
			merge_sorted_list_recursive(list0, list1->next);
	}
	return head;
}

static list_t *
__sort_list(list_t **head, int length)
{
	if (length == 1) {
		list_t *temp = *head;
		*head = (*head)->next;
		temp->next = NULL;
		return temp;
	}

	return merge_sorted_list(__sort_list(head, length / 2),
				 __sort_list(head, length - length / 2));
}

list_t *
sort_list(list_t *head)
{
	int	len  = 0;  
	list_t *list = head;
	
	for (list = head, len = 0; list; list = list->next, len++);
	return __sort_list(&head, len);
}
