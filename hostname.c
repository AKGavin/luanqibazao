#include <unistd.h>  
#include <sys/utsname.h>  
#include <sys/types.h>  
#include <pwd.h>  
int main(void){//  
	char hname[256];//节点名称  
	struct utsname uts;//节点结构信  
	uid_t uid;  
	gid_t gid;  
	struct passwd *pw;  

	if (gethostname(hname,255)!=0||uname(&uts)<0){  
		printf("不能得到主机信息");  
		exit(1);  
	}  

	printf("主机名:%s\n",hname);  
	printf("系统名称：%s\n 机器名称:%s\n",uts.sysname,uts.machine);  
	printf("节点名称:%s\n",uts.nodename);  
	printf("版本:%s,版本号%s",uts.release,uts.version);//系统版本,版本号  
	//取得当前用户登陆情况  
	uid=getuid();  
	gid=getgid();  
	pw=getpwuid(uid);  
	printf("用户id 为%d,用户组为%d\n",uid,gid);  
	printf("用户真实姓名%s\n用户名称:%s\n",pw->pw_gecos,pw->pw_name);  
	printf("用户uid:%s\ngid:%s\n",pw->pw_uid,pw->pw_gid);             
	printf("主目录:%s\n",pw->pw_dir);               
	printf("用户shell:%s\n",pw->pw_shell);       

}  
