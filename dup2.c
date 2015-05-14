#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <strings.h>

#define TESTSTR "Hello dup2\n"

void test()
{


	printf("aaaaaaa\n");
}

int main() {
	int fd3;
	fd3 = open("testdup2.log", O_CREAT | O_RDWR);
		if (fd3 < 0) {
			printf("open error\n");
			exit(-1);
		}
		
		if (dup2(fd3,STDOUT_FILENO) < 0) {
			printf("err in dup2\n");
		}
		
		test();
	printf(TESTSTR);
	close(fd3);
	return 0;
}

