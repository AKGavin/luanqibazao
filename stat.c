#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILENAME "abcd"

static int getAuthenticationStatus()
{
	int len = 0; 
	char buf[128] = "";
	FILE *fp = NULL;
	struct stat st;

	if(stat(FILENAME, &st)!=0)
		return -1;

	len = st.st_size;
	if(len <=0) 
		return 0;

	fp = fopen(FILENAME, "r");
	if(NULL == fp)
		return -1;

	fread(buf, len, 1, fp); 
	fclose(fp);

	buf[len] = '\0'; 
		return atoi(buf);
}

int main()
{
	int ret = getAuthenticationStatus();
	printf("ret = %d\n", ret);

	return ret;
}


