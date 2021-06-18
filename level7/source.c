#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//I don't know if we can know the size of this variable by looking at the assembly ?
//As it is used to print the flag it must be 64 bytes + null byte at the end
char c[65];

void m()
{
	printf("%s - %d\n", c, time(0));
}

int main()
{
	char *a;
	char *b;
	char *c;

	a = malloc(8);
	*a = 1;
	b = malloc(8);

}