static char *
reverse_string(char *str, int l, int u)
{
	char c;
	while (l < u) {
		c = str[l];
		str[l] = str[u];
		str[u] = c;
		l++; u--;
	}
	return str;
}

#if 0
/* 不支持前后空格及多空格。
 */
static char *
reverse_words(char *str)
{
	int i, j;

	for (i = 0, j = 0; str[i] != '\0'; j++) {
		if (isspace(str[j]) || str[j] == '\0') {
			reverse_string(str, i, j - 1);
			i = (str[j] == '\0') ? j : j + 1;
		}
	}

	reverse_string(str, 0, i - 1);
	
	return str;
}
#else
/* 倒腾字符串，关键要理清游标在每一轮迭代之前之后的准确含义
 *
 * 思路：反转每一个单词，最后对整个字符串做一次反转。本题难点不在反转，
 * 而在于去除多余的空白字符。实现需要考虑扫描过程及时去除空给。
 */
static int
reverse_words(char *str)
{
	/* i 用于指示下一个可能单词的开始，j 是纯游标 */
	int i, j, wlen = 0;

	for (i = 0, j = 0; str[j] != '\0'; j++) {
		/* 遇见一个空白字符，当前单词长度如果不为零，说明历经了
		 * 一个完整的单词，对其进行反转。将单词之后的字符赋值为
		 * 空格，并将 i 指向空格之后，即下一个可能的单词开始处。
		 */
		if (isspace(str[j])) {
			if (wlen) {
				reverse_string(str, i, i + wlen - 1);
				str[i + wlen] = ' ';
				i += wlen + 1;
				wlen = 0;
			}
		} else {
			str[i + wlen] = str[j];
			wlen++;
			/* 到达尾部，反转最后一个单词 */
			if (str[j + 1] == '\0') {
				reverse_string(str, i, i + wlen - 1);
				i += wlen;
			}
		}
	}

	/* 当源字符串以空格结尾，可能发生如下情况 */
	if (isspace(str[i - 1]))
		i--;
	
	str[i] = '\0';
	reverse_string(str, 0, i - 1);

	return i;
}
#endif
