#include"db.hpp"
//Model 部分
void TestBlogTable(){
    Json::StyledWriter writer;//序列化
    bool ret =false;
    MYSQL* mysql=blog_system::MySQLInit();
    blog_system::BlogTable blog_table(mysql);
   //测试插入
   // Json::Value blog;
   //blog["title"]="我的第一篇博客";
   //blog["content"]="我是一个男同,真实的女人，需要划清界限，否则剩下只有自我祭奠，peace&love";
   //blog["tag_id"]=1;
   //blog["create_time"]="2019/07/28";
   //bool ret= blog_table.Insert(blog);
  // printf("insert:%d\n",ret);
    //测试查找
   //Json::Value blogs;
    //ret=blog_table.SelectAll(&blogs);
   //printf("select all %d\n",ret);
   //printf("blogs:%s\n",writer.write(blogs).c_str());
   //测试查找单个博客
   // Json::Value blog;
   //ret =blog_table.Selectone(1,&blog);
   //printf("select one %d\n",ret);
  // printf("blog: %s\n",writer.write(blog).c_str());
  // 
  //测试修改博客
//    Json::Value blog;
  //  blog["blog_id"]=1;
   // blog["title"]="第一篇C语言博客";
   // blog["content"]="1.变量和类型\n什么是变量？创建一个'变量'就相当于创建一块内存空间";
 // ret=blog_table.Update(blog);
//printf("update %d\n",ret);

//测试删除博客
  ret=blog_table.Delete(2);
  printf("delete %d\n",ret);


   blog_system::MySQLRelease(mysql);

}

void TestTagTable(){
    Json::StyledWriter writer;
    MYSQL* mysql =blog_system::MySQLInit();
    blog_system::TagTable tag_table(mysql);
   //
   //
   //测试插入
    /* Json::Value tag; */
    /* tag["tag_name"]="C语言"; */
    /* bool ret=tag_table.Insert(tag); */
    /* printf("insert %d\n",ret); */
    //
    //
    //测试查找
    /* Json::Value tags; */
    /* bool ret=tag_table.SelectAll(&tags); */
    /* printf("select all %d\n",ret); */
    /* printf("tags:%s\n",writer.write(tags).c_str()); */
    
    //
    //测试删除
    bool ret =tag_table.Delete(1);
    printf("delete %d\n",ret);
    blog_system::MySQLRelease(mysql);
}

int main()
{
    TestBlogTable();
    TestTagTable();
    return 0;
}
