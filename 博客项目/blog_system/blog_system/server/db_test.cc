#include"db.hpp"
void TestBlogTable(){
    MYSQL* mysql=blog_system::MySQLInit();
    blog_system::BlogTable blog_table(mysql);
    Json::Value blog;
    blog["title"]="我的第一篇博客";
    blog["content"]="我是一个男同";
    blog["tag_id"]=1;
    blog["create_time"]="2019/07/28";
    bool ret= blog_table.Insert(blog);
    printf("insert:%d\n",ret);
    blog_system::MySQLRelease(mysql);
}


int main()
{

    return 0;
}
