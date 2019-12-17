bool search(int A[], int n, int key) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l)/2;
		if (A[m] == key)
			return true; /* return m in Search in Rotated Array I */

		if (A[l] < A[m]) { /* left half is sorted */
			if (A[l] <= key && key < A[m])
				r = m - 1;
			else
				l = m + 1;
		} else if (A[l] > A[m]) { /* right half is sorted */
			if (A[m] < key && key <= A[r])
				l = m + 1;
			else
				r = m - 1;
		} else  /* 问题 II 允许有相同元素需要 */
			l++;	/* the best we can do */
	}
	return false;
}

