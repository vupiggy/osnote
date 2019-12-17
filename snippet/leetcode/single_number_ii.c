int singleNumber(int A[], int n)
{
	/* bit_count[i]表示A中第i个二进制位的1个数（结果对3求模）*/
	char bit_count[32];
	/* 用来确定single number的符号，0正1负 */
	char sign = 0;
	
	memset(bit_count, 0, sizeof(char) * 32);
	
	for (int i = 0; i < n; i++) {
		int tmp = A[i];
		if(A[i] < 0) {
			tmp *= -1;
			sign = (sign + 1) % 3;
		}
		for(int k = 0; k < 32; k++) {
			bit_count[k] = (bit_count[k] + (tmp & 0x00000001)) % 3;
			tmp = tmp >> 1;
		}
	}
	int res = 0, base = 1;
	for(int i = 0; i < 32; i++) {
		res += (base * bit_count[i]);
		base <<= 1;
	}
	return sign == 0 ? res : -res;
}
