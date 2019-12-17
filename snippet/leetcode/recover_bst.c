typedef struct list {
	struct list	*next;
	bst_t		*node;
} stack_item;

static inline int
is_stack_empty(stack_item *top)
{
	return top == NULL;
}

static inline stack_item *
stack_push(stack_item **top, bst_t *node)
{
	stack_item *item;

	item = malloc(sizeof(*item));
	if (item == NULL)
		goto out;

	item->node = node;
	item->next = *top;
	*top = item;

out:
	return item;
}

static inline bst_t *
stack_pop(stack_item **top)
{
	bst_t		*node = NULL;
	stack_item	*item;
	
	if (*top) {
		node = (*top)->node;
		item = *top;
		*top = (*top)->next;
		free(item);
	}

	return node;
}

static inline bst_t *
stack_top(stack_item *top)
{
	return top == NULL ? NULL : top->node;
}

static void
inorder_traversal(bst_t *root, walk_func func)
{
	stack_item *top = NULL;

	while (!is_stack_empty(top) || root != NULL) {
		if (root) {
			stack_push(&top, root);
			root = root->left;
		} else {
			root = stack_top(top);
			func(root);
			root = stack_pop(&top)->right;
		}
	}
}

static void
recover_bst(bst_t *root)
{
	bst_t *wrong_node0 = NULL, *wrong_node1 = NULL;
	bst_t *prev;
	stack_item *top = NULL;

	while (!is_stack_empty(top) || root != NULL) {
		if (root) {
			stack_push(&top, root);
			root = root->left;
		} else {
			root = stack_pop(&top);
			
			/* error detection*/
			if (prev && prev->key > root->key) {
				if (wrong_node0 == NULL) {
					wrong_node0 = prev;
					/* in  case  of it  was  swapped
					 * with its successor.
					 */
					wrong_node1 = root;
				} else {
					wrong_node1 = root;
					break;
				}
			}
			prev = root;
			
			root = root->right;
		}
	}

	if (wrong_node0 && wrong_node1) {
		int64_t key, val;

		printf("%"PRId64 " %"PRId64 "\n",
		       wrong_node0->key, wrong_node1->key);
		// node = *wrong_node0;
		key = wrong_node0->key;
		val = wrong_node0->val;
		
		wrong_node0->key = wrong_node1->key;
		wrong_node0->val = wrong_node1->val;
		wrong_node1->key = key;
		wrong_node1->val = val;
	}
}
