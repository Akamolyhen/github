
#include<cstdio>
#include<cstdlib>
#include<mysql/mysql.h>

int main()
{
    //1,创建一个数据库连接句柄
    MYSQL* connect_fd = mysql_init(NULL);
    //2,和数据库建立链接(和TCP区分开，这是在应用层建立连接)
    //连接过程需要指定一些必要的信息
    //a) 链接句柄
    //b) 服务器的ip地址
    //c) 服务器的端口号
    //d) 用户名
    //e) 密码
    //f) 数据库名(blog_system)
    //g) unix_sock NULL
    //h) client_flag 0
   if( mysql_real_connect(connect_fd,"127.0.0.1","root",
                      "","blog_system", 3306,NULL,0 )==NULL)
   {
       printf("链接失败!%s\n",mysql_error(connect_fd));
       return 1;
   }
    printf("链接成功!\n");
   //3,设置编码方式
   //   mysql server 在最初安装的时候已经设置成了 utf8
   //   同时在客户端也设置成 utf8
   mysql_set_character_set(connect_fd,"utf8");
    char sql[1024*4]="select * from blog_table";
    //5,执行SQL语句
    int ret=mysql_query(connect_fd,sql);
     if(ret<0){
       printf("执行sql失败！%s\n",mysql_error(connect_fd));
       mysql_close(connect_fd);//断开链接
       return 1;
   }
     //6,遍历结果集合了
    MYSQL_RES* result=mysql_store_result(connect_fd);
    //a) 获取到结果集合中的行数和列数
    int rows=mysql_num_rows(result);
    int fields=mysql_num_fields(result);
    //b) 根据行数和列数来遍历结果
    for(int i=0;i<rows;++i){
        //一次获取一行数据
        MYSQL_ROW row=mysql_fetch_row(result);
    for(int j=0;j<fields;++j){
        printf("%s\t",row[j]);
    }
    printf("\n");
 }
    printf("请输入你想删除的title！\n");
    char title1[50];
    scanf("%s",title1);
    delete from blog_table where  
    mysql_close(connect_fd);//断开链接
    return 0;
}

