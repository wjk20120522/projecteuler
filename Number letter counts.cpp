#include <stdio.h>

int max[2000] = {0,3,3,5,4,4,3,5,5,4,3,
			6,6,8,8,7,7,9,8,8,6};

int count = 0;

void ten(int i)
{
	if(i%10 == 0)
	{
		count += max[i];
	}
	else
	{
		if(i/10 == 1)
		{
			count += max[i];
		}
		else
		{
			count += max[i-i%10];
			count += max[i%10];
		}
		
	}
}

void hundred(int i)
{
	if(i>=100 && i<=999)
	{
		count += max[i/100] + 7; //7 stands for hundred

		if(i%100 != 0)
		{
			count += 3;
		}		
	}

	ten(i%100);
}

void thousand(int i)
{
	if(i>=1000 && i<=9999)
	{
		count += max[i/1000] + 8; //8 stands for thousand
		// so it will have 'and' in the expression
		if(i % 1000 != 0 && (i-i%100)%10 == 0 )
		{
			count += 3;
		}
	}		
	if(i==100)
	{
		i=i;
	}

	hundred(i%1000);
}

int main()
{
	max[30] = 6;
	max[40] = 5;
	max[50] = 5;
	max[60] = 5;
	max[70] = 7;
	max[80] = 6;
	max[90] = 6;

	
	int i;
	for(i=1; i<=1000; i++)
	{
		thousand(i);
	}
	printf("%d\n",count);
	return 0;
}