int
removeDuplicates(int a[], int n)
{
        if (n < 3) 
		return n;

        int c = 1;
        int i = 1;
        int count = 1;
        while(i < n) {
		/* copy element if the count is less than 2 or number is
		 * not equal to previous one.
		 */
		if (a[i] != a[i-1]) {
			a[c++] = a[i];
			count = 1;
		} else if (a[i] == a[i - 1] && count < 2) {
			a[c++] = a[i];
			count++;
		}
		i++;
        }
        return c;
}
