#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int input = 0,count=0;
	while (cin >> input)
	{
		count = 0;
		for (int i = 2; i <= input; i++)
		{
			int sum = 1;
			for (int j = 2; j <= i; j++)
			{
				if ((i%j == 0) && (i != j))
				{
					sum += j;
				}
			}
			if (sum == i)
			{
				count++;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}