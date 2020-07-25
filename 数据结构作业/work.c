#include"work.h"

void init_contact(contact* pcon)//初始化列表
{
    assert(pcon != NULL);
    pcon->count = 0;//初始化个数
    pcon->sz = PEO_MAX;
    pcon->book = (library*)malloc(PEO_MAX*sizeof(library));//为列表创建动态内存
    if (pcon->book == NULL)
    {
        printf("%s\n", strerror(errno));//打印错误信息
        return;
    }
    memset(pcon->book, '0', PEO_MAX*sizeof(library));
    read_contact(pcon);
    return;
}

void add_contact(contact* pcon)//添加图书信息
{
    assert(pcon != NULL);
    if (1 == CheckCapacity(pcon))
    {
        printf("请输入图书的名字：  ");
        scanf("%s", pcon->book[pcon->count].name);
        printf("请输入图书的费用：  ");
        scanf("%f", &(pcon->book[pcon->count].fee));
        pcon->count++;
        return;
    }
}

void show_contact(const contact *pcon)//查看图书信息
{
    assert(pcon != NULL);
    if (pcon->count == 0)
    {
        printf("图书信息列表为空！\n");
        return;
    }
    int i = 0;
    printf("%-10s\t%-10s\t\n", "图书姓名", "费用");
    for (i = 0; i < pcon->count; i++)
    {
        printf("%-10s\t%-10f\t\n", pcon->book[i].name,pcon->book[i].fee);
    }


    return;
}

void dele_contact(contact *pcon)//删除图书信息
{
    assert(pcon != NULL);
    int i = 0;
    int j = 0;
    char name[20];
    if (pcon->count == 0)
    {
        printf("图书信息列表为空，无法删除！\n");
        return;
    }
    printf("请输入要删除图书的名字：");
    scanf("%s", name);
    for (i = 0; i < pcon->count; i++)
    {
        if (strcmp(name, pcon->book[i].name) == 0)
        {
            for (j = i; j < pcon->count; j++)
            {
                pcon->book[j] = pcon->book[j + 1];
            }
            pcon->count--;
            printf("删除成功！\n");
            return;
        }
    }
    printf("图书信息列表中没有此书！\n");
    return;
}

void serch_contact(const contact* pcon)//查询图书信息
{
    int input = 0;
    printf("按图书姓名还是按图书费用查询？（图书姓名请输入 1，图书费用请输入 2）\n");
    scanf("%d", &input);
    switch (input){
        case 1:
        {
            int flag=0;
            char name[20];
            scanf("%s", name);
    for (int i = 0; i < pcon->count; i++)
    {
        if (strcmp(name, pcon->book[i].name) == 0){
             printf("%-10s\t%-10f\t\n", pcon->book[i].name,pcon->book[i].fee);
             flag=1;
        }
    }
     if(flag==1)
        break;
    printf("没有这本书！\n");
    
     break;
        }
        case 2:
        {
            int flag=0;
            float fee;
            scanf("%f",&fee);
            for (int i = 0; i < pcon->count; i++){
                if(fee==pcon->book[i].fee)
               { printf("%-10s\t%-10f\t\n", pcon->book[i].name,pcon->book[i].fee);
               flag=1;}


        }
         if(flag==1)
        break;
       printf("没有这本书！\n");
        break;
        }
            
    }
    
}

void modifi_contact(contact* pcon)//修改图书信息
{
    assert(pcon != NULL);
    int i = 0;
    char name[20];
    if (pcon->count == 0)
    {
        printf("图书列表为空，无法修改\n");
        return;
    }
    printf("请输入要修改图书的名字：");
    scanf("%s", name);
    for (i = 0; i < pcon->count; i++)
    {
        if (strcmp(name, pcon->book[i].name) == 0)
        {
            printf("请输入修改后图书的姓名：  ");
            scanf("%s", pcon->book[i].name);
            printf("请输入修改后图书的费用：  ");
            scanf("%f", &(pcon->book[i].fee));
            printf("修改成功！\n");
            return;
        }
    }
    printf("图书列表中没有此书！\n");
    return;
}

void sort_contact(contact* pcon)//给图书排序
{
    int input = 0;
    printf("按照姓名排序请输入 1，按照费用排序请输入 2\n");
    scanf("%d", &input);
    switch (input)
    {
        case 1:
            assert(pcon != NULL);
            int i = 0;
            int j = 0;
            int flag = 0;
            library tmp;
            if (pcon->count == 0)
            {
                printf("图书列表为空，无法修改\n");
                return;
            }
            for (i = 0; i < pcon->count; i++)//确定趟数
            {
                flag = 1;
                for (j = 0; j < (pcon->count - i - 1); j++)
                {
                    if (strcmp(pcon->book[j].name, pcon->book[j + 1].name)>0)
                    {
                        tmp = pcon->book[j];
                        pcon->book[j] = pcon->book[j + 1];
                        pcon->book[j + 1] = tmp;
                        flag = 0;
                    }
                }
                if (flag == 1)
                {
                    printf("排序成功！\n");
                    return;
                }
            }
        case 2:
            assert(pcon != NULL);
            if (pcon->count == 0)
            {
                printf("图书列表为空，无法修改\n");
                return;
            }
            i = 0;
            j = 0;

            for (i = 0; i < pcon->count; i++)//确定趟数
            {
                flag = 1;
                for (j = 0; j < (pcon->count - i - 1); j++)
                {
                    if (pcon->book[j].fee>pcon->book[j+1].fee)
                    {
                        tmp = pcon->book[j];
                        pcon->book[j] = pcon->book[j + 1];
                        pcon->book[j + 1] = tmp;
                        flag = 0;
                    }
                }
                if (flag == 1)
                {
                    printf("排序成功！\n");
                    return;
                }
            }
        default:
            printf("选择错误！请重新选择！\n");
            return;
    }
}

int CheckCapacity(contact* pcon)//检验是否需要扩容函数
{
    assert(pcon != NULL);
    if (pcon->sz == pcon->count)
    {
        library* tmp = (library*)realloc(pcon->book, (pcon->sz + 2)*sizeof(library));
        if (tmp != NULL)
        {
            pcon->book = tmp;
            pcon->sz += 2;
            //printf("扩容成功！\n");//扩容成功，实际运行时不用打印；
            return 1;
        }
        else
        {
            printf("%s\n", strerror(errno));//打印错误信息
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

void DestroyContact(contact* pcon)//释放动态内存
{
    assert(pcon != NULL);
    free(pcon->book);
    pcon->book = NULL;
    pcon->sz = 0;
    pcon->count = 0;
}

void save_contact(contact* pcon)//把数据保存到文件
{
    assert(pcon != NULL);
    int i = 0;
    FILE* pfin = fopen("name.txt", "wb");
    if (pfin == NULL)
    {
        perror("open file for write:");//打开文件失败后打印错误信息
        return;
    }
    for (i = 0; i < pcon->count; i++)
    {
        fwrite(pcon->book + i, sizeof(library), 1, pfin);
    }
    fclose(pfin);//关闭文件
    pfin = NULL;
    printf("保存成功\n");
    return;
}

void read_contact(contact* pcon)//读取文件中的数据到程序
{
    assert(pcon != NULL);
    library tmp = { 0 };
    FILE* pfout = fopen("name.txt", "rb");
    if (pfout == NULL)
    {
        perror("open file for read:");
        return;
    }
    while (fread(&tmp, sizeof(library), 1, pfout))
    {
        CheckCapacity(pcon);//检查是否需要扩容
        pcon->book[pcon->count] = tmp;
        pcon->count++;
    }
    fclose(pfout);
    pfout = NULL;
    //printf("加载数据完成!\n");//加载数据完成，实际运行时不用展示；
    return;
}





