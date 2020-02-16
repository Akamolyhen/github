#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;

int Issushu(int s)
{
	for (int i = 2; i < s; i++)
	{
		if (s%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int input = 0;
	while (cin >> input)
	{
		int min_a = 0;
		int min_b = input;
		for (int i = 2; i <= input / 2; i++)
		{
			int a = i;
			int b = input - a;
			if (Issushu(a) && Issushu(b))
			{
				int tmp = b - a;
				int min = min_b - min_a;
				if (tmp < min)
				{
					min_a = a;
					min_b = b;
				}
			}
		}
		cout << min_a << endl;
		cout << min_b << endl;
	}
	system("pause");
	return 0;
}