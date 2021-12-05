#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>

char	*plus(int fd)
{
	static char b[5];
	int i = 0;

	read(fd, b, 4);
	b[4] = '\0';

	while(b[i] && b[i] != ' ')
	{
		printf("%c", b[i]);
		i++;
	}
	printf("\n");
	return (b);
}

int main()
{
	int fd;

	fd = open("../text.txt", O_RDONLY);
	printf("%s\n", plus(fd));
	close(fd);
	return 0;
}