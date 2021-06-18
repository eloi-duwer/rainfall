#include <stdio.h>
#include <string.h>

char *auth; // 0x8049aac
char *service; // 0x8049ab0

int main()
{
	unsigned int	len; //0x1c(%esp)
	char			str[128]; //0x20(esp)

	while (1)
	{
		printf("%p %p \n", auth, service);

		if (fgets(str, 128, stdin) == 0)
			break;
		if (strncmp("auth ", str, 5) == 0)
		{
			auth = malloc(4);
			auth[0] = '\0';

			len = strlen(str + 5);
			if (len <= 30)
			{
				strcpy(auth, str + 5);
			}
		}
		if (strncmp("reset", str, 5) == 0)
		{
			free(auth);
		}
		if (strncmp("service", str, 6))
		{
			service = strdup(str + 7);
		}
		if (strncmp("login", str, 5) == 0)
		{
			if (auth[32] != 0)
			{
				system("/bin/sh");
			}
			else
			{
				fwrite("Password:\n", 1, 10, stdout);
			}
		}
	}
	return (0);
}