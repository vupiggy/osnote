typedef struct heap_struct {
	int	length;
	int	hsize;
	int64_t	array[];
} heap;

#define left_child(i)	(2 * (i) + 1)
#define right_child(i)	(2 * ((i) + 1))
#define parent(i)	(((i) - 1) / 2)
#define swap_entry(array, i, j)					\
	({	typeof(*array) tmp = array[i];			\
		array[i] = array[j];				\
		array[j] = tmp;		})

/* pre-condition：root's left and right child are both minimum heap */
static void
min_heapify(heap *h, int root)
{
	int l = left_child(root);
	int r = right_child(root);
	int smallest = (l < h->hsize && array[l] < array[root]) ? l : root;
	
	if (r < h->size && array[r] < array[root])
		smallest = r;
	/* If root is not the smallest, push down it */
	if (smallest != root) {
		swap_entry(h->array, root, smallest);
		min_heapify(h, smallest);
	}
}

static void
build_min_heap(heap *h)
{
	int i;
	h->hsize = h->length;
	for (i = (h->hsize - 1) / 2; i >= 0; i--)
		min_heapify(h, i);
}

/* It ends up with a descent array, the heap size becomes 0 */
static void
sort_min_heap(heap *h)
{
	if (h != NULL) {
		int i;

		for (i = h->hsize - 1; i > 0; i-- ) {
			swap_entry(h->array, 0, i);
			h->hsize--;
			min_heapify(h, 0);
		}
	}
}

static heap *
construct_min_heap(int64_t *array, int sz, int k)
{
	heap	*h;
	int	 i;

	if (sz < k)
		k = sz;

	h = malloc(sizeof(*h) + k * sizeof(*(h->array)));
	if (h == NULL) {
		perror("malloc");
		return NULL;
	}
	h->length = k;
	/* or read the data segment one by one */
	memcpy(h->array, array, k * sizeof(*(h->array)));
	build_min_heap(h);

	/* Each iteration O(lg k), totally O(n\times lg k) */
	for (i = k; i < sz; i++) {
		/* replace the  first item  in the  heap with  a smaller
		 * value, maintain the heap's property. */
		if (array[i] < h->array[0])
			min_heapify(h, 0);
	}

	return h;
}

/* iterate on h->length after returning (if h is not NULL) */
heap *
top_k(int64_t *array /* the input, can be from a huge file */,
      int sz /* size of the input */, int k /* top k */)
{
	heap *h = construct_min_heap(array, sz, k);
	if (h)
		heap_sort(h);
	return h;
}
