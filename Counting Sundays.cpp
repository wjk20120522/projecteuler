#include <iostream>

using namespace std;


//month[0] is no use
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//count the days between 1990,1,1 with year,month,day
int get_days(int year, int month, int day)
{
	int i;
	int days = 0;
	//first count the year days
	for (i = 1900; i < year; i++)
	{
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
		{
			days += 366;
		}
		else
		{
			days += 365;
		}
	}
	//count the month
	for (i = 1; i < month; i++)
	{

		days += months[i];
		if (i == 2)
		{
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			{
				days++;
			}
		}
	}
	days += day - 1;
	return days;
}

int main()
{
	int i, j;
	int days; 
	
	int res = 0;
	//every year
	for (i = 1; i < 101; i++)
	{
		//every month
		for (j = 1; j <= 12; j++)
		{
			days = get_days(1900 + i, j, 1);
			if ((days + 1) % 7 == 0)
			{
				res++;
			}
		}	
	}
	
	cout << res << endl;
	return 0;
}