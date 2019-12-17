#define min(x, y) ({			\
		typeof(x) _x = (x);	\
		typeof(y) _y = (y);	\
		(void)(&_x == &_y);	\
		_x < _y ? _x : _y;	\
	})

/* 二分法：数组中分之后，最小元素只能出现在无序的那段，如果两段都有序，
 * 就返回右段的最小元素，以下实现的前提是数组无重复元素。
 */
static int64_t
min_of(int64_t *array, int l, int u)
{
	int m;
	
	if (l == u)
		return array[0];

        m = (l + r) / 2;

	/* <= 是因为索引值可能相等 */
	if (num[l] <= num[m]) {
		if (num[m + 1] <= num[u])
			/* 两段皆有序，如果数组被移动过， 只要直接返回右
			 * 子数组的最左元素即可，如下返回左右子数组最
			 * 左元素中的小者是因为可能数组根本就没被移动过。
			 */
			return min(array[l], array[m + 1]);
		
		return min_of(array, m + 1, u);
        }
        return min_of(num, l, m);
}

/* 如果有相同元素，如果左右两个子数组的最左和最右元素都相等，无法判断那
 * 一边是有序，最坏情况变成逐个比较，全相等$O(n)$。
 */
static int64_t
find_min_recurisve(int64_t *num, int l, int u)
{
        int64_t min;
        int64_t m;
	
        if (l == u)
		return num[l];
        
        m = (l + u) / 2;        
        if (num[u] < num[m])
		return find_min(num, m + 1, u);
        else if (num[u] > num[m])
		return find_min(num, l, m);
	return min(find_min(num, l, m), find_min(num, m + 1, u));
}

static int64_t
find_min_iterate(int *num, int sz)
{
        int l = 0;
        int u = sz - 1;

        while (l < u) {
		int m = (l + u) / 2;
		/* 整数除法下取整，所以中间索引偏左，换句话说，当左右索引相差一的时候，中间
		 * 索引等于左边索引，如果下面写成：
		 *
		 * while (l <= u) {
		 *	m = (l + u) / 2;
		 * 	if (num[l] < num[m]) l = m + 1;
		 * 	else if (num[l] > num[m]) u = m - 1;
		 * 	else l++;
		 * }
		 *
		 * 会导致左右元素之间不发生比较大小，考虑[2,1]这种情况。二分查找就不需要担心
		 * 这种情况，因为二分查找是将中间元素和一个外部值比较，而这题的解法是通过始终
		 * 用某一边的元素和中间元素比较来缩小范围，在仅剩两个元素时要保证它们做一次比
		 * 较，也就是用右元素和中间元素做比较来决定怎么缩小范围。
		 */
		if (num[m] > num[u])
			l = m + 1;
		else if (num[m] < num[u])
			u = m;
		else
			u--;
        }	
        return num[l];
}

/* 经典算法对调两个子数组位置 */
static int64_t *
_rotate_array(int64_t *array, int sz)
{
	int l, u;
	for (l = 0, u = sz - 1; l <= u; l++, u--)
		swap_entry(array, l, u);
	return array;
}

/* swap @array[0..@pivot] with @array[@pivot + 1..@sz - 1] */
static int64_t *
rotate_array(int64_t *array, int sz, int pivot)
{
	_rotate_array(array, pivot + 1);
	_rotate_array(array + pivot + 1, sz - pivot - 1);
	_rotate_array(array, sz);	
	return array;
}
