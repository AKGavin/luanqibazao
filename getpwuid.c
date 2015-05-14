#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

int main(void)
{
	struct passwd *pwd;
	pwd = getpwuid(getuid());
	printf("当前登陆的用户名为：%s\n", pwd->pw_name);

	return 0;
}
