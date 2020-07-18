#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int input = 0;
	while (cin>>input)
	{
		int min = 1, max = 1, sum = 0, i = 0;
		for (i = 1; i <= input; i++)
		{
			if (i > 2)
			{
				sum = min + max;
				min = max;
				max = sum;
			}
		}
		if (i <= 2)
			sum = 1;
		cout << sum << endl;
	}
	system("pause");
	return 0;
}