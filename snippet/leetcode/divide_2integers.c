int
div(int a, int b)
{
	int ret = 0;

	while (a >= b) {
		int count = 0;
		while (a >= (b << count))
			count++;
		ret += 1 << (count - 1);
		a -= b << (count - 1);
	}

	return ((a > 0) ^ (b > 0)) ? -ret : ret;
}

