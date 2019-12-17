/* 判断在格 (row, col) 处放置 num 是否引发冲突 */
static int
is_valid_cell(char board[9][9], int row, int col, char num)
{
	int i;
	
	if (num == '.')
		return 1;

	/* 将待查格置空，循环时就不用判断是否为待查格 */
	board[row][col] = '.';
	
	for (i = 0; i < 9; i++) {
		int sub_row = (row / 3) * 3 + i / 3,
		    sub_col = (col / 3) * 3 + i % 3;
		
		if (num == board[row][i] ||
		    num == board[i][col] ||
		    num == board[sub_row][sub_col]) {
			board[row][col] = num;
			return 0;
		}
	}

	/* 复原待查格 */
	board[row][col] = num;
	return 1;
}

static int
is_valid_sudoku(char board[9][9])
{
	int i, j;

	/* 没有捷径，只能判断每一格的合法性 */
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (!is_valid_cell(board, i, j, board[i][j]))
				return 0;

	return 1;
}
