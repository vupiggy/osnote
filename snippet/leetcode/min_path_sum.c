int
min_path_sum(int **grid, int rows, int cols)
{
	int **min_sum;
	int i, j;
	
	if(rows == 0 || cols == 0)
		return 0;

	min_sum = malloc((rows + 1) * sizeof(*min_sum));
	if (min_sum == NULL)
		return -1;
	for (i = 0; i < rows; i++) {
		min_sum[i] = malloc((cols + 1) * sizeof(*min_sum[0]));
		if (min_sum[i] == NULL) {
			for (--i; i >= 0; --i)
				free(min_sum[i]);
			free(min_sum);
			return -1;
		}
	}
	/* 动态规划如果使用二维表，处理边界条件的一个常用方式是将外沿填
	 * 充为特殊值，譬如本题找最小路径，就将外沿填充为无穷大，这样就
	 * 不用特殊处理起始行列，逻辑统一。
	 */
	for (i = 0; i < cols; i++)
		min_sum[0][i] = INT_MAX;
	for (i = 0; i < rows; i++)
		min_sum[i][0] = INT_MAX;
	min_sum[0][1] = 0;
	
	for (i = 1; i <= rows; i++)
		for (j = 1; j <= cols; j++)
			min_sum[i][j] = grid[i - 1][j - 1] +
				min(min_sum[i][j - 1], min_sum[i - 1][j]);
	
	return min_sum[rows][cols];
}
