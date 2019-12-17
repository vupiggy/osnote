int uniquePaths(int m, int n)
{
	return combination(m + n - 2, m - 1);
}
     
int combination(int a, int b)
{
	if (b > (a >> 1)) b = a - b;
	long long res = 1;
	for(int i = 1; i <= b; i++)
		res = res * (a - i + 1) / i;
	return res;
}
/* 动态规划求解 */
int uniquePaths(int m, int n) {
	vector<int>paths(n + 1, 1);
	
	for(int i = 2; i <= m; i++)
		for(int j = 2; j <= n; j++)
			paths[j] =  paths[j] + paths[j-1];
	return paths[n];
}
/* 外加判断是否可达 */
int uniquePaths_II(vector<vector<int> > &grid, int m, int n) {
	vector<int>paths(n + 1, 1);
	
	for(int i = 2; i <= m; i++) {
		for(int j = 2; j <= n; j++) {
			if(grid[i-1][j-1] == 0)
				paths[j] =  paths[j] + paths[j-1];
			else
				paths[j] = 0;
		}
	}
	return paths[n];
}

