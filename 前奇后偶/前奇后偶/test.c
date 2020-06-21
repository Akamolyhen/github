#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>




void qianjihouou(int arr[20], int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			for (j = i + 1; j < n; j++)
			{
				if (arr[j] % 2 != 0)
				{
					k = arr[i];
					arr[i] = arr[j];
					arr[j] = k;
				}
			}
		}
	}
	for (m = 0; m < n; m++)
	{
		printf("%d ", arr[m]);
	}
}




int main()
{
	int arr[20] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int n = 0;
	char c;
	printf("请输入一些数字（其间以空格隔开）：");
	while (1)
	{
		scanf("%d", &arr[i]);
		i++;
		c = getchar();
		if (c == '\n')
		{
			break;
		}
	}
	qianjihouou(arr, i);
	//for (j = 0; j < i; j++)
	//{
	//	if (arr[j]%2 == 0)
	//	{
	//		for (k = j + 1; k < i; k++)
	//		{
	//			if (arr[k]%2 != 0)
	//			{
	//				m = arr[j];
	//				arr[j] = arr[k];
	//				arr[k] = m;
	//			}
	//		}

	//	}
	//}
	//for (n = 0; n < j; n++)
	//{
	//	printf("%d ",arr[n]);
	//}
	system("pause");
	return 0;
}
