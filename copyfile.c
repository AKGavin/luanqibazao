#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define LINE_SIZE 512

static int copyFile(const char *src_path, const char *dst_path);

int main(int argc, char **argv)
{
	if(argc < 3)
	{
		printf("Usage ...\n");
		return -1;
	}

	if(copyFile(argv[1], argv[2]) < 0)
		return -1;

	return 0;
}

static int copyFile(const char *src_path, const char *dst_path)
{
	FILE *conf_f = NULL;
	FILE *tmp_f = NULL;

	char buf[LINE_SIZE];
	int  ret = 0;


	conf_f = fopen(src_path,"r");
	if(conf_f == NULL)
	{
		perror("fopen()");
		ret = -1;
		goto err;
	}

	tmp_f = fopen(dst_path, "w+");
	if(tmp_f == NULL)
	{
		perror("fopen()");
		ret = -1;
		goto err;
	}

	while(fgets(buf, LINE_SIZE, conf_f) !=  NULL)
	{
		if(fputs(buf,tmp_f) == EOF)
		{
			perror("fputs()");
			ret = -1;
			goto err;
		}
		memset(buf, 0x0, LINE_SIZE);
	}
err:
	if(conf_f != NULL)
	{
		fclose(conf_f);
		conf_f = NULL;
	}
	if(tmp_f != NULL)
	{
		fclose(tmp_f);
		tmp_f = NULL;
	}
	if(ret != 0)
	{
		remove(dst_path);
		return ret;
	}
	return ret;
}

