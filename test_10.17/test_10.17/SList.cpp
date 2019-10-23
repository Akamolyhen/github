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
void SListInit(SList** pplist){
    *pplist=NULL;
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
void SListReverse(SList** pplist){
    SList *head=*pplist;//此指针在每次循环中指向当前链表的头
    SList *oldh=*pplist;//此指针在每次循环中始终指向链表原来的头，oldhead
    SList *temp=head->next;//此指针指向每次循环中的头指针的下一个
   while(temp)
   { oldh->next=temp->next;//将temp架空
    temp->next=head;//将temp前插，设为新头
    head=temp;//换头
    temp=oldh->next;//让temp进行下次循环删除的节点
   }
  *pplist=head;
  
}

void SListReverse2(SList** pplist){
    SList *pre= *pplist;
    SList *cur=pre->next;
    SList *next=cur->next;
    pre->next=NULL;
   while(next)
   { cur->next=pre;
    pre=cur;
    cur=next;
    if(next)
    next=next->next;
   }
   *pplist=cur;
   (*pplist)->next=pre;
}

SList* getintersectionNode(SList *headA,SList *headB){
    int lenA=0;
    int lenB=0;
    int gap;
    SList *cur;
    SList *longer=headA;
    SList *shorter=headB;
    for(cur=headA;cur;cur=cur->next){
        lenA++;
    }
    for(cur=headB;cur;cur=cur->next){
        lenB++;
    }
    gap=abs(lenA-lenB);
    if(lenA<lenB){
        longer=headB;
        shorter=headA;
    }
    for(int i=0;i<gap;i++){
        longer=longer->next;
    }
    for(;longer&&shorter;longer=longer->next,shorter=shorter->next){
        if(longer==shorter){
            return longer;
        }
    }
    return NULL;
}