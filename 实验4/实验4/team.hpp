//
//  team.hpp
//  实验4
//
//  Created by 恶龙咆哮 on 2019/10/21.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#ifndef team_hpp
#define team_hpp

#include <stdio.h>
#include<stdlib.h>
typedef struct Person{
    char name[20];
    char sex;
}Person;
typedef struct QNode{
    Person data;
    struct QNode* next;
}QNode;

void InitialQueue(QNode** pphead);
void EnQueue(QNode** pphead,Person p);
void DeQueue(QNode** pphead);
Person GetHead(QNode* phead);
void QueueEmpty(QNode** phead);
QNode* BuySListNode(Person p);


#endif /* team_hpp */
