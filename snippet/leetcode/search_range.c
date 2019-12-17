vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int low = 0, high = n-1;
        while(low <= high) {
		int middle = low + ((high - low)>>2);
		if(A[middle] < target)
			low = middle + 1;
		else if(A[middle] > target)
			high = middle - 1;
		else {
			res[0] = lowerBound(A, low, middle - 1, target);
			res[1] = upperBound(A, middle + 1, high, target) - 1;
			return res;
		}
        }
        return res;
}
     
//找到范围内[left,right]内第一个不小于target的元素
int lowerBound(int A[], int left, int right, int target)
{
        int low = left, high = right;
        while(low <= high) {
		int middle = low + ((high - low)>>2);
		if(A[middle] < target)
			low = middle + 1;
		else high = middle - 1;
        }
        return high + 1;//注意这里返回值不是low
}
//找到范围[left,right]内第一个大于target的元素
int upperBound(int A[], int left, int right, int target)
{
        int low = left, high = right;
        while(low <= high) {
		int middle = low + ((high - low)>>2);
		if(A[middle] <= target)
			low = middle + 1;
		else high = middle - 1;
        }
        return low;
}

