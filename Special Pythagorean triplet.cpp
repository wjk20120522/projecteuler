#include <stdio.h>
#include <string.h>

const int large = 1000;

int main()
{
	int a,b,c;
	for(a=1; a<large-2; a++)
	{
		for(b=a+1; b<large-1; b++)
		{
			if(1000-a-b <= b)
			{
				break;
			}
			if(a*a + b*b == (1000-a-b)*(1000-a-b))
			{
				printf("%d\n", a*b*(1000-a-b));
				return 0;
			}

		}
	}
	return 0;
}