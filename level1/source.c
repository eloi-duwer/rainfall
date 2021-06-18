#include <stdio.h>

void run()
{
	fwrite("Good... Wait what?\n", 0x1, 0x13, stdout);
}

int main(int argc, char **argv)
{
	char str[64];
	gets(str);
}