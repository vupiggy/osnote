static struct int64_list *
remove_nth_from_end(struct int64_list *head, int n)
{
	struct int64_list **h = &head, *t = head;

	while (n > 0 && t != NULL) {
		t = t->next;
		n--;
	}

	if (t == NULL) {
		/* n 太大 */
		if (n > 0 || head == NULL)
			return NULL;
	}

	/* 到了该删除的节点没法删，用一重指针正确处理的逻辑比较复杂，双
	 * 重指针使得逻辑简单化。
	 */
	while (t != NULL) {
		h = &(*h)->next;
		t = t->next;
	}

	t = *h;
	*h = t->next;
	free(t);

	return head;
}

/* 递归版本，一路递归到最后一级，在那里返回级数为零，之后返回的每一层查
 * 自己的级数，如果级数为 n  就在那一层删除节点，如果小于 n 就返回当前级
 * 数，如果已经删除节点就通过一个特殊值通知之后的每一层不再做任何处理。
 */
static int
_remove_nth_from_end(struct int64_list *head, int n)
{
	struct int64_list *tmp;
	int level;

	if (head == NULL)
		return 0;
	
	level = _remove_nth_from_end(head->next, n);
	if (level < 0)
		return level;
	
	level++;
	if (level == n + 1) {
		tmp = head->next;
		head->next = head->next->next;
		free(tmp);
		level = -1;
	}

	return level;
}

static struct int64_list *
remove_nth_from_end(struct int64_list *head, int n)
{
	struct int64_list *tmp;
	
	if (_remove_nth_from_end(head, n) < 0)
		return head;

	tmp = head->next;
	free(head);
	return tmp;
}
