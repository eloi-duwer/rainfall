#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int		n;
	char	*shell;
	gid_t	gid;
	uid_t	uid;
	char	*av[1];

	n = atoi(argv[1]);
	if (n == 423)
	{
		shell = strdup("/bin/sh");
		gid = getegid();
		uid = geteuid();
		setresgid(gid, gid, gid);
		setresuid(uid, uid, uid);
		av[0] = "/bin/sh";
		execv(shell, av);
	}
	else
	{
		fwrite("No !\n", 1, 5, stderr);
	}
	return (0);
}