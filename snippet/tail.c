#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 8192

static void
print_lines(FILE *fp, off_t start)
{
	int	fd;
	int	nread;
	char	buffer[BUFF_SIZE];

	fd = fileno(fp);
	lseek(fd, (start + 1), SEEK_SET);
	
	while ((nread = read(fd, buffer, BUFF_SIZE)) > 0)
		write(STDOUT_FILENO, buffer, nread);
}

static void
tail(FILE *fp, int n)
{
	off_t	pos;
	int	lines;
	
	fseek(fp, 0, SEEK_END);
	pos = ftell(fp);

	while (pos >=0) {
		char c = fgetc(fp);

		if (c == '\n')
			if (++lines == n + 1) /* n  is  wrong, the  last
					       * '\n' should be ignore
					       */
				break;
		fseek(fp, --pos, SEEK_SET);
	}

	print_lines(fp, pos);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	
	if ((fp = fopen(argv[2], "r")) == NULL) {
		perror("Open");
		return -1;
	}
	
	tail(fp, atoi(argv[1]));
	
	fclose(fp);	
	return 0;
}
/*
 * awk '{ buffer[NR % 10] = $0; } END { for (i = 1; i < 11; i++){print buffer[i % 10]} }'
 *
 * tac xxx.txt | head -10
 *
 * head: awk 'NR <= 10' xxx.txt
 * 
 */
