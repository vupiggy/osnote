static inline void
_print_binary(char c)
{
	int i = 1 << 7;	
	while (i) {
		putchar(c & i ? '1' : '0');
		i >>= 1;
	}
}
void
print_binary(int i)
{
	char *c;
	for (c = (char *)&i + sizeof(i) - 1; c >= (char *)&i; c--)
		_print_binary(*c);
}
