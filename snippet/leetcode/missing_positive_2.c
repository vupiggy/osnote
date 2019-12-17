int first_missing_positive(int A[], int n) {
	int i = 0, j, tmp;
    
	while (i < n) {
		/* 不处理大于 n， 小于 0， 和已经就位的数 */
		if (A[i] >= n || A[i] <= 0 || A[i] == A[A[i] - 1]) {
			i++;
			continue;
		}
        
		tmp = A[A[i] - 1];
		A[A[i] - 1] = A[i];
		A[i] = tmp;
		/* 把它处一个元素调过来，就地处理，i 不增 */
	}

	for (i = 0; i < n; i++)
		if (A[i] != i + 1)
			return i + 1;

	return n + 1;
}
