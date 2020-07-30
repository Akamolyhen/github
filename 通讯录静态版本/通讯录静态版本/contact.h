#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define PEO_MAX 3   //自定义联系人列表容纳的联系人总数
#define NAME_MAX 10

enum num
{
	esc,
	add,
	dele,
	search,
	show,
	modifi,
	sort,
};

typedef struct peoinfo
{
	char name[NAME_MAX];//姓名
	int age;//年龄
	char sex[5];//性别
	char number[20];//电话号码
	char address[10];//住址
}peoinfo;

typedef struct contact
{
	struct peoinfo people[PEO_MAX];//静态版本。。
	int count;
}contact;

void init_contact(contact* pcon);//初始化联系人列表
void add_contact(contact* pcon);//添加联系人
void show_contact(const contact* pcon);//显示联系人
void dele_contact(contact* pcon);//删除联系人
void serch_contact(const contact* pcon);//查询联系人
void modifi_contact(contact* pcon);//修改联系人
void sort_contact(contact* pcon);//排序联系人