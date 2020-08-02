#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void init_contact(contact* pcon)//初始化联系人列表
{
	assert(pcon != NULL);
	pcon->count = 0;
	memset(pcon, '0', PEO_MAX*sizeof(pcon->people[0]));
	return;
}

void add_contact(contact* pcon)//添加联系人
{
	assert(pcon != NULL);
	if (pcon->count == PEO_MAX)
	{
		printf("联系人列表已满，无法添加！\n");
		return;
	}
	else
	{
		printf("请输入联系人的姓名：  ");
		scanf("%s", pcon->people[pcon->count].name);
		printf("请输入联系人的年龄：  ");
		scanf("%d", &(pcon->people[pcon->count].age));
		printf("请输入联系人的性别：  ");
		scanf("%s", pcon->people[pcon->count].sex);
		printf("请输入联系人的电话：  ");
		scanf("%s", pcon->people[pcon->count].number);
		printf("请输入联系人的住址：  ");
		scanf("%s", pcon->people[pcon->count].address);
		pcon->count++;
	}
	return;
}

void show_contact(const contact *pcon)//查看联系人
{
	assert(pcon != NULL);
	if (pcon->count == 0)
	{
		printf("联系人列表为空！\n");
		return;
	}
	int i = 0;
	printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "姓名", "年龄", "性别", "电话", "住址");
	for (i = 0; i < pcon->count; i++)
	{
		printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\t\n", pcon->people[i].name,
			pcon->people[i].age,
			pcon->people[i].sex,
			pcon->people[i].number,
			pcon->people[i].address);
	}

	return;
}

void dele_contact(contact *pcon)//删除联系人
{
	assert(pcon != NULL);
	int i = 0;
	int j = 0;
	char name[NAME_MAX];
	if (pcon->count == 0)
	{
		printf("联系人列表为空，无法删除！\n");
		return;
	}
	printf("请输入要删除联系人的名字：");
	scanf("%s", name);
	for (i = 0; i < pcon->count; i++)
	{
		if (strcmp(name, pcon->people[i].name) == 0)
		{
			for (j = i; j < pcon->count; j++)
			{
				pcon->people[j] = pcon->people[j + 1];
			}
			pcon->count--;
			printf("删除成功！\n");
			return;
		}
	}
	printf("联系人列表中没有此人！\n");
	return;
}

void serch_contact(const contact* pcon)//查询联系人
{
	assert(pcon != NULL);
	int i = 0;
	char name[NAME_MAX];
	if (pcon->count == 0)
	{
		printf("联系人列表为空！\n");
		return;
	}
	printf("请输入要查找的联系人的名字：");
	scanf("%s", name);
	for (i = 0; i < pcon->count; i++)
	{
		if (strcmp(name, pcon->people[i].name) == 0)
		{
			printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "姓名", "年龄", "性别", "电话", "住址");
			printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\t\n", pcon->people[i].name,
				pcon->people[i].age,
				pcon->people[i].sex,
				pcon->people[i].number,
				pcon->people[i].address);
			return;
		}
	}
	printf("查无此人！\n");
}

void modifi_contact(contact* pcon)//修改联系人
{
	assert(pcon != NULL);
	int i = 0;
	char name[NAME_MAX];
	if (pcon->count == 0)
	{
		printf("联系人列表为空！\n");
		return;
	}
	printf("请输入要修改联系人的名字：");
	scanf("%s", name);
	for (i = 0; i < pcon->count; i++)
	{
		if (strcmp(name, pcon->people[i].name) == 0)
		{
			printf("请输入修改后联系人的姓名：  ");
			scanf("%s", pcon->people[i].name);
			printf("请输入修改后联系人的年龄：  ");
			scanf("%d", &(pcon->people[i].age));
			printf("请输入修改后联系人的性别：  ");
			scanf("%s", pcon->people[i].sex);
			printf("请输入修改后联系人的电话：  ");
			scanf("%s", pcon->people[i].number);
			printf("请输入修改后联系人的住址：  ");
			scanf("%s", pcon->people[i].address);
			printf("修改成功！\n");
			return;
		}
	}
	printf("联系人列表中没有此人！\n");
	return;
}

void sort_contact(contact* pcon)//给联系人排序(冒泡排序)
{
	assert(pcon != NULL);
	int i = 0;
	int j = 0;
	int flag = 0;
	peoinfo tmp;
	if (pcon->count == 0)
	{
		printf("联系人列表为空！\n");
		return;
	}
	for (i = 0; i < pcon->count; i++)//确定趟数
	{
		flag = 1;
		for (j = 0; j < (pcon->count - i - 1); j++)
		{
			if (strcmp(pcon->people[j].name, pcon->people[j + 1].name)>0)
			{
				tmp = pcon->people[j];
				pcon->people[j] = pcon->people[j + 1];
				pcon->people[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			printf("排序成功！\n");
			return;
		}
	}
}