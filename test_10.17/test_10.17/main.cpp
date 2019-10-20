//
//  main.cpp
//  test_10.17
//
//  Created by 恶龙咆哮 on 2019/10/17.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#include "SList.hpp"

int main()
{
    SList* head;
    SListInit(&head);
    SListPushFront(&head, 7);
    SListPushFront(&head, 6);
    SListPushFront(&head, 5);
    SListPushFront(&head, 4);
    SListPushFront(&head, 3);
    SListPushFront(&head, 2);
    SListPushFront(&head, 1);
//    SListPopFront(&head);
//    SListPopFront(&head);
//    SListPopFront(&head);
    SListInsertAfter(SListFind(head, 6), 9);
//
   SListRemove(&head, 6); SListEraseAfter(SListFind(head, 5));
    SListPrint(head);
//    SListDestory(head);
//    SListPrint(head);
    return 0;
}


