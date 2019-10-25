#include"work.h"
void menu()
{
    printf("*********************************************\n");
    printf("***************  WELCOME  *******************\n");
    printf("*********************************************\n");
    printf("*******   1.add            2.dele    ********\n");//添加图书信息   删除图书信息
    printf("*******   3.search         4.show    ********\n");//查询图书信息  查看图书信息
    printf("*******   5.modifi         6.sort    ********\n");//修改图书信息   排序图书信息
    printf("*******           0.esc              ********\n");//  退出程序
    printf("*********************************************\n");
}
void test()
{
    contact my_contact = { 0 };
    init_contact(&my_contact);//初始化图书信息；
    int input = 0;
    do
    {
        menu();
        printf("请选择—>");
        scanf("%d", &input);
        switch (input)
        {
            case add:
                add_contact(&my_contact);//添加图书信息
                break;
            case dele:
                dele_contact(&my_contact);//删除图书信息
                break;
            case search:
                serch_contact(&my_contact);//查询图书信息
                break;
            case show:
                show_contact(&my_contact);//查看图书信息
                break;
            case modifi:
                modifi_contact(&my_contact);//修改图书信息
                break;
            case sort:
                sort_contact(&my_contact);//排序图书信息
                break;
            case esc:
                save_contact(&my_contact);//把数据保存到文件中
                DestroyContact(&my_contact);//释放动态内存
                printf("退出程序\n");
                break;
            default:
                printf("选择错误！请重新选择！\n");
        }
    } while (input);

}
int main()
{
    test();
    return 0;
}