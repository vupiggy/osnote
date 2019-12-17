/* rotate the image 90 degrees clockwise
 *
 *          (0,0)             j
 *            +-x---------------->
 *            |               |
 *            |               x'
 *            |               |
 *            |       +------------->
 *            |       |       | 
 *            x'''    |       |
 *            +-------+---x''-+
 *        i   |       |
 *  coord X'  |       |
 *            v       v
 *               coord X
 *
 * In coordinate X, rotating a vector  (i, j) about the origin clockwise
 * by 90 degrees  to (j, -i). And we  knew that each vector (i,  j) in X
 * can be represented in  X' as (i + n /  2, j + n / 2),  so we get that
 * the in X', the vector (i, j) rotates about the origin by 90 degree to
 * (j, n - i), that is, the assignment formula is, (i, j) <- (n - j, i).
 *
 * next think  of the loop,  apparently looping  on the whole  matrix is
 * wrong.  Looping from  outer side  to inner  side is  the solution.  i
 * starts from 0 to size / 2, j starts from i to (size - 1 - i).
 */
static unsigned char **
rotate_image(unsigned char **image, int size)
{
	int i, j, n;
	
	n = size - 1;
	for (i = 0; i < size / 2; i++) {
		for (j = i; j < n - i; j++) {
			char tmp = image[i][j];
			image[i][j]	    = image[n - j][i];
			image[n - j][i]	    = image[n - i][n - j];
			image[n - i][n - j] = image[j][n - i];
			image[j][n - i]	    = tmp;
		}
	}
	return image;
}

void rotate_image(unsigned char *8image) {
	int n = image.size();
	/* 转置 */
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			swap(image[i][j] , image[j][i]);
	
	/* 每一行翻转 */
	for(int i = 0; i < n; i++)
		for(int j = 0; j < (n>>1); j++)
			swap(image[i][j], image[i][n-j-1]);
}
