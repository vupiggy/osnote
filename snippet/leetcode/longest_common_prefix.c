int
longest_common_prefix(const char **string_array, int n)
{
	int i, j, stop = 0;

	if (n == 0)
		return -1;
	if (n == 1)
		return strlen(string_array[0]) - 1;

	for (j = 0; !stop; j++) {
		char c = string_array[0][j];

		if (c == '\0')
			stop = 1;
		else {
			for (i = 1; i < n; i++) {
				if (string_array[i][j] != c) {
					stop = 1;
					break;
				}
			}
		}
	}

	return j - 2;
}
