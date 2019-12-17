class Solution {
private:
	void swap_entry(int A[], int i, int j) {
		int tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
public:
	/* 从尾向头扫描，遇见符合条件元素就甩到后面，变量 n 是用于表示当
	 * 前发现的所有满足条件元素组成的尾子数组的头。
	 */
	int removeElement(int A[], int n, int elem) {
		int i = n - 1;
		while (i >= 0) {
			if (A[i] == elem)
				swap_entry(A, --n, i);
			i--;
		}

		return n;
	}
};
