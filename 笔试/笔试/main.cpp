//
//  main.cpp
//  笔试
//
//  Created by 恶龙咆哮 on 2020/3/30.
//  Copyright © 2020 秦伟钦. All rights reserved.
//
/*#define High 100
#include <iostream>
#include<math.h>


int main(int argc, const char * argv[]) {
    static float ans1=High,ans2=High/2;
    static float high=High;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
             high=high/2;
             ans1=ans1+high*2;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        ans2=ans2/2;
    }
    
    printf("%f\t%f",ans1,ans2);
    return 0;
}*/
#include <stdio.h>

 int M = 3;

int main()
{
    int n, s = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
        s = (s+M)%i;
    printf("%d\n", s+1);
    return 0;
}
