#include <stdio.h>
#include <string.h>
#include <math.h>

int count[20];
int const max = 150000;
int prime[max];

void sum_it_up(int one_prime)
{
	int i = 0;
	int one_digit;
	int temp;
	while(one_prime)
	{
		one_digit = one_prime % 10;
		one_prime /= 10;
		temp = count[i] + one_digit;
		if(temp >= 10)
		{
			count[i+1] += 1;
			count[i] = temp - 10;
		}
		else
		{
			count[i] = temp;
		}
		i++;
	}
	// make the high digit be only one digit 
	for(; i<19; i++)
	{
		if(count[i] >= 10)
		{
			count[i+1] += count[i] /10;
			count[i] = count[i] % 10;
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
	for(i=0; i<max; i++)
	{
		if(prime[i] <2000000)
		{
			sum_it_up(prime[i]);
		}
		else
		{
			break;
		}
	}
	for(i=0; i<20; i++)
	{
		printf("%d ", count[i]);
	}
	return 0;
}