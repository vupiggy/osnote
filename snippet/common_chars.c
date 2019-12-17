char *
common_chars(char *a, char *b)
{
	char map[256] = { 0 };
	char *output;
	int i = 0;

	output = malloc(256);
	if (output == NULL)
		return NULL;

	memset(output, 0, 256);
	
	while (*a) {
		map[(int)*a] = 1;
		a++;
	}

	while (*b) {
		/* 在 a 出现过 */
		if (map[(int)*b] == 1) {
			map[(int)*b] = 2;
			output[i++] = *b;
		}
		b++;
	}

	return output;
}
