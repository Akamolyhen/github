#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#define PEO_MAX 2   //自定义刚开始的容量
#define NAME_MAX 20 //自定义为名字分配空间的大小


enum num //枚举常量
{
    esc,
    add,
    dele,
    search,
    show,
    modifi,
    sort,
};

typedef struct library
{
    char name[NAME_MAX];//图书
  float fee;//费用
}library;
typedef struct contact
{
    library *book;//维护动态开辟的内存；
    int count;//当前图书的数量
    int sz;//当前空间的容量

}contact;

void init_contact(contact* pcon);//初始化图书信息列表
void add_contact(contact* pcon);//添加图书信息
void show_contact(const contact* pcon);//显示图书信息
void dele_contact(contact* pcon);//删除图书信息
void serch_contact(const contact* pcon);//查询图书信息
void modifi_contact(contact* pcon);//修改图书信息
void sort_contact(contact* pcon);//排序图书信息
int CheckCapacity(contact* pcon);//动态内存扩容（检查是否需要扩容）
void DestroyContact(contact* pcon);//释放动态内存
void save_contact(contact* pcon);//把数据保存到文件
void read_contact(contact* pcon);//读取数据到程序
