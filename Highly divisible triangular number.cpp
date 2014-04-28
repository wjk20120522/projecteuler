#include <stdio.h>
#include <math.h>

int num_of_dividor(int trian_num)
{
	int i;
	int count = 0;
	for(i=1; i<=sqrt(1.0*trian_num); i++)
	{
		if(0 == trian_num % i)
		{
			count += 2 ;
		}
		if(i*i == trian_num)
		{
			count --;
		}
	}
	return count;
}

int main()
{
	int i;
	for(i=10; ; i++)
	{
		int trian_num = (i*i+i)/2;
		if(trian_num < 0)
			printf("oh ,no\n");
		if(num_of_dividor(trian_num) > 500)
		{
			printf("%d\n", i);
			printf("%d\n", trian_num);
			break;
		}
	}
	return 0;
}