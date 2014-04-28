#include <stdio.h>
#include <string.h>

const int max = 100;
int para[max];


int main()
{
	int n = 100;
	int res = (n*n*n*n)/4 + (n*n*n)/6 - (n*n)/4 - n/6;
	printf("%d\n", res);
	return 0;
}