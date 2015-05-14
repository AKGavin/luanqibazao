#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define path "testfile"

int main()
{
	int fd = open(path,O_WRONLY|O_CREAT);
	if(fd == -1)
	{
		printf("open error!\n");
		return -1;
	}

	write(fd, "1234567890\n0987654321\nabcdef\n", 26);
	close(fd);
	return 0;
}

