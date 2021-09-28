#include <stdlib.h>
#include <stdio.h>

int n()
{
	system("/bin/cat /home/user/level7/.pass");
}

int m()
{
	return puts("Nope");
}

int main(int argc, char **argv)
{
	char *str; // 0x1c(%esp)
	int (*func)(void); // 0x18(%esp)

	str = malloc(64);
	func = malloc(4);
	func = &m;
	strcpy(str, argv[1]);
	func();
}
