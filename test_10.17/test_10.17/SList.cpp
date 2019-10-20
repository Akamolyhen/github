//
//  SList.cpp
//  test_10.17
//
//  Created by 恶龙咆哮 on 2019/10/17.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#include "SList.hpp"
void SListInit(SList** pplist,SLDataType x){
    /**pplist=(SList*)malloc(sizeof(SList));
  (*pplist)->data=0;
    (*pplist)->next=NULL;*/
  *pplist=BuySListNode(x);
   
    
}
void SListDestory(SList* plist){
    while(plist->next)
    {
        SListEraseAfter(plist);
    }
    free(plist);
}

SList* BuySListNode(SLDataType x){
    SList* ret=(SList*)malloc(sizeof(SList));
    ret->data=x;
    ret->next=NULL;
    return ret;
}
void SListPushFront(SList** pplist, SLDataType x){
    SList* temp;
    temp=BuySListNode(x);
    temp->next=*pplist;
    *pplist=temp;

}
void SListPopFront(SList** pplist){
    if(*pplist==NULL)
        return;
    SList* temp=(*pplist)->next;
    free(*pplist);
    *pplist=temp;
}
SListNode* SListFind(SList* plist, SLDataType x){
    SList* temp;
    for(temp=plist;temp;temp=temp->next){
        if(temp->data==x)
            return temp;
    }
    return NULL;
}
    

// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLDataType x) // 在pos的前面进行插入
{
    SList* temp=BuySListNode(x);
    temp->next=pos->next;
    pos->next=temp;
}
void SListEraseAfter(SListNode* pos){
    SList* temp=pos->next;
    if(temp==NULL)
        return;
    pos->next=temp->next;
    free(temp);
}
void SListRemove(SList** plist, SLDataType x){
    SList* temp;
    if((*plist)->data==x){
        SListPopFront(plist);
        return;}
    for(temp=*plist;temp->next;temp=temp->next)
    {
        if(temp->next->data==x)
        {
            SListEraseAfter(temp);
            return;
        }
    }
}
void SListPrint(SList* plist){
    SList* temp;
    for(temp=plist;temp;temp=temp->next){
        printf("%d->",temp->data);
    }
    printf("NULL\n");
}

