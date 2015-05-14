#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char **argv)
{
	FILE *fp = fopen("aaaa", "r");
	if(fp == NULL)
	{
		printf("open fail! errno %d\n", errno);
	}

	return errno;
}


