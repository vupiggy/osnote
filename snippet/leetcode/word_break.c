static int
match(const char *word, const char *string, int l, int u)
{
	for (; l <= u && *word; l++, word++)
		if (*word != string[l])
			return 0;
	
	return (l > u && *word == 0);
}

static int
in_dict(const char **dict, const char *string, int l, int u)
{
	const char *cur;

	for (cur = *dict; cur; cur = *(++dict))
		if (match(*dict, string, l, u))
			return 1;
	
	return 0;
}

static int
word_break(const char **dict, const char *string)
{
	int *solutions;
	int len;
	int i, j;

	len = strlen(string);
	solutions = malloc((len + 1) * sizeof(int));
	if (solutions == NULL)
		return -1;
	memset(solutions, 0, sizeof(int) * (len + 1));
	
	solutions[0] = 1;
	for (i = 1; i <= len; i++) {
		for (j = 0; j < i; j++) {
			if (solutions[j] == 1 &&
			    in_dict(dict, string, j, i - 1)) {
				solutions[i] = 1;
				break;
			}
		}
	}

	i = solutions[len];
	free(solutions);
	
	return i;
}
