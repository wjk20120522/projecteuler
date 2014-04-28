#include <stdio.h>
#include <math.h>
#include <string.h>

int const max = 30000;
int prime[max];

int big_integer[20] = {6,0,0,8,5,1,4,7,5,1,4,3,-1,-1,-1,-1,-1,-1,-1,-1};
int answer[20];


void put_into_answer(int factor)
{
	int i=0;
	while(answer[i] != -1)
	{
		i++;
	}
	if(factor == 0)
	{
		answer[i] = 0;
		i++;
	}
	else
	{
		while(factor)
		{
			int x = factor;
			if(x/100000000) x/=100000000;
			if(x/10000) x/=10000;
			if(x/100) x/=100;
			if(x/10) x/=10;
			answer[i] = x;
			i++;
			factor /= 10;
		}
	}
}


int main()
{
	int i,j,k=0;
	bool is_prime;
	for(i=2; ; i++)
	{
		is_prime = true;
		for(j=2; j<=sqrt(i*1.0); j++)
		{
			if(i%j == 0)
			{
				is_prime = false;
				break;
			}
		}
		if(is_prime)
		{
			prime[k] = i;
			k++;
			if(k>= max)
			{
				break;
			}
		}
	}
	printf("%d\n", prime[0]);
	printf("%d\n", prime[10000]);
	int count;
	int factor;
	memset(answer, -1, 20*sizeof(answer));
	for(j=0; j<max; j++)
	{
		count = 0;
		if(big_integer[0] == 1 && big_integer[1] == -1)
		{
			break;
		}
		for(i=0; i<20; i++)
		{
			if(big_integer[i] == -1)
			{
				break;
			}
			count = count*10 + big_integer[i];
			if(count >= prime[j])
			{
				factor = count/prime[j];
				put_into_answer(factor);
				count = count % prime[j];
			}
			else
			{
				put_into_answer(0);
			}
		}
		if(count == 0)
		{
			int temp = 0;
			k =0;
			while(answer[k] == 0)
				k++;
			for(; k<20; k++)
			{	
				big_integer[temp] = answer[k];
				temp++;
			}
			while(temp<20)
			{
				big_integer[temp] = -1;
				temp ++;
			}
			j--;
		}
		memset(answer, -1, 20*sizeof(answer));
	}
	printf("%d\n", prime[j]);

	return 0;
}