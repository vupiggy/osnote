/* Copyright (c) 2014 Luke Huang <lukehuang.ca@me.com> */

/**
 * @Date	2015/04/04 04:55:09
 * @Summary	
 */

#define left_child(i)	((i) * 2 + 1)
#define right_child(i)	(((i) + 1) * 2)
#define parent(i)	(((i) - 1) / 2)

typedef struct heap_struct {
	int64_t *array;
	int	 length;
	int	 size;
} heap;

static inline void
swap_entry(heap *hp, int i, int j)
{
	int64_t tmp  = hp->array[i];
	hp->array[i] = hp->array[j];
	hp->array[j] = tmp;
}

/* 假设 i 的左右子都是最大堆， */
void
max_heapify(heap *hp, int i)
{
	int l = left_child(i);
	int r = right_child(i);
	int largest = i;

	if (l < hp->size && hp->array[l] > hp->array[i])
		largest = l;
	if (r < hp->size && hp->array[r] > hp->array[largest])
		largest = r;
	
	if (largest != i) {
		swap_entry(hp, i, largest);
		max_heapify(hp, largest);
	}
}

heap *
build_max_heap(int64_t *array, int n)
{
	heap *hp = malloc(sizeof(*hp));
	int i;

	if (hp == NULL) {
		perror("malloc");
		return NULL;
	}

	hp->array  = array;
	hp->size   = n;
	hp->length = n;

	for (i = n / 2; i >= 0; i--)
		max_heapify(hp, i);
}

void
sort_max_heap(heap *hp)
{
	if (hp) {
		int i;
		for (i = hp->size - 1; i >= 0; i--) {
			swap_entry(hp, 0, i);
			hp->size--;
			max_heapify(hp, 0);
		}
		
	}
}

int
main(int argc, char **argv)
{

}

/*
 * Local Variables:
 * mode: C
 * c-file-style: "Linux"
 * End:
 */
