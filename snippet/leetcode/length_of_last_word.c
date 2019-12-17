static int
length_of_last_word(const char *s)
{
	int start = -1, end = -1, cur = 0, in_word = 0;

	while (1) {
		if (s[cur] == '\0') {
			if (in_word)
				end = cur;
			break;
		}
		
		if (s[cur] == ' ') {
			if (in_word) {
				end = cur;
				in_word = 0;
			}
		} else if (!in_word) {
			start = cur;
			in_word = 1;
		}
		cur++;
	}

	return end - start;
}
