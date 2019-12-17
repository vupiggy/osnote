int
climbing_stairs(int n)
{
	int stairs[2] = {1, 2};
        int i;

	if (n <= 0)
		return 1;
	
        for (i = 2; i < n; i++)
            stairs[i % 2] = stairs[(i - 1) % 2] + stairs[(i - 2) % 2];
	
        return stairs[(n - 1) % 2];
}

