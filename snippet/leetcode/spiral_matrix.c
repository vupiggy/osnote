int *
clockwise_matrix(int **matrx, int rows, int cols)
{
	int *res;
	int i, curr, rings;
	
	if (rows == 0 || cols == 0)
		return NULL;

	res = malloc(sizeof(*res) * rows * cols);
	if (res == NULL)
		return NULL;

	rings = (rows > cols ? cols / 2 : rows / 2) + 1;

	for (i = 0, curr = 0; i < rings; i++, rows -= 2, cols -= 2) {
		int row, col;

		for (col = i; col < i + cols; col++)
			res[curr++] = matrix[i][col];
		for (row = i + 1; row < i + rows; row++)
			res[curr++] = matrix[row][i + cols - 1];
		for (col = i + cols - 2; col >= i; col--)
			res[curr++] = matrix[i + rows - 1][col];
		for (row = i + rows - 2; row > i; row--)
			res[curr++] = matrix[row][i];
	}

	return res;
}

vector<int> spiral_matrix(vector<vector<int> > &matrix)
{
        int m = matrix.size() /* rows */, n /* col */;
	
        if(m != 0)
		n = matrix[0].size();
	
        int cycle = m > n ? (n + 1) / 2 : (m + 1) / 2; //环的数目
	
        vector<int>res;
        int width = n, height = m;
	
        for(int i = 0; i < cycle; i++, width -= 2, height -= 2) {
		// 每个环的左上角起点是 matrix[i][i], 下面顺时针依次打印环的四条边
		for (int column = i; column < i+width; column++)
			res.push_back(matrix[i][column]);
		for (int row = i + 1; row < i + height; row++)
			res.push_back(matrix[row][i + width - 1]);
		
		if (width == 1 || height == 1)
			break; // 最后的环只有一行或一列
		
		for (int column = i + width - 2; column >= i; column--)
			res.push_back(matrix[i+height-1][column]);
		for (int row = i + height - 2; row > i; row--)
			res.push_back(matrix[row][i]);
        }
        return res;
}
