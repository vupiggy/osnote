#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_struct {
	struct list_struct	*next;
	char			 digit;
} queue_item;

struct dequeue {
	queue_item *head, *tail;
};

static inline int
is_queue_empty(struct dequeue *q)
{
	return q->head == NULL;
}

static inline char
q_append(struct dequeue *q, char c)
{
	queue_item *item;
	
	item = malloc(sizeof(*item));
	if (item == NULL)
		return 0;
	
	item->digit = c;
	item->next = NULL;
	
	if (is_queue_empty(q)) {
		q->head = item;
	} else 
		q->tail->next = item;
	
	q->tail = item;
	
	return c;
}

static inline char
q_insert(struct dequeue *q, char c)
{
	queue_item *item;

	item = malloc(sizeof(*item));
	if (item == NULL)
		return 0;
	
	item->digit = c;
	item->next = NULL;
	
	if (is_queue_empty(q)) {
		q->tail = item;
	} else
		item->next = q->head;
	
	q->head = item;
	
	return c;
}

static inline char
q_head(struct dequeue *q)
{
	return q->head == NULL ? 0 : q->head->digit;
}

static inline char
q_remove(struct dequeue *q)
{
	char		 c;
	queue_item	*tmp;
	
	if (is_queue_empty(q))
		return 0;

	c = q->head->digit;
	tmp = q->head;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp);
	
	return c;
}

#define for_each_item(item, q)	\
	for (item = (q)->head; item; item = item->next)

static void
count_and_say(char *num, int sz, int n)
{
	struct dequeue	 q[2] = {{NULL}};
	queue_item	*item;
	char		 c;
	int		 i = n;

	for (i = 0; i < sz; i++)
		q_append(&q[0], num[i]);

	for (i = 1; i <= n; i++) {
		struct dequeue *src = &q[(i - 1) % 2];
		struct dequeue *dst = &q[i % 2];
		int	digit_count = 1;
		
		while (!is_queue_empty(src)) {
			char	cur;
			
			cur = q_remove(src);
			if (cur != q_head(src)) {
				/* 非重复数字，将计数数字``念出来''，即
				 * 将连续出现的$n$个数字$k$表示为$nk$。
				 */
				int tmp;
				int base = 1;

				tmp = digit_count / 10;
				while (tmp) {
					tmp /= 10;
					base *= 10;
				}

				while (base) {
					c = digit_count / base + '0';
					digit_count = digit_count -
						digit_count / base * base;
					q_append(dst, c);
					base /= 10;
				}
				q_append(dst, cur);
				digit_count = 1;
			} else	/* 统计重复数字 */
				digit_count++;
		}
	}

	for_each_item(item, &q[(i - 1) % 2])
		printf("%c ", item->digit);
	
	printf("\n");
}

