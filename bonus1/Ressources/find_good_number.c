#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int n;
	size_t nb;

	n = INT_MIN;
	do {
		nb = (size_t)n;
		if (4 * nb == 44)
		{
			printf("The right value for n is %d\n", n);
			return ;
		}
		n++;
	} while (n < 9);
	printf("Could not find a good value for n\n");
}