#include"work.h"

void init_contact(contact* pcon)//初始化列表
{
    assert(pcon != NULL);
    pcon->count = 0;//初始化个数
    pcon->sz = PEO_MAX;
    pcon->people = (stuinfo*)malloc(PEO_MAX*sizeof(stuinfo));//为列表创建动态内存
    if (pcon->people == NULL)
    {
        printf("%s\n", strerror(errno));//打印错误信息
        return;
    }
    memset(pcon->people, '0', PEO_MAX*sizeof(stuinfo));
    read_contact(pcon);
    return;
}

void add_contact(contact* pcon)//添加学生信息
{
    assert(pcon != NULL);
    if (1 == CheckCapacity(pcon))
    {
        printf("请输入学生的学号：  ");
        scanf("%s", pcon->people[pcon->count].student);
        printf("请输入学生的姓名：  ");
        scanf("%s", pcon->people[pcon->count].name);
        printf("请输入学生的语文成绩：  ");
        scanf("%d", &(pcon->people[pcon->count].yuwen));
        printf("请输入学生的数学成绩：  ");
        scanf("%d", &(pcon->people[pcon->count].shuxue));
        printf("请输入学生的英语成绩：  ");
        scanf("%d", &(pcon->people[pcon->count].yingyu));
        pcon->count++;
        return;
    }
}

void show_contact(const contact *pcon)//查看学生信息
{
    assert(pcon != NULL);
    if (pcon->count == 0)
    {
        printf("学生信息列表为空！\n");
        return;
    }
    int i = 0;
    printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "学号", "姓名", "语文", "数学", "英语");
    for (i = 0; i < pcon->count; i++)
    {
        printf("%-10s\t%-10s\t%-10d\t%-10d\t%-10d\t\n", pcon->people[i].student,
               pcon->people[i].name,
               pcon->people[i].yuwen,
               pcon->people[i].shuxue,
               pcon->people[i].yingyu);
    }


    return;
}

void dele_contact(contact *pcon)//删除学生信息
{
    assert(pcon != NULL);
    int i = 0;
    int j = 0;
    char student[20];
    if (pcon->count == 0)
    {
        printf("学生信息列表为空，无法删除！\n");
        return;
    }
    printf("请输入要删除学生的学号：");
    scanf("%s", student);
    for (i = 0; i < pcon->count; i++)
    {
        if (strcmp(student, pcon->people[i].student) == 0)
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
    printf("学生信息列表中没有此人！\n");
    return;
}

void serch_contact(const contact* pcon)//查询学生信息
{
    int input = 0;
    printf("按学号查询还是按最高分查询？（学号请输入 1，最高分请输入 2）\n");
    scanf("%d", &input);
    switch (input)
    {
        case 1:
            assert(pcon != NULL);
            int i = 0;
            char student[20];
            if (pcon->count == 0)
            {
                printf("学生信息列表为空！\n");
                return;
            }
            printf("请输入要查找的学生的学号：");
            scanf("%s", student);
            for (i = 0; i < pcon->count; i++)
            {
                if (strcmp(student, pcon->people[i].student) == 0)
                {
                    printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\t\n", "学号", "姓名", "语文", "数学", "英语");
                    printf("%-10s\t%-10s\t%-10d\t%-10d\t%-10d\t\n", pcon->people[i].student,
                           pcon->people[i].name,
                           pcon->people[i].yuwen,
                           pcon->people[i].shuxue,
                           pcon->people[i].yingyu);
                    return;
                }
            }
            printf("查无此人！\n");
            return;
        case 2:
            assert(pcon != NULL);
            if (pcon->count == 0)
            {
                printf("学生信息列表为空！\n");
                return;
            }
            i = 0;
            int j = 0;
            int max = 0;
            int a = 0;
            printf("语文最高分请输入 1，数学最高分请输入 2，英语最高分请输入 3\n");
            scanf("%d", &a);
            switch (a)
        {
            case 1:
                for (i = 0; i < pcon->count; i++)
                {
                    if (pcon->people[i].yuwen>max)
                        max = pcon->people[i].yuwen;
                }
                for (j = 0; j < pcon->count; j++)
                {
                    if (pcon->people[j].yuwen == max)
                    {
                        printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "学号", "姓名", "语文", "数学", "英语");
                        printf("%-10s\t%-10s\t%-10d\t%-10d\t%-10d\t\n", pcon->people[j].student,
                               pcon->people[j].name,
                               pcon->people[j].yuwen,
                               pcon->people[j].shuxue,
                               pcon->people[j].yingyu);
                        return;
                    }
                }
            case 2:
                i = 0;
                j = 0;
                max = 0;
                for (i = 0; i < pcon->count; i++)
                {
                    if (pcon->people[i].shuxue>max)
                        max = pcon->people[i].shuxue;
                }
                for (j = 0; j < pcon->count; j++)
                {
                    if (pcon->people[j].shuxue == max)
                    {
                        printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "学号", "姓名", "语文", "数学", "英语");
                        printf("%-10s\t%-10s\t%-10d\t%-10d\t%-10d\t\n", pcon->people[j].student,
                               pcon->people[j].name,
                               pcon->people[j].yuwen,
                               pcon->people[j].shuxue,
                               pcon->people[j].yingyu);
                        return;
                    }
                }
            case 3:
                i = 0;
                j = 0;
                max = 0;
                for (i = 0; i < pcon->count; i++)
                {
                    if (pcon->people[i].yingyu>max)
                        max = pcon->people[i].yingyu;
                }
                for (j = 0; j < pcon->count; j++)
                {
                    if (pcon->people[j].yingyu == max)
                    {
                        printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "学号", "姓名", "语文", "数学", "英语");
                        printf("%-10s\t%-10s\t%-10d\t%-10d\t%-10d\t\n", pcon->people[j].student,
                               pcon->people[j].name,
                               pcon->people[j].yuwen,
                               pcon->people[j].shuxue,
                               pcon->people[j].yingyu);
                        return;
                    }
                }
            default:
                printf("选择错误！请重新选择！\n");
                return;
        }
        default:
            printf("选择错误！请重新选择！\n");
            return;
    }
}

void modifi_contact(contact* pcon)//修改学生信息
{
    assert(pcon != NULL);
    int i = 0;
    char student[20];
    if (pcon->count == 0)
    {
        printf("学生信息列表为空！\n");
        return;
    }
    printf("请输入要修改学生的学号：");
    scanf("%s", student);
    for (i = 0; i < pcon->count; i++)
    {
        if (strcmp(student, pcon->people[i].student) == 0)
        {
            printf("请输入修改后学生的学号：  ");
            scanf("%s", pcon->people[i].student);
            printf("请输入修改后学生的姓名：  ");
            scanf("%s", pcon->people[i].name);
            printf("请输入修改后学生的语文成绩：  ");
            scanf("%d", &(pcon->people[i].yuwen));
            printf("请输入修改后学生的数学成绩：  ");
            scanf("%d", &(pcon->people[i].shuxue));
            printf("请输入修改后学生的英语成绩：  ");
            scanf("%d", &(pcon->people[i].yingyu));
            printf("修改成功！\n");
            return;
        }
    }
    printf("学生列表中没有此人！\n");
    return;
}

void sort_contact(contact* pcon)//给学生排序
{
    int input = 0;
    printf("按照姓名排序请输入 1，按照总分排序请输入 2\n");
    scanf("%d", &input);
    switch (input)
    {
        case 1:
            assert(pcon != NULL);
            int i = 0;
            int j = 0;
            int flag = 0;
            stuinfo tmp;
            if (pcon->count == 0)
            {
                printf("学生信息列表为空！\n");
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
        case 2:
            assert(pcon != NULL);
            if (pcon->count == 0)
            {
                printf("学生信息列表为空！\n");
                return;
            }
            i = 0;
            j = 0;

            for (i = 0; i < pcon->count; i++)//确定趟数
            {
                flag = 1;
                for (j = 0; j < (pcon->count - i - 1); j++)
                {
                    if ((pcon->people[j].yuwen + pcon->people[j].shuxue + pcon->people[j].yingyu)<(pcon->people[j + 1].yuwen + pcon->people[j + 1].shuxue + pcon->people[j + 1].yingyu))
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
        stuinfo* tmp = (stuinfo*)realloc(pcon->people, (pcon->sz + 2)*sizeof(stuinfo));
        if (tmp != NULL)
        {
            pcon->people = tmp;
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
    free(pcon->people);
    pcon->people = NULL;
    pcon->sz = 0;
    pcon->count = 0;
}

void save_contact(contact* pcon)//把数据保存到文件
{
    assert(pcon != NULL);
    int i = 0;
    FILE* pfin = fopen("student.txt", "wb");
    if (pfin == NULL)
    {
        perror("open file for write:");//打开文件失败后打印错误信息
        return;
    }
    for (i = 0; i < pcon->count; i++)
    {
        fwrite(pcon->people + i, sizeof(stuinfo), 1, pfin);
    }
    fclose(pfin);//关闭文件
    pfin = NULL;
    printf("保存成功\n");
    return;
}

void read_contact(contact* pcon)//读取文件中的数据到程序
{
    assert(pcon != NULL);
    stuinfo tmp = { 0 };
    FILE* pfout = fopen("student.txt", "rb");
    if (pfout == NULL)
    {
        perror("open file for read:");
        return;
    }
    while (fread(&tmp, sizeof(stuinfo), 1, pfout))
    {
        CheckCapacity(pcon);//检查是否需要扩容
        pcon->people[pcon->count] = tmp;
        pcon->count++;
    }
    fclose(pfout);
    pfout = NULL;
    //printf("加载数据完成!\n");//加载数据完成，实际运行时不用展示；
    return;
}





