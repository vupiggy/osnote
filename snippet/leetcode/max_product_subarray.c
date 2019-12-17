#define min(x, y) ({				\
			int _x = (x);		\
			int _y = (y);		\
			_x < _y ? _x : _y;	\
		})
#define max(x, y) ({				\
			int _x = (x);		\
			int _y = (y);		\
			_x > _y ? _x : _y;	\
		})
int maxProduct(int array[], int n) {
	int sub_max[2], sub_min[2], max;
	int i;
		
	/* 两个数组存放以 array[i] 结尾的子数组的最大积和最小积 */
	max = sub_max[0] = sub_min[0] = array[0];
    
	for (i = 1; i < n; i++) {
		int cur = i % 2, prev = (i - 1) % 2;
			
		/* 遇见负数，以前一个元素结尾的子数组的最大积和
		 * 最小积和当前元素相乘将产生以当前元素结尾的子
		 * 数组的最小和最大积。在这里做交换避免之后复杂
		 * 的分情况讨论。
		 */
		if (array[i] < 0) {
			int tmp;
			tmp = sub_min[prev];
			sub_min[prev] = sub_max[prev];
			sub_max[prev] = tmp;
		}
    
		sub_min[cur] = min(sub_min[prev] * array[i], array[i]);
		sub_max[cur] = max(sub_max[prev] * array[i], array[i]);
    
		if (sub_max[cur] > max)
			max = sub_max[cur];
	}

	return max;
}

