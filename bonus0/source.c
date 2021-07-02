#include <stdio.h>
#include <unistd.h>
#include <string.h>

void p(char *b1, char *b2)
{
	char	buff[4096]; // -0x1008(%ebp)

	puts(b2);

	read(0, buff, 4096);
	strchr(buff, '\n')[0] = '\0';
	strncpy(b1, buff, 20);
}

void pp(char *buff)
{
	char b1[20]; //-0x30(%ebp)
	char b2[20]; //-0x1c(%ebp)

	p(b1, " - ");
	p(b2, " - ");

	strcpy(buff, b1);
	buff[strlen(buff)] = ' ';
	strcat(buff, b2);

}

int main()
{
	char buff[64]; //0x16(%esp)

	pp(buff);
	puts(buff);
	return (0);
}

aaaaaaaaaaaaaaaaaaaa
aaaabbbbccccddddeeeeffffgggg