#include <iostream>
#include <fstream>
using namespace std;

int res[60];

int main()
{
	ifstream fin;
	int k = 0;
	char buff[100][51];
	fin.open("input.txt",ifstream::in);
	while(fin.good())
	{
		fin.getline(buff[k],51);
		 cout<<buff[k]<<endl;
		k++;
	}
	fin.close();

	int i,j;
	for(i=49; i>=0; i--)
	{
		int temp = 0;
		for(j=0; j<100; j++)
		{
			temp += (buff[j][i]-'0');
		}
		printf("%d\n", temp);
		temp += res[49-i];
		res[49-i] = temp % 10;
		res[50-i] += temp/10;
	}
	for(i=0; i<60; i++)
	{
		cout<<res[i]<<" ";
	}
	return 0;
}