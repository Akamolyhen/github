//创建一些相关的类来封装数据库的操作

#include<memory>
#include<cstdio>
#include<cstdlib>
#include<mysql/mysql.h>
#include<jsoncpp/json/json.h>
#include<cstring>

namespace blog_system{
	static MYSQL* MySQLInit(){
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
		BlogTable(MYSQL* connect_fd):mysql_(connect_fd){
			//通过这个构造函数获取到一个数据库的操作句柄
		}
		//以下操作相关参数都统一使用JSON的方式
		//json::Value jsoncpp 中最核心的类
		//json::Value 就表示一个具体的json对象
		bool Insert(const Json::Value& blog){
			const std::string& content=blog["content"].asCString();
			//char* to=new char[content.size()*2+1]
			std::unique_ptr<char> to(new char[content.size()*2+1]);
			mysql_real_escape_string(mysql_, to.get() ,content.c_str(),content.size());
			//拼装SQL语句
			std::unique_ptr<char> sql(new char[content.size()*2+4096]);
			sprintf(sql.get(),"insert into blog_table valus(null,'%s','%s')",
				blog["title"].asCString(),to.get(),
				blog["blog_id"].asInt(),blog["create_time"].asCString());
			int ret=mysql_query(mysql_,sql.get());
			if(ret!=0){
				printf("执行插入博客失败！%s\n",mysql_error(mysql_));
				return false;
			}
			printf("执行插入成功！\n");
			return true;

		}
		//blogs 作为一个输出型参数
		bool SelectAll(json::Value* blogs,
			const std::string& tag_id=""){
			char sql[1024*4]={0};
			if (tag_id==""){
				//此时不需要用tag_id筛选
				sprintf(sql,"select blog_id,title,tag_id,create_time from blog_table");

			}
			else{
				sprintf(sql,"select blog_id,title,tag_id,create_time from 
					blog_table where tag_id=%d",std::stoi(tag_id));
			}
			int ret=mysql_query(mysql_,sql);
			if(ret!=0){
				printf("执行查找所有博客失败！\n",mysql_error(mysql_));
				return false;
			}
			printf("执行查找所有博客成功！\n");
			MYSQL_RES* result=mysql_store_result(mysql_);
			int rows=mysql_num_rows(result);
			//遍历结果集合然后把结果写到blogs参数中，返回调用者		
			for(int i=0;i<rows;++i)
			{
				MYSQL_ROW row=mysql_fetch_row(result);
				Json::Value blog;
				blog["blog_id"]=atoi(row[0]);
				blog["title"]=row[1];
				blog["tag_id"]=atoi(row[2]);
				blog["create_time"]=row[3];
				blogs->append(blog);
			}
			//mysql查询的结果集合要及时释放
			musql_free_result(result);
			printf("执行查找所有博客成功！共查找到%d条博客\n"，rows);
		 	return true;

		}
		//blog同样是输出型参数，根据当前的blog_id在数据库中找到具体的blog参数返回
		bool Selectone(int32_t blog_id,Json::Value* blogs){
			char sql[1024]={0};
			sprintf(sql,"select blog_id,title,content,tag_id,create_time 
				from blog_table where blog_id =%d",blog_id);
			int ret=mysql_query(mysql_,sql);
			if(ret!=0)
			{
				printf("执行查找博客失败！%s\n",mysql_error(mysql_) );
				return false;
			}
			MYSQL_RES* result =mysql_store_result(mysql_);
			int rows=mysql_num_rows(result);
			if(row!=1){
				printf("查找到的博客不是只有一条！实际有%d条",rows);
				return false;
			}
			MYSQL_ROW row=mysql_fetch_row(result);
			(*blog)["blog_id"]=atoi(row[0]);
			(*blog)["title"]=row[1];
			(*blog)["content"]=row[2];
			(*blog)["title"]=atoi(row[3]);
			(*blog)["create_time"]=row[4];
			return true;
		}
		bool Update(const Json::Value& blog){
			const std::string& content=blog["content"].asCString();
			//char* to=new char[content.size()*2+1]
			std::unique_ptr<char> to(new char[content.size()*2+1]);
			mysql_real_escape_string(mysql_, to.get() ,content.c_str(),content.size())
			//拼装SQL语句
			std::unique_ptr<char> sql(new char[content.size()*2+4096]);
			sprintf(sql.get(),"update blog_table set title='%s',content='%s',tag_id=%d
				where blog_id=%d",
				blog["title"].asCString(),
				to.get(),
				blog["tag_id"].asInt,
				blog["blog_id"].asInt());
			int ret =mysql_query(mysql_,sql.get());
			if(ret!=0){
				printf("更新博客失败！%s\n",mysql_error(mysql_) );
				return false;
			}
			printf("更新博客成功！\n");
			return true;

		}
		bool Delete(int32_t blog_id){
			char sql[1024*4]={0};
			sprintf(sql,"delete from blog_table where blog_id=%d",blog_id);
			int ret=mysql_query(mysql_,sql);
			if(ret!=0){
				printf("删除博客失败！\n",mysql_error(mysql_));
				return false;
			}
			printf("删除博客成功！\n");
			return true;
		}
    private:
    	MYSQL* mysql_;
	};
	class TagTable
	{
	public:
		TagTable();
		bool Insert(const Json::Value& tag){
			return true;
		}
		bool Delete(int32_t tag_id){
			return true;
		}
		bool SelectAll(Json::Value* tags){
			return true;
		}
	private:
		
	};
}//end blog_system