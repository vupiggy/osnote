static inline void __list_add_rcu(struct list_head * new,
				  struct list_head * prev,
				  struct list_head * next)
{
	new->next = next;
	new->prev = prev;
	smp_wmb();
	next->prev = new;
	prev->next = new;
}
static inline void list_add_rcu(struct list_head *new, struct list_head *head)
{
	__list_add_rcu(new, head, head->next);
}
static inline void list_add_tail_rcu(struct list_head *new,
				     struct list_head *head)
{
	__list_add_rcu(new, head->prev, head);
}

static inline void __list_del(struct list_head * prev, struct list_head * next)
{
	next->prev = prev;
	prev->next = next;
}
static inline void list_del_rcu(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	entry->prev = LIST_POISON2;
}

static inline void list_replace_rcu(struct list_head *old,
				    struct list_head *new)
{
	new->next = old->next;
	new->prev = old->prev;
	smp_wmb();
	new->next->prev = new;
	new->prev->next = new;
}

/**
 * list_for_each_entry_rcu	-	iterate over rcu list of given type
 * @pos:	the type * to use as a loop counter.
 * @head:	the head for your list.
 * @member:	the name of the list_struct within the struct.
 *
 * This list-traversal primitive may safely run concurrently with
 * the _rcu list-mutation primitives such as list_add_rcu()
 * as long as the traversal is guarded by rcu_read_lock().
 */
#define list_for_each_entry_rcu(pos, head, member)			\
	for (pos = list_entry((head)->next, typeof(*pos), member);	\
	     prefetch(pos->member.next), &pos->member != (head); 	\
	     pos = rcu_dereference(list_entry(pos->member.next, 	\
					      typeof(*pos), member)))
