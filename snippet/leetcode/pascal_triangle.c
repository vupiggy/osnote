#include <stdio.h>
#include <stdlib.h>

static void
init_matrix(int **matrix, int rows, int cols)
{
	int i, j;
	
	for (i = 0; i < rows; i++) 
		for (j = 0; j < cols; j++) 
			matrix[i][j] = '.';
}

static void
print_matrix(int **matrix, int rows, int cols)
{
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (matrix[i][j] == '.')
				printf("%6c ", matrix[i][j]);
			else
				printf("%6d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

static int
generate_pascal_triangle(int level)
{
	int	*area;
	int	**matrix;
	int	  i, j;
	
	area = malloc(sizeof(int) * level * (level + 1));
	if (area == NULL)
		return -1;
	
	matrix = malloc(sizeof(int *) * level);
	for (i = 0; i < level; i++)
		matrix[i] = area + (level + 1) * i;
	
	init_matrix(matrix, level, level + 1);

	matrix[0][0] = 1;
	if (level == 1) return 0;
	matrix[1][0] = 1;
	matrix[1][1] = 2;
	matrix[1][2] = 1;
	if (level == 2) return 0;
	
	for (i = 2; i < level; i++) {
		matrix[i][0] = matrix[i][i + 1] = 1;
		for (j = 1; j < i + 1; j++)
			matrix[i][j] = (matrix[i - 1][j - 1] + matrix[i - 1][j]);
	}

	print_matrix(matrix, level, level + 1);

	return 0;
}

static int *
the_kth_level(int level)
{
	int *line[2];
	int i;

	line[0] = malloc((level + 1) * sizeof(int));
	if (line[0] == NULL)
		return NULL;
	line[1] = malloc((level + 1) * sizeof(int));
	if (line[1] == NULL) {
		free(line[0]);
		return NULL;
	}

	line[0][0] = 1;
	if (level == 0) {free(line[1]); return line[0];}
	
	line[1][0] = 1;
	line[1][1] = 1;
	if (level == 1) {free(line[0]); return line[1];}

	for (i = 2; i <= level; i++) {
		int j, k;
		
		j = i % 2;
		line[j][0] = line[j][i] = 1;
		for (k = 1; k < i; k++)
			line[j][k] =
				line[(i - 1) % 2][k - 1] + line[(i - 1) % 2][k];
	}

	free(line[i % 2]);
	return line[level % 2];
}

/* 第 i 行的第 j 个数等于第 i -1 行的第 j - 1 个数与第 j 个数之和
 */
int
main(int argc, char **argv)
{
	int	 level;
	int	*line;
	
	if (argc != 2) {
		fprintf(stderr, "Usage: 125_valid_palidrome <\"string\">\n");
		return 1;
	}
	level = atoi(argv[1]);	
	// generate_pascal_triangle(level);
	line = the_kth_level(level);
	{
		int i;
		for (i = 0; i < level + 1; i++)
			printf("%d ", line[i]);
		printf("\n");
	}
	return 0;
}
