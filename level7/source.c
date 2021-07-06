#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//I don't know if we can know the size of this variable by looking at the assembly ?
//As it is used in fgets I suppose it must be at leat 68 bytes
char c[68];

void m()
{
	printf("%s - %d\n", c, time(0));
}

int main(int argc, char **argv)
{
	char *a[2]; //0x1c(%esp)
	char *b[2]; //0x18(%esp)

	a[0] = malloc(8);
	a[0][0] = 1;

	a[1] = malloc(8);

	b[0] = malloc(8);
	b[0][0] = 2;

	b[1] = malloc(8);

	strcpy(a[1], argv[1]);

	strcpy(b[1], argv[2]);

	fgets(c, 68, fopen("/home/user/level8/.pass", "r"));
	puts("~~");

	return (0);
}