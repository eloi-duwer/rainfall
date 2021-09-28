#include <stdio.h>

unsigned int nb; // 0x8049810

void p(char *str)
{
	printf(str);
}

void n()
{
	char str[520];

	fgets(str, 512, stdin);
	p(str);
	if (nb == 0x1025544)
		system("/bin/cat /home/user/level5/.pass");
}

int main()
{
	n();
}
