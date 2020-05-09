#define maxsize 100
#define dacernum 5
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int status;
using namespace std;

 typedef struct {
    char name[20];
    char sex;
}Person;
typedef struct {
    Person *base;
    int fronter;
    int rear;
}SqQueue;
status InitQueue(SqQueue &Q){
    Q.base=new Person[maxsize];
    if(!Q.base)
        exit(OVERFLOW);
    Q.fronter=Q.rear=0;
    return OK;
}
status EnQueue(SqQueue &Q,Person e){
    if((Q.rear+1)%maxsize==Q.fronter){
      printf("队列已满！\n");
      return ERROR;    
      }
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%maxsize;
    return OK;
}

void DeQueue(SqQueue &Q){
    if(Q.rear==Q.fronter){
        printf("队列为空！\n");
        exit(ERROR);
    }

    Q.fronter=(Q.fronter+1)%maxsize;

    
}

int QueueEmpty(SqQueue Q){
    if(Q.rear==Q.fronter)
    return 1;
    else
    {
        return 0;
    }
    
}

Person GetHead(SqQueue Q){
    if(Q.fronter!=Q.rear)
    return Q.base[Q.fronter];
    else
    {
        exit(ERROR);
    }
    
}
void DancePartner(Person dancer[],int num){
    SqQueue Mdancer,Fdancer;
    Person p;
    Person e;
    InitQueue(Mdancer);
    InitQueue(Fdancer);
    for(int i=0;i<num;i++){
        p=dancer[i];
        if(p.sex=='F'||p.sex=='f')
        EnQueue(Fdancer,p);
        else
        EnQueue(Mdancer,p);
    }
   printf("舞蹈搭档是：");
    while(!QueueEmpty(Fdancer)&&!QueueEmpty(Mdancer)){
        e=GetHead(Fdancer);
        cout<<e.name<<"\t";
        DeQueue(Fdancer);
        e=GetHead(Mdancer);
        cout<<e.name<<endl;
        DeQueue(Mdancer);
    }

    if(!QueueEmpty(Fdancer)){
        p=GetHead(Fdancer);
        printf("第一个将会获得舞伴的女生是：%s\n",p.name);
    }
    else if(!QueueEmpty(Mdancer)){
        p=GetHead(Mdancer);
        printf("第一个将会获得舞伴的男生是：%s\n",p.name);
    }
}
int main(){
    
    Person dancer[dacernum];
    
    for(int i=0;i<5;i++){
        cin>>dancer[i].name;
        do
        {
           cin>>dancer[i].sex;
           if(dancer[i].sex!='F'&&dancer[i].sex!='M'&&dancer[i].sex!='f'&&dancer[i].sex!='m')
           cout<<"性别有误请重输性别！"<<endl;
        } while (dancer[i].sex!='F'&&dancer[i].sex!='M'&&dancer[i].sex!='f'&&dancer[i].sex!='m');
       if(i<4)
       cout<<"下一位舞者信息："<<endl;
    }
    DancePartner(dancer,5);
    return 0;
}