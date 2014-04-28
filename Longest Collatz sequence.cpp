#include <stdio.h>

int num_sequence(unsigned long num)
{
	int count = 0;
	while(1 != num)
	{
		if(num%2 == 0)
		{
			num = num /2;
		}
		else
		{
		//	num = 3*num +1;
			num = num+(num+1)/2;
			count ++;
		}
		count ++;
		
	}
	return count;
}

int main()
{
	int max = 0;
	int max_num = 1;
	int i;
	for(i=999999; i>=1; i--)
	{
		int temp = num_sequence(i);
		if( temp > max )
		{
			max = temp;
			max_num = i;
		}
	}
	printf("%d\n", max_num);
	return 0;
}