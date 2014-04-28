#include <stdio.h>
#include <string.h>

const int max = 500;
int sum[max];
int digit[max];

void multi(int num)
{
	int i;
	
	for(i=0; i<max-1; i++)
	{
		sum[i] = sum[i] * num + digit[i]; 
		if(sum[i] >= 10)
		{
			digit[i+1] += sum[i] / 10;
			sum[i] =  sum[i] % 10; 
		}
	}
	// remember to clear the value of digit array 
	memset(digit,0,sizeof(digit));
}

int main()
{
	sum[0] = 1;
	int i;
	for(i=0; i<1000; i++)
	{
		multi(2);
	}
	int count = 0;
	for(i=0; i<max; i++)
	{
		printf("%d\n", sum[i]);
		count += sum[i];
	}
	printf("%d\n", count);
	return 0;
}