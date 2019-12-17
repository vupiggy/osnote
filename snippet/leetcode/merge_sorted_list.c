#include <stdio.h>
#include "list.h"

static struct int64_list *
merge_sorted_list_recursive(struct int64_list *l0, struct int64_list *l1)
{
	struct int64_list *head;

	if (l0 == NULL) return l1;
	if (l1 == NULL) return l0;

	/* 递归思路很简单，比较两个链表头，取小的那个作为新链表头，它的
	 * 下一个是谁取决于递归作用在移动后的链表和刚才表头大的那个链表。
	 */
	if (l0->data < l1->data) {
		head = l0;
		head->next = merge_sorted_list_recursive(l0->next, l1);
	} else {
		head = l1;
		head->next = merge_sorted_list_recursive(l0, l1->next);
	}
	return head;
}

static struct int64_list *
merge_sorted_list(struct int64_list *l0, struct int64_list *l1)
{
	/* 用一个排头兵解决链表头问题，否则需要在循环开始前确定尾指针是
	 * 哪一个并且移动对应链表头，看起来不美。
	 */
	struct int64_list dummy = {0, NULL};
	struct int64_list *tail = &dummy, *h0 = l0, *h1 = l1;

	if (h0 == NULL) return h1;
	if (h1 == NULL) return h0;

	while (h0 && h1) {
		if (h0->data < h1->data) {
			tail->next = h0;
			h0 = h0->next;
			tail = tail->next;
		} else {
			tail->next = h1;
			h1 = h1->next;
			tail = tail->next;
		}
	}
	tail->next = (h0 == NULL ? h1 : h0);
	return (l0->data < l1->data) ? l0 : l1;
}

#define MAX	100000
#define LEN	100
int
main(int argc, char **argv)
{
	struct int64_list *list0, *list1, *list2;

	reseed();
	list0 = gen_int64_sorted_list(MAX, LEN);
	list1 = gen_int64_sorted_list(MAX, LEN);
	print_int64_list(list0);
	print_int64_list(list1);

	list2 = merge_sorted_list(list0, list1);
	print_int64_list(list2);
	
	return 0;
}
