//
//  main.cpp
//  实验4
//
//  Created by 恶龙咆哮 on 2019/10/21.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#define maxsize 100
#define ok 1
#define error 0
#define overflow -2
#include<iostream>
#include<stdio.h>
#include <stdlib.h>

typedef int status;
typedef struct {
    char name[20];
    char sex;
}Person;
typedef struct {
    Person *base;
    int fronter;
    int rear;
}SqQueue;
status InitQueue(SqQueue Q){
    Q.base=new Person[maxsize];
    if(!Q.base)
        exit(overflow);
    Q.fronter=Q.rear=0;
    return ok;
}
status EnQueue(SqQueue Q,Person e){
    if((Q.rear+1)%maxsize==Q.fronter){
      printf("队列已满！\n");
      return error;    
      }
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%maxsize;
    return ok;
}

Person DeQueue(SqQueue Q,Person e){
    if(Q.rear==Q.fronter){
        printf("队列为空！\n");
        exit(error);
    }
    e=Q.base[Q.fronter];
    Q.fronter=(Q.fronter-1)%maxsize;
    return e;
    
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
        exit(error);
    }
    
}
void DancePartner(Person dancer[],int num){
    SqQueue Mdancer,Fdancer;
    Person p;
    InitQueue(Mdancer);
    InitQueue(Fdancer);
    for(int i=0;i<num;i++){
        p=dancer[i];
        if(p.sex=='F')
        EnQueue(Fdancer,p);
        else
        EnQueue(Mdancer,p);
    }
    printf("舞蹈搭档是：");
    while(!QueueEmpty(Fdancer)&&!QueueEmpty(Mdancer)){
        DeQueue(Fdancer,p);
        printf("%s",p.name);
        DeQueue(Mdancer,p);
        printf("%s",p.name);
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
    SqQueue party;
    Person dancer[5];
    InitQueue(party);
    printf("%d\n",QueueEmpty(party));
    for(int i=0;i<5;i++){   
       scanf("%c",&dancer[i].sex);
       
    }
    DancePartner(dancer,5);
    return 0;
}