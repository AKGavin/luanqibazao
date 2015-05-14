#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char **argv)
{
	char *p = "123";
	char buf[64] = "";
	system(buf);
	printf("%d --%d\n", sizeof(buf), strlen(buf));
	strcpy(buf, "12345678");
	printf("%d --%d\n", sizeof(buf), strlen(buf));
	printf("%d --%d\n", sizeof(p), strlen(p));
	return 0;
}

