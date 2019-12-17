vector<vector<int> > generateMatrix(int n)
{
        vector<vector<int> > matrix(n, vector<int>(n));
        int a = n; //a为当前环的边长
        int val = 1;
        for(int i = 0; i < n/2; i++, a -= 2)
        {
		// 每个环的左上角起点是matrix[i][i], 下面顺时针依次填充环的四条边
		for(int column = i; column < i+a; column++)
			matrix[i][column] = val++;
		for(int row = i+1; row < i+a; row++)
			matrix[row][i+a-1] = val++;
		for(int column = i+a-2; column >= i; column--)
			matrix[i+a-1][column] = val++;
		for(int row = i+a-2; row > i; row--)
			matrix[row][i] = val++;
        }
        if(n % 2)matrix[n/2][n/2] = val;// n是奇数时，最后一个环只有一个数字
        return matrix;
}
