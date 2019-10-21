//
//  team.cpp
//  实验4
//
//  Created by 恶龙咆哮 on 2019/10/21.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#include "team.hpp"
void InitialQueue(QNode** pphead){
    *pphead=NULL;
}
void EnQueue(QNode** pphead,Person p){
    QNode* temp;
    temp=BuySListNode(p);
    temp->next=*pphead;
    *pphead=temp;
}
void DeQueue(QNode** pphead){
    if(*pphead==NULL)
        return;
    QNode* temp=(*pphead)->next;
    free(*pphead);
    *pphead=temp;
    
}
Person GetHead(QNode** phead){
    if(*phead)
        return (*phead)->data;
    else
        printf("队列为空\n");
    }
void QueueEmpty(QNode** pphead){
    if(*pphead==NULL)
        printf("队列为空\n");
    else
        printf("队列不为空\n");
}
QNode* BuySListNode(Person p){
    QNode* ret=(QNode*)malloc(sizeof(QNode));
    ret->data=p;
    ret->next=NULL;
    return ret;
}


