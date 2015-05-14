#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
	FILE *fp = fopen("aaaaa", "w");

	if(fp == NULL)
		return -1;

	fwrite("UNREGIST", strlen("UNREGIST"),1,fp);
	fclose(fp);

	return 0;
}


