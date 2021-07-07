#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int language = 0; // 0x8049988

int	greetuser(char *msg)
{
	char s[72];

	if (language == 1)
		strcpy(s, "Hyvää päivää ");
	else if (language == 2)
		strcpy(s, "Goedemiddag! ");
	else if (language == 0)
		strcpy(s, "Hello ");
	strcat(s, msg);
	puts(s);
}

int main(int argc, char **argv)
{
	char	b[20]; //used for strncpy (rep movsl at +256) and for greetuser, but never used explicitely ? ¯\_(ツ)_/¯
	char	str[76]; //0x50(%esp)
	char	*lang;   //0x9c(%esp)
	
	if (argc != 3)
		return (1);
	memset(str, 0, 19 * 4);
	strncpy(str, argv[1], 40);
	strncpy(str + 40, argv[2], 32);
	lang = getenv("LANG");
	if (lang != NULL)
	{
		if (memcmp(lang, "fi", 2) == 0)
		{
			language = 1;
		}
		else if (memcmp(lang, "nl", 2) == 0)
		{
			language = 2;
		}
	}
	strncpy(b, str, 19);
	return (greetuser(b));
}