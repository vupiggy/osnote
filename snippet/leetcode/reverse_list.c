/* 朴素的算法 */
static struct list_t *
reverse_list_t(struct list_t *head)
{
	struct list_t *new_head = NULL;
	struct list_t *next;

	while (head != NULL) {
		next	   = head->next;
		head->next = new_head;
		new_head   = head;
		head	   = next;
	}

	return new_head;
}

/* 算法其实和上面朴素的算法类似，重指针的妙处在于一个指针维护两个信息并
 * 且最终可以正确返回可能已经修改过的头指针无需专门处理。
 */
static inline struct list_t *
reverse_list_t_mn(struct list_t *head, int m, int n)
{
	struct list_t	**reverse_head = &head, *reverse_tail;
	struct list_t	 *next, *cur;
	int		  count;

	for (count = 0 /* 1 if one-based index */; *reverse_head && count < m;
	     count++, reverse_head = &(*reverse_head)->next);

	if (*reverse_head == NULL)
		return NULL;

	cur = *reverse_head;
	reverse_tail = cur;
	for (; cur && count <= n; count++) {
		next	      = cur->next;
		cur->next     = *reverse_head;
		*reverse_head = cur;
		cur	      = next;
	}
	reverse_tail->next = cur;

	if (cur == NULL && count <= n)
		return NULL;

	return head;
}
