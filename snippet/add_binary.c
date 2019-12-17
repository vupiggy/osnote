#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b)	({		\
	typeof(a)	_a = (a);	\
	typeof(b)	_b = (b);	\
	(void) (&_a == &_b);		\
	_a > _b ? _a : _b; })

static void
reverse_array(char *array, int len)
{
	int l, r;

	for (l = 0, r = len - 1; l < r; l++, r--) {
		char c = array[l];
		array[l] = array[r];
		array[r] = c;
	}
}

char *
add_binary(const char *a, const char *b)
{
	int la;
	int lb;
	int slen;
	int i, carry;
	char *sum = malloc(sizeof(*sum) * slen);
	
	if (sum == NULL)
		goto out;
	if (a == NULL || (la = strlen(a)) == 0) {
		strcpy(sum, b);
		goto out;
	}
	if (b == NULL || (lb = strlen(b)) == 0) {
		strcpy(sum, a);
		goto out;
	}

	slen = max(la, lb) + 2;

	la--; lb--; i = 0;
	carry = 0;
	while (la >= 0 && lb >= 0) {
		int s = (a[la] - '0' + b[lb] - '0') + carry;
		sum[i++] = s % 2 + '0';
		carry = s / 2;
		la--; lb--;
	}

	if (la < 0) {
		la = lb;
		a = b;
	}
	while (la >= 0) {
		int s = a[la] - '0' + carry;
		sum[i++] = s % 2 + '0';
		carry = s / 2;
		la--;
	}
	if (carry) {
		sum[i] = 1;
		slen -= 1;
	}
	else
		slen -= 2;

	reverse_array(sum, slen);
out:
	return sum;
}
