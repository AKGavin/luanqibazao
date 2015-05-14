#include <stdio.h>
#include <string.h>

#define CONFIGFILE "/etc/os_safe.d/lxsec.conf"

int get_confdata(char *key, char *findbuf)
{
	int len = 0;
	char linebuf[256] = {0};
	char *data = findbuf;
	char *pos = NULL;
	FILE *confp = NULL;

	if(NULL == data)
		return -1; 

	confp = fopen(CONFIGFILE, "r");
	if(confp == NULL)
	{   
		printf("open file %s fail!\n", CONFIGFILE);
		return -1; 
	}   

	puts(key);
	printf("aaaaaaa\n");
	while(fgets(linebuf, 256, confp)){
		if(strlen(linebuf) < strlen(key))
			continue;
		puts(linebuf);
		pos = strstr(linebuf, key);
		printf("bbbbbbbbbbb\n");
		if(pos != NULL){
			while(1){
				memset(linebuf, 0x0, 256);
				fgets(linebuf, 256, confp);
				if(strlen(linebuf) == 0 || strlen(linebuf) == 1 ){
					bzero(linebuf, 256);
					continue;
				}else{
					break;
				}   
			}
			if(strlen(linebuf) > sizeof(findbuf))
				printf("bbbbbb\n");
			linebuf[strlen(linebuf)-1]='\0';
			memcpy(findbuf, linebuf, strlen(linebuf));
			break;
		}   
	}   
	
	rewind(confp);
	fclose(confp);

	return 0;
}



int main(int argc, char **argv)
{
	char buf[64];
	int port = 0;
	char serip[16]="";
	get_confdata("PLAT_UUID", buf);
	if(strlen(buf) > 0)
		port = atoi(buf);
	printf("port = %d\n", port);
	memset(buf, 0x0, sizeof(buf));
	get_confdata("POLICY_SERVER_IP", serip);
	printf("ip %s\n", serip);
	if(strlen(serip) == 0)
	{
		printf("wrong ip");
		return -1;
	}
	return 0;
}

