static void reverse_range(char *start, char *end)
{
	assert(start != NULL && start < end);	
	while (start < end) {
		char c = *start;
		*start = *end;
		*end = c;
		start++; end--;
	}
}

void reverse_by_word(char *str)
{
	char *c, *wstart;
	int wlen = 0;
	for (c = str, wstart = str; *c; c++) {
		if (isspace(*c)) {
			if (wlen) { /* 单词结束，反转之 */
				reverse_range(wstart, wstart + wlen - 1);
				wstart[wlen] = ' '; /* 删除此行不支持去除空格 */
				wstart += wlen + 1;
				wlen = 0;
			}
		} else {
			wstart[wlen] = *c; /* 无此行不支持去除空格 */
			wlen++;
			if (*(c + 1) == '\0') {
				reverse_range(wstart, wstart + wlen - 1);
				wstart += wlen + 1;
			}
		}
	}
	/* wstart 或者在 \0 之后，或者在一个空格之后 */
	*(wstart - 1) = '\0';
	reverse_range(str, (wstart - 2));
}

