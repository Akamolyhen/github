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
#include <iostream>
#include <stdlib.h>
using namespace std;
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
status InitQueue(SqQueue &Q){
    Q.base=new Person[maxsize];
    if(!Q.base)
        exit(overflow);
    Q.fronter=Q.rear=0;
    return ok;
}
status EnQueue(SqQueue &Q,Person e){
    if((Q.rear+1)%maxsize==Q.fronter)
        return error;
    Q.base
}
