#include <stdio.h>

/* 判断在(row, col)坐标上放置num是否合法 */
static int
is_possible(char board[9][9], int row, int col, char num)
{
	int i;

	/* 实际上使用三个循环效率相同，可读性更好一些 */
	for (i = 0; i < 9; i++) {
		int sub_row, sub_col;

		sub_row = 3 * (row / 3) + i / 3;
		sub_col = 3 * (col / 3) + i % 3;
		
		if (num == board[row][i] ||		/* 同行 */
		    num == board[i][col] ||		/* 同列 */
		    num == board[sub_row][sub_col])	/* 同块 */
			return 0;
	}

	return 1;
}

/* 回溯法解数独问题：先找出所有空白格子，逐个尝试用一到九填入，每尝试一
 * 个数就判断该数是否合法，如果合法则尝试填充下一空白格子（通过递归），
 * 否则用下一个数尝试，如果九个数全不合法，回退一格用那一格的下一个数尝
 * 试。运气不好的可能一直回溯到第一个空白格子重新开始一轮。回溯法思路可
 * 用于解迷宫，八皇后等问题。
 */
static int
try_solve(char board[9][9], int *empty_cells, int current, int rest)
{
	char c;
	
	if (rest == 0)
		return 1;	/* 解毕 */

	for (c = '1'; c <= '9'; c++) {
		int row = empty_cells[current] / 9,
		    col = empty_cells[current] % 9;
		/* 最坏情况一直递归到最后一个待解格子才发现冲突 */
		if (is_possible(board, row, col, c)) {
			board[row][col] = c;
			if (try_solve(board, empty_cells,
				      current + 1, rest - 1))
				return 1;
			board[row][col] = '.';
		}
	}

	return 0;
}

static int
sudoku_solver(char board[9][9])
{
	int i, j, empty_cells[81] = {-1}, rest = 0;

	/* 找出所有空白格子的坐标 */
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (board[i][j] == '.')
				empty_cells[rest++] = i * 9 + j;

	return try_solve(board, &empty_cells[0], 0, rest);
}
