#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 最大回文子串问题，动态规划解法使用二维表E[i,j]存储子串str[i,j]是否为
 * 回文串的信息，E[i,j]的值和[i,j]长度有关，长度为一的子串是回文串，所以
 * 所有的E[i,i]的值都为真，长度为二的子串取决于两个字符是否相等，也容易
 * 得到。其它情况，E[i,j]是回文串等价于str[i]==str[j]并且E[i+1,j-1]是回
 * 文串，于是从表征子串长度小的表项可以递推出长度大的表项，最终得到所有值。
 *
 */
static void
longest_palindrom(const char *str, int *start, int *end)
{
	int	  longest = 0;
	int	  total_length, cur_len;
	int	  i, j;
	char	**table;

	*start = 0; *end = 0;

	total_length = strlen(str);
	table = malloc(sizeof(char *) * total_length);
	if (table == NULL)
		return;

	memset(table, 0, sizeof(char *) * total_length);
	for (i = 0; i < total_length; i++) {
		table[i] = malloc(sizeof(char) * total_length);
		if (table[i] == NULL)
			goto free_table;
	}
	
	for (cur_len = 1; cur_len <= total_length; cur_len++) {
		for (i = 0; i < total_length - cur_len + 1; i++) {
			j = i + cur_len - 1;
			switch (cur_len) {
			default:
				table[i][j] = (table[i + 1][j - 1] &&
					       str[i] == str[j]);
				break;
			case 1:
				table[i][j] = 1;
				break;
			case 2:
				table[i][j] = (str[i] == str[j]);
				break;
			}
			
			if (table[i][j] && cur_len > longest) {
				longest = cur_len;
				*start	= i;
				*end	= j;
			}
		}
	}

free_table:
	for (i = 0; i < total_length; i++)
		if (table[i] != NULL)
			free(table[i]);
	free(table);
}

const char *str = "3lukeeeekul123321xylinuxunixixinuxunilyxsolution";

int
main(void)
{
	int plrdm_start, plrdm_end;
	
	printf("%s\n", str);

	longest_palindrom(str, &plrdm_start, &plrdm_end);
	
	printf("longest palindrome length: %d ", plrdm_end - plrdm_start + 1);
	while(plrdm_start <= plrdm_end) {
		printf("%c", str[plrdm_start]);
		plrdm_start++;
	}
	printf("\n");
	
	return 0;
}
