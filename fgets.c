#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int i = 0;
	char buf[128];
	FILE *fp = fopen("aaa", "r");
	if(fp == NULL){
		printf("fopen error\n");
		return -1;
	}

	while(fgets(buf, 128, fp))
	{
		i++;
		printf("[%d]\n", i);
		memset(buf, 0x0, 128);
	}
	printf("end======\n");
	fclose(fp);
	return 0;
}


