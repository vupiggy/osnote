#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>

static int
isPalindrome(int x)
{
        int a, r;

        if (x < 0) return 0;

	a = x;
	r = 0;
	
	/* 反转 */
        while (a != 0) {
		r = r * 10 + a % 10;
		a = a / 10;
        }

        return r == x;
}

static inline int
power_of_ten_down(int x)
{
	int p;
	for (p = 1; x != 0; x /= 10)
		p *= 10;
	return p / 10;
}

static inline int
peel(int x, int *h, int *t)
{
	int p;
	if (x / 10 == 0)
		return 0;
	
	p = power_of_ten_down(x);
	*h = x / p;
	*t = x % 10;

	return (x % p) / 10;
}

static int
is_palindrome(int x)
{
	int h, t;
	int p;

	p = peel(x, &h, &t);
	if (p == 0)
		return 1;
	
	if (h != t)
		return 0;
	
	return is_palindrome(p);
}

int
main(int argc, char **argv)
{
	int i;

	if (argc != 2)
		goto usage;
	
	i = strtoll(argv[1], NULL, 0);
	if (errno == EINVAL)
		goto usage;

	printf("%d %s a palindrome\n",
	       i, isPalindrome(i) ? "is" : "isn't");

	printf("%d %s a palindrome\n",
	       i, is_palindrome(i) ? "is" : "isn't");
	
	return 0;

usage:
	fprintf(stderr, "Usage: \n");
	return 1;
}
