#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void pam_copy(char *data)
{
	if(!strcmp(data, "pam")){
		if(!access("/etc/pam.d/su.pam", F_OK))
			system("cp /etc/pam.d/su.pam /etc/pam.d/su");
		if(!access("/etc/pam.d/sudo.pam", F_OK))
			system("cp /etc/pam.d/sudo.pam /etc/pam.d/sudo");
		if(!access("/etc/pam.d/sshd.pam", F_OK))
			system("cp /etc/pam.d/sshd.pam /etc/pam.d/sshd");
		if(!access("/etc/pam.d/login.pam", F_OK))
			system("cp /etc/pam.d/login.pam /etc/pam.d/login");
		if(!access("/etc/pam.d/gdm.pam", F_OK))
			system("cp /etc/pam.d/gdm.pam /etc/pam.d/gdm");
		if(!access("/etc/pam.d/kde.pam", F_OK))
			system("cp /etc/pam.d/kde.pam /etc/pam.d/kde");
		if(!access("/etc/pam.d/gdm-password.pam", F_OK))
			system("cp /etc/pam.d/gdm-password.pam /etc/pam.d/gdm-password");
		system("/usr/sec/sec_lock -d");
	}else{
		if(!access("/etc/pam.d/su.bak", F_OK))
			system("cp /etc/pam.d/su.bak /etc/pam.d/su");
		if(!access("/etc/pam.d/sudo.bak", F_OK))
			system("cp /etc/pam.d/sudo.bak /etc/pam.d/sudo");
		if(!access("/etc/pam.d/sshd.bak", F_OK))
			system("cp /etc/pam.d/sshd.bak /etc/pam.d/sshd");
		if(!access("/etc/pam.d/login.bak", F_OK))
			system("cp /etc/pam.d/login.bak /etc/pam.d/login");
		if(!access("/etc/pam.d/gdm.bak", F_OK))
			system("cp /etc/pam.d/gdm.bak /etc/pam.d/gdm");
		if(!access("/etc/pam.d/kde.bak", F_OK))
			system("cp /etc/pam.d/kde.bak /etc/pam.d/kde");
		if(!access("/etc/pam.d/gdm-password.bak", F_OK))
			system("cp /etc/pam.d/gdm-password.bak /etc/pam.d/gdm-password");
		system("killall /usr/sec/sec_lock");
	}
}

int main(int argc, char **argv)
{
	if(argc <2){
		printf("Usage ..\n");
		return 0;
	}

	pam_copy(argv[1]);
	
	return 0;
}

