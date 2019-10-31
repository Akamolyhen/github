#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<stdio.h>
#include<stdlib.h>
#define QueueMax 100
typedef int QuDataType;
typedef struct Queue
{
    QuDataType data[QueueMax];
    QuDataType *front;
    QuDataType *rear;
    size_t size;
}Queue;
void QueueInit(Queue* p);
void QueuePush(Queue* p,QuDataType x);
void QueueDestory(Queue *p);






#endif /*_QUEUE_H_*/