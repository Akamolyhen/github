#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int a = 0;
	int count = 0;
	int max = 0;
	while (cin >> a)
	{
		
		count = 0;
		max = 0;
		while (a)
		{
			if (a & 1 == 1)
			{
				count++;
				if (count > max)
				{
					max = count;
				}
			}
			else
			{
				count = 0;
			}
			a = a >> 1;
		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}