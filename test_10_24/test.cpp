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
status SListInit(SList &S){
    S.base=new datatype[MAXSIZE];
    if(!S.base)
    exit(overflow);
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return ok;
}
status pushfront(SList &s,datatype e){
    if(s.top-s.base==s.stacksize)
    return error;
    *(s.top++)=e;
    return ok;
}
datatype gettop(SList s){
    if(s.top!=s.base)
    {
        datatype e= *(s.top-1);
        s.top=s.top-1;
        return e;
    }
    else
   exit(NULL);
}
int main(){
    int str[MAXSIZE];
    SList s;
    SListInit(s);
    for(int j=0;j<MAXSIZE;j++){
        scanf("%d",&str[j]);
        if(str[j]!=-1)
        pushfront(s,str[j]);
        else
        {
            break;
        }
        
    }
    datatype e=gettop(s);
    printf("top=%d\n",e);
    return 0;
}
