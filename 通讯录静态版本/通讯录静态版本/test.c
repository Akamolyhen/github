#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void meau()
{
	printf("*********************************************\n");
	printf("*******   1.add            2.dele    ********\n");//添加联系人   删除联系人
	printf("*******   3.search         4.show    ********\n");//查询联系人   查看联系人
	printf("*******   5.modifi         6.sort    ********\n");//修改联系人   排序联系人
	printf("*******           0.esc              ********\n");//  退出通讯录
	printf("*********************************************\n");
}
void test()
{
	contact my_contact = { 0 };
	init_contact(&my_contact);//初始化联系人；
	int input = 0;
	do
	{
		meau();
		printf("请选择—>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			add_contact(&my_contact);//添加联系人
			break;
		case dele:
			dele_contact(&my_contact);//删除联系人
			break;
		case search:
			serch_contact(&my_contact);//查询联系人
			break;
		case show:
			show_contact(&my_contact);//查看联系人
			break;
		case modifi:
			modifi_contact(&my_contact);//修改联系人
			break;
		case sort:
			sort_contact(&my_contact);//排序联系人
			break;
		case esc:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误！请重新选择！\n");
		}
	} while (input);

}
int main()
{
	test();
	system("pause");
	return 0;
}