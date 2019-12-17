public ListNode addTwoNumbers(ListNode l1, ListNode l2)
{
    int		carry = 0;
    int		digit = 0;
    ListNode	head  = null;
    ListNode	tail   = null;
    
    while (l1 != null && l2 != null) {
        digit = (l1.val + l2.val + carry) % 10;
        carry = (l1.val + l2.val + carry) / 10;
	
        ListNode newNode = new ListNode(digit);
        if (head == null)
            head = newNode;
        else
            tail.next = newNode;
	
        tail = newNode;
        l1   = l1.next;
        l2   = l2.next;
    }

    if (l1 == null)
	l1 = l2;    

    while (l1 != null) {
        digit = (l1.val + carry) % 10;
        carry = (l1.val + carry) / 10;
	tail.next = new ListNode(digit);
        tail = tail.next;
        l1 = l1.next;
    }
    
    if (carry > 0) {
        ListNode newNode = new ListNode(carry);
        tail.next = newNode;
    }
    return head;
}
