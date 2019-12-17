/* FIFO */
typedef struct list_struct {
	void			*data;
	struct list_struct	*next;
} queue_item;

struct queue {
	queue_item *head;
	queue_item *tail;
};

static inline int
queue_empty(struct queue *q)
{
	return q->head == NULL;
}

static inline int
enqueue(struct queue *q, void *data)
{
	queue_item *item = malloc(sizeof(*item));
	if (item == NULL)
		return -1;

	item->data = data;
	item->next = NULL;
	if (queue_empty(q))
		q->head = q->tail = item;
	else {
		q->tail->next = item;
		q->tail = item;
	}

	return 0;
}

static inline void *
dequeue(struct queue *q, void *item)
{
	void		*data = NULL;
	queue_item	*tmp = q->head;

	if (tmp) {
		data = tmp->data;
		q->head = tmp->next;
		free(tmp);
	}
	return data;
}

int
level_order_travel(bin_tree *root, visit_function fn)
{
	struct queue q = { NULL, NULL };
	
	if (root == NULL)
		return 0;

	enqueue(&q, root);
	while (!queue_empty(&q)) {
		root = dequeue(q);
		fn(root);
		if (root->left)
			if (enqueue(root->left) < 0)
				return -1;
		if (root->right)
			enqueue(root->left);
	}

	return 0;
}
