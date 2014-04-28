#include <stdio.h>
#include <string.h>

const int max = 100;
int para[max];


int main()
{
	int i,j;
	int res = 0;
	for(i=999; i>=100; i--)
	{
		for(j=999; j>=100; j--)
		{
			memset(para, -1, sizeof(para));
		//	int answer = i*j;
			int answer = i*j;
			int count = 0;
			while(answer)
			{
				para[count] = answer % 10;
				count ++;
				answer /= 10;
			}
			int begin = 0, end = count-1;
			bool is_para = true;
			while(begin<end)
			{
				if(para[begin] != para[end])
				{
					is_para = false;
					break;
				}
				begin++;
				end--;
			}
			if(is_para)
			{
				if(i*j > res)
				{
					printf("%d*%d=%d\n",i,j,i*j);
					res = i*j;
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}