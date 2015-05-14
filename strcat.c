#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i = 0;
	char buf[128] = "";
	for(i=2;i < argc; i++)
	{
		strcat(buf, argv[i]);
		if(i + 1 < argc)
			strcat(buf, " ");
	
	}
	printf("[%d]%s\n", i-2, buf);
	return 0;
}

