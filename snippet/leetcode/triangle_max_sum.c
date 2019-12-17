int minimumTotal(vector<vector<int> > &triangle) {
	const int rows = triangle.size();
	int sums[rows];
	for(int i = 0; i < rows; i++)
		sums[i] = triangle[rows-1][i];
	for(int i = rows-2; i >= 0; i--)
		for(int j = 0; j <= i; j++)
			sums[j] = triangle[i][j] + min(sums[j], sums[j+1]);
	return sums[0];
}
