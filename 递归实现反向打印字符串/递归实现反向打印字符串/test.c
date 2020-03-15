#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void reverse_string(char*string)
{
	if (*string)
	{

		char*start = string;
		char*end = string + my_strlen(string) - 1;
		char m = *start;
		*start = *end;
		*end = '\0';
		reverse_string(start + 1);
		*end = m;
	}
}

int my_strlen(char*str)
{
	if (*(str + 1))
	{
		return my_strlen(str + 1) + 1;
	}
	return 1;
}

int main()
{
	char arr[20] = { 0 };
	printf("ÇëÊäÈëÒ»´®×Ö·û:");
	scanf("%s", &arr);
	reverse_string(arr);
	printf("%s", arr);
	system("pause");
	return 0;
}