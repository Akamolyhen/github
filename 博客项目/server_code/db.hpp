//创建一些相关的类来封装数据库的操作


#include<cstdio>
#include<cstdlib>
#include<mysql/mysql.h>

namespace blog_system{
	static MySQL* MySQLInit(){
		//1、创建一个句柄
		MYSQL* connect_fd = mysql_init(NULL);
		//2、和数据库建立链接
		if( mysql_real_connect(connect_fd,"127.0.0.1","root",
                      "","blog_system", 3306,NULL,0 )==NULL)
   {
       printf("链接失败!%s\n",mysql_error(connect_fd));
       return NULL;
   }
   //	设定字符编码
   		mysql_set_character_set(connect_fd,"utf8");
   		return connect_fd;
	}


	static void MySQLRelease(MYSQL* connect_fd){
		//释放句柄并断开链接
		mysql_close(connect_fd);

	}

	//创建一个类，用于操作博客表的类
	class BlogTable{
	public:
		BlogTable(MYSQL* connect_fd){
			//通过这个构造函数获取到一个数据库的操作句柄
		}
		bool Insert(){

		}
		bool SelectAll(){

		}
		bool Selectone(){

		}
		bool Update(){

		}
		bool Delete(){
			
		}
	}
}//end blog_system