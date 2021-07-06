#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE	*fd; // 0x9c(%esp)
	char	str[66]; // 0x18(%esp)
	char	str2[65]; // Not referred directly, but as an offset of str it seems?? (main+158 and main+273)

	fd = fopen("/home/user/end/.pass", "r");
	memset(str, 0, 34);
	if (fd == 0 || argc != 2)
		return (255);
	fread(str, 1, 66, fd);
	str[65] = '\0';
	str[atoi(argv[1])] = '\0';
	fread(str2, 1, 65, fd);
	fclose(fd);
	if (strcmp(str, argv[1]) != 0)
		execl("/bin/sh", "sh", 0);
	else
		puts(str2);
	return(0);
}