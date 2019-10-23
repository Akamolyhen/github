//
//  SList.hpp
//  test_10.17
//
//  Created by 恶龙咆哮 on 2019/10/17.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#ifndef SList_hpp
#define SList_hpp
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
typedef int SLDataType;
typedef struct SListNode{
    SLDataType data;
    struct SListNode* next;
}SList;

//void SListInit(SList** pplist,SLDataType x);//初始化
void SListInit(SList** pplist);//初始化
void SListDestory(SList* plist);//销毁
SListNode* BuySListNode(SLDataType x);
void SListPushFront(SList** pplist, SLDataType x);//前插
void SListPopFront(SList** pplist);//前删
SListNode* SListFind(SList* plist, SLDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLDataType x); // 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SList** plist, SLDataType x);
void SListPrint(SList* plist);
void SListReverse(SList** pplist);
void SListReverse2(SList** pplist);
SList* getintersectionNode(SList *headA,SList *headB);

#endif /* SList_hpp */
