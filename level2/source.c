#include <stdio.h>

void p()
{
	void *pt;
	char str[64];
	
	fflush(stdout);
	gets(str);
	if ((unsigned int)pt & 0xb0000000 == 0xb0000000)
	{
		printf("(%p)\n", pt);
		exit(1);
	}
	puts(str);
	strdup(str);
}

int	main(int argc, char **argv)
{
	p();
}