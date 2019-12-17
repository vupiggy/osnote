/* Jump game I */
bool canJump(int A[], int n) {
	int farest = 0; // 当前从头跳能到达的最远位置
	for (int i = 0; i <= farest && farest < n-1; i++)
		if ((i + A[i]) > farest)
			farest = i + A[i];
	return farest >= n-1;
}

/* Jump game II */
int jump(int A[], int n) {
	int *min_jumps = malloc(n * sizeof(*min_jumps));
	if (min_jumps == NULL)
		return -1;
	/* 初始化为最大值 */
	memset(min_jumps, 0xff, n * sizeof(*min_jumps));
        min_jumps[0] = 0;
        for (int i = 0; i < n; i++) {
		int farest = min(i + A[i], n - 1);
		for (int j = i + 1; j <= farest; j++)
			if (min_jumps[j] > min_jumps[i] + 1)
				min_jumps[j] = min_jumps[i] + 1;
        }
        return min_jumps[n-1];
}
