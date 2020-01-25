//
//  main.cpp
//  test_10_241
//
//  Created by 恶龙咆哮 on 2019/10/24.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#define MAXSIZE 100
#define overflow -2
#define ok 1
#define error -1
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef int status;
typedef struct SList
{
    datatype *base;
    datatype *top;
    int stacksize;
}SList;
status SListInit(SList *S){
    S->base=new datatype[MAXSIZE];
    if(!S->base)
    exit(overflow);
    S->top=S->base;
    S->stacksize=MAXSIZE;
    return ok;
}
status pushfront(SList *s,datatype e){
    if(s->top-s->base==s->stacksize)
    return error;
    *(s->top++)=e;
    return ok;
}
datatype* gettop(SList *s){
    if(s->top!=s->base)
    {
        datatype *e= s->top-1;
        s->top=s->top-1;
        return e;
    }
    else
    return NULL;
}
int main(){
    int str[10];
    SList *S = nullptr;
    SListInit(S);
    int i;
    scanf("%d",&i);
    for(int j=0;j<i;j++){
        scanf("%d",&str[j]);
    }
    i=0;
    while(str[i++]!=-1){
        pushfront(S,str[i]);
    }
    datatype *e=gettop(S);
    printf("top=%d",*e);
    return 0;
}
