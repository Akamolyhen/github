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
   //4,拼接SQL语句
   char sql[1024*4]={0};
   char title[]="立一个flag";
   char content[]="我要学会C#";
   int tag_id=1;
   char date[]="2020/2/27";
   sprintf(sql,"insert into blog_table values(null,'%s','%s','%d','%s')"
           ,title,content,tag_id,date);
   printf("sql:%s\n",sql);
   //5,让数据库 服务器执行SQL
   int ret = mysql_query(connect_fd,sql);
   if(ret<0){
       printf("执行sql失败！%s\n",mysql_error(connect_fd));
       mysql_close(connect_fd);//断开链接
       return 1;
   }
   printf("insert succeedly!\n");
   mysql_close(connect_fd);//断开链接
    return 0;
}

