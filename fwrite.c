#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buf[128];
	FILE *fp = fopen("testfile", "r");
	if(!fp)
	{
		printf("fopen errod\n");
		return -1;
	}

	fread(buf, 128, 1, fp);
	puts(buf);
	fclose(fp);
#if 1
	if(argc == 2)
	{
		fp = fopen("testfile", "w+");
		if(!fp)
		{
			printf("fopen errod\n");
			return -1;
		}
		fwrite("bbbbbbbb",8,  1, fp);
	fclose(fp);
	}
#endif

	return 0;
}


