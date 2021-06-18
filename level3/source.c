#include <stdio.h>
#include <stdlib.h>

unsigned int i;

void v()
{
	char str[520];

	fgets(str, 512, stdin);
	printf(str);
	if (i == 64) {
		fwrite("Wait what?!\n", 1, 0xc, stdout);
		system("/bin/sh");
	}
	return ;
}

int main()
{
	v();
}