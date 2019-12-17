static size_t
_strlen(char *str)
{
	char *tmp = str;
	while (*tmp++);
	return (tmp - str - 1);
}

static size_t
_strlen_recursive(char *str)
{
	if (*str == 0)
		return 0;
	
	return (_strlen_recursive(str + 1) + 1);
}

char *strcpy(char *dst, const char *src)
{
	char *tmp = dst;
	while (*dst++ = *src++);
	return tmp;
}

int strcmp(const char *str1, const char *str2)
{
	char res = 0;
	
	while (1) {
		if ((res = *str1 - *str2) != 0 || !*str1++ || !*str2++)
			break;
	}
	return res;
}

int strncmp(const char *str1, const char *str2, int n)
{
	char res = 0;
	
	while (n) {
		if ((res = *str1 - *str2++) != 0 || !*str1++)
			break;
		n--;
	}
	return res;
}

char * strcat(char * dest, const char * src)
{
	char *tmp = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++) != '\0')
		;

	return tmp;
}

char * strncat(char *dest, const char *src, size_t count)
{
	char *tmp = dest;

	if (count) {
		while (*dest)
			dest++;
		while ((*dest++ = *src++) != 0) {
			if (--count == 0) {
				*dest = '\0';
				break;
			}
		}
	}

	return tmp;
}
