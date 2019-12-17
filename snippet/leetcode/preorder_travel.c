typedef int (*visit_function)(void *args);

typedef struct list_head {
	void			*data;
	struct list_head	*next;
} stack_item;

typedef struct stack_struct {
	stack_item *stack_top;
};

static inline int
stack_empty(struct stack *stk)
{
	BUG_ON(stk == NULL);
	return stk->stack_top == NULL;
}

static inline void *
stack_top(struct stack *stk)
{
	BUG_ON(stk == NULL);
	return stk->stack_top ? stk->stack_top->data : NULL;
}

static inline int
stack_push(struct stack *stk, void *data)
{
	stack_item *item;
	
	BUG_ON(stk == NULL);	/* internal logic error, kill */

	item = malloc(*item);
	/* system is malfunctional, let the program decide */
	if (item == NULL)
		return -1;
	
	item->data     = data;
	item->next     = stk->stack_top;
	stk->stack_top = item;
	return 0;
}

static inline void *
stack_pop(struct stack *stk)
{
	void *data = NULL;
	
	BUG_ON(stk == NULL);
	
	if (stk->stack_top) {
		stack_item *item;
		item	       = stk->stack_top;
		data	       = item->data;
		stk->stack_top = item->next;
		free(item);
	}
	return data;
}

int
preorder_travel(bin_tree *root, visit_function fn)
{
	struct stack stk = { NULL };

	while (root || !stack_empty(&stk)) {
		if (root) {
			fn(root);
			if (stack_push(&stk, root) < 0)
				return -1;
			root = root->left;
		} else
			root = stack_pop(&stk)->right;
	}
	return 0;
}
