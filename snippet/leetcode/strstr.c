#include <stdio.h>

int my_strstr(char *haystack, char *needle) {
        int i = 0, j, k;
        /* 朴素算法，每一次失配就从待配字符串开头，源字符串往后移一个字
	 * 符，开始新一轮匹配。终止条件是程序正确与否的关键。
	 */
        for (i = 0; haystack[i] != '\0'; i++) {
		j = i;
		k = 0;
		while (haystack[j] == needle[k] &&
		       haystack[j] != '\0' &&
		       needle[k] != '\0') {
			j++;
			k++;
		}

		if (needle[k] == '\0')
			return i;
		if (haystack[j] == '\0')
			return -1;
        }
        
        return -1;
}

int
main(int argc, char **argv)
{
	printf("%d\n", my_strstr(argv[1], argv[2]));
	return 0;
}
