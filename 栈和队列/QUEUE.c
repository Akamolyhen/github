#include "QUEUE.h"

void QueueInit(Queue* p){
   p->front=p->rear=p->data;
   p->size=0;
}

void QueuePush(Queue* p,QuDataType x){
    if(p->size+1==QueueMax)
    return;
    *p->rear=x;
    p->rear++;
    if(p->rear - p->front==QueueMax){
        p->rear=p->data;
    }
    
}
void QueueDestory(Queue *p){
    p->front=p->rear=p->data;
   p->size=0;
}
void QueuePop(Queue* p){
    if(p->size==0){
        return;
    }
    p->front=
}