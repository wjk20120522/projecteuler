#include <stdio.h>

int const max = 33;
int num[max];

int main()
{
	num[0] = 1;
	num[1] = 2;
	int i;
	for(i=2; i<max; i++)
	{
		num[i] = num[i-1] + num[i-2];
	}
	int count = 0;
	//here the magic 31 is tested by hand
	for(i=0; i<=31; i++)
	{
		if(num[i] %2 == 0)
		{
			count += num[i];
		}
	}
	printf("%d\n", count);
	return 0;
}