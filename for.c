#include <stdio.h>


int main(int argc, char **argv)
{
	int i = 0;
	for(i=0; i< argc; i++)
	{
		printf("%d\n", argc);
		if(i+1 >= argc)
		{
			printf("aaaa%s\n", argv[i]);
		}
	}
	return 0;
}


