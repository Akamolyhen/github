//
//  main.c
//  firsttea
//
//  Created by 恶龙咆哮 on 2020/2/26.
//  Copyright © 2020 秦伟钦. All rights reserved.
//

#include "Header.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int x;
    scanf("%d",&x);
    int a[x];
    while(x--)
    {
        a[x]=x;
        printf("%d\t",a[x]);
    }
    printf("hehe\n");
    char c='1';
    printf("%c",c);

    
    
    return 0;
}
