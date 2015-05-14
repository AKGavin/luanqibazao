#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define true 1

FILE *fp = NULL;

void * One(void * no) 
{
		while (true)
		{
				printf("NUAACS1\n");
				sleep(1);
		}
}

void * Two(void * no) 
{
		while (true)
		{
				printf("NUAACS2\n");
				sleep(1);
		}
}

void Stop(int signo) 
{
		printf("oops! stop!!!\n");
		printf("aaaa %p\n", fp);
		if(fp)
			fwrite("aaaaaa", 6, 1, fp);
		else
			_exit(0);
		fclose(fp);
		_exit(0);
}

int main()
{
		int res;
		pthread_t A, B;
		fp = fopen("aaa", "w");
		if(fp == NULL)
			return 0;

		signal(SIGINT, Stop); 
		res = pthread_create(&A, NULL, One, NULL);
		res = pthread_create(&B, NULL, Two, NULL);
		res = pthread_join(A, NULL);
		res = pthread_join(B, NULL);

		fclose(fp);
		fp = NULL;
		return 0;
}
