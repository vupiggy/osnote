static int
is_valid_palindrome(const char *str)
{
	const char *l = str;
	const char *u = str;
	
	while(*u++);
	u--;

	while (l < u) {
		if (!isalpha(*l)) {
			l++;
			continue;
		}
		if (!isalpha(*u)) {
			u--;
			continue;
		}

		if (tolower(*l) != tolower(*u))
			return 0;
		l++; u--;
	}

	return 1;
}
