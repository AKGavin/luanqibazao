#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int main()
{
	int i,grp_size;
	uid_t myuid;
	gid_t mygid;
	struct passwd *pwd_st;
	struct group *grp_st;
	gid_t supp_groups[32];

	myuid = getuid();
	mygid = getgid();

	pwd_st = getpwuid(myuid);
	grp_st = getgrgid(mygid);
	grp_size = getgroups(32,supp_groups);

	printf("my account: %s (uid: %u)\n",pwd_st->pw_name,myuid);
	printf("main group: %s (gid: %u)\n",grp_st->gr_name,mygid);
	printf("supplementary groups: ");
	for(i=0;i<grp_size;i++) {
		grp_st = getgrgid(supp_groups[i]);
		printf("%s(%u) ",grp_st->gr_name,grp_st->gr_gid);
	}

	printf("\n\n");

	return 0;
}
