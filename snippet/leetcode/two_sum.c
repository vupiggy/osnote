#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct num_struct {
	int val;
	int index;
};

int num_compare(const void *num1, const void *num2)
{
	int ret = ((struct num_struct *)num1)->val -
		((struct num_struct *)num2)->val;
	return ret != 0 ? ret :
			((struct num_struct *)num1)->index -
			 ((struct num_struct *)num2)->index;
}

int (*pairs_with_sum(int *array, int len, int sum))[2]
{
	int i, j, k;
	int (*res)[2];
	struct num_struct *nums = malloc(sizeof(*nums) * len);
	if (nums == NULL)
		return NULL;
	res = malloc(sizeof(*res) * (len * len));
	if (res == NULL) {
		free(nums);
		return NULL;
	}
	memset(res, -1, sizeof(*res) * (len * len));
	
	for (i = 0; i < len; i++) {
		nums[i].val = array[i];
		nums[i].index = i;
	}
	qsort(nums, len, sizeof(*nums), num_compare);
	
	for (i = 0; i < len; i++)
		printf("<%d-%d> ", nums[i].index, nums[i].val);
	printf("\n");
	
	i = 0, j = len - 1, k = 0;
	while (i < j) {
		int s = nums[i].val + nums[j].val;
		if (s == sum) {
#if 1
#  if 0
			/* count only once */
			int l = nums[i].val, r = nums[j].val;
			res[k][0] = nums[i].index;
			res[k][1] = nums[j].index;
			k++;
			/* 逻辑上说 i < j 没必要，加这个判断好不好？？？
			 * while (i < j && nums[j].val == r) j--;
			 * while (i < j && nums[i].val == l) i++;
			 */
			while (nums[j].val == r) j--;
			while (nums[i].val == l) i++;
#  else
			/* count combinations of all duplicates */
			int l = nums[i].val, r = nums[j].val;
			int ii, jj;
			for (ii = i; nums[ii].val == l; ii++) {
				for (jj = j; nums[jj].val == r; jj--, k++) {
					res[k][0] = nums[ii].index;
					res[k][1] = nums[jj].index;
				}
			}
			i = ii;
			j = jj;

#  endif
#else
			/* If no duplicate */
			int l = nums[i].val, r = nums[j].val;
			res[k][0] = nums[i].index;
			res[k][1] = nums[j].index;
			k++;
#  if 0
			/* generate all pairs */
			j--, i++;
#  else
			/* only one solution */
			return res;
#  endif
#endif
		} else if (s < sum) {
			i++;
		} else
			j--;
	}

	free(nums);
	return res;
}

int
main(void)
{
	int i;
	int array[] = {2, 1, 9, 3, 4, 10, 6, 5, 2, 7, 1, 9, 8, 4, 2, 2};
	int (*res)[2];
	int len = sizeof(array) / sizeof(array[0]);

	for (i = 0; i < len; i++)
		printf("<%d-%d> ", i, array[i]);
	printf("\n");

	res = pairs_with_sum(array, len, 11);
	if (res == NULL)
		return -1;
	
	while ((*res)[0] != -1) {
		printf("<%d-%d>:<%d-%d> ",
		       (*res)[0], array[(*res)[0]],
		       (*res)[1], array[(*res)[1]]);
		res++;
	}
	printf("\n");
	
	free(res);
	return 0;
}
