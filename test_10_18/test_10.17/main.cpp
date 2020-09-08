//
//  main.cpp
//  test_10.17
//
//  Created by 恶龙咆哮 on 2019/10/17.
//  Copyright © 2019 秦伟钦. All rights reserved.
//

#include "SList.hpp"

/*int _main()
{
    SList* head,head1;
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
     SListReverse(&head);
     SListPrint(head);
     SListReverse2(&head);
     SListReverse2(&head);
     SListPrint(head);

    return 0;
}
*/
int main()
{
    SList *head,*head1;
    SListInit(&head1);
    SListInit(&head);
    SListPushFront(&head, 7);
    SListPushFront(&head, 6);
    SListPushFront(&head, 5);
    SListPushFront(&head, 4);
    SListPushFront(&head1, 3);
    SListPushFront(&head1, 2);
    SListPushFront(&head1, 1);
    SListPrint(head);
    SListPrint(head1);
    head1->next->next->next=head->next;
    SList *ret=getintersectionNode(head,head1);
    if(ret){
        printf("%d\n",ret->data);
    }
    else
    {
        printf("NULL\n");
    }
    SListPrint(head);
    SListPrint(head1);
    
}
