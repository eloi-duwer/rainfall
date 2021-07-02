#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char str[40]; //0x14(%esp)
	int n; //0x3c(%esp)

	n = atoi(argv[1]);
	if (n > 9)
		return (1);
	else
	{
		memcpy(str, argv[2], (size_t)(n) * 4);
		if (n == 0x574f4c46)
			execl("/bin/sh", "sh", NULL);
	}
	return (0);
}