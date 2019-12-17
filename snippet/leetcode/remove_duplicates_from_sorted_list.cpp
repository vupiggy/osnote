/* Given  a sorted  linked list,  delete all  duplicates such  that each
 * element appear only once.
 */
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *cur = head;
		ListNode *tmp;
        
		while (cur && cur->next != NULL) {
			if (cur->val == cur->next->val) {
				tmp = cur->next;
				cur->next = cur->next->next;
				free(tmp);
				continue;
			}
			cur = cur->next;
		}
        
		return head;
	}
};


/* Given  a sorted  linked list,  delete all  nodes that  have duplicate
 * numbers, leaving only distinct numbers from the original list.
 * 
 * 一般这类有可能改变头指针的要想到用双重指针，双重指针有两个优美之处，
 * 其一是不需要单独处理头指针，其二是它可以找到满足条件节点的上一个节点
 * 的 next 指针用来进行删除操作，如只使用单重指针，就不得不引入额外的一
 * 个 prev 指针，使得逻辑复杂易错。
 */
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode **phead = &head;
		/* phead 指向下一个待查节点 */
		while (*phead) {
			ListNode *tail = *phead;
			
			while (tail->next != NULL && tail->val == tail->next->val) {
				ListNode *tmp = tail;
				tail = tail->next;
				free(tmp);
			}
			/* 如果尾指针移动过，说明处理了重复节点，跃过它
			 * 们。尾指针可能已经到达最后一个节点，这无须特
			 * 别处理，循环将自然终止。
			 */
			if (tail != *phead)
				*phead = tail->next;
			else	/* 此节点保留，继续检测 */
				phead = &(*phead)->next;
		}
        
		return head;
	}
};
