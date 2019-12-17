static double
power(double x, int y)
{
	if(y == 0 /* || y == -y corner case */)
		return 1.0;

	if (y < 0) {
		printf("negative number\n");
		return 1.0 / power(x, -y);
	}

	if (y & 1)
		return (x * power(x, y - 1));

	return power(x * x, y / 2);
}
