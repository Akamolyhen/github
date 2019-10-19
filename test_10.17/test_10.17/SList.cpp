//
//  SList.cpp
//  test_10.17
//
//  Created by 恶龙咆哮 on 2019/10/17.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#include "SList.hpp"
void SListInit(SList* plist){
    
}
void SListDestory(SList* plist);
SListNode* BuySListNode(SLDataType x);
void SListPushFront(SList* plist, SLDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLDataType x); // 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLDataType x);
void SListPrint(SList* plist);

