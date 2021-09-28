#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int o()
{
	system("/bin/sh");
	_exit(1);
}

n()
{
	char str[0x200];

	fgets(str, 0x200, stdin);
	printf(str);
	exit(1);
}

int main()
{
	n();
}
