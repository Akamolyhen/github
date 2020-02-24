#include <stdio.h>
int a1(int);
int a2(int);
int a3(int);
int main()
{
int (*a[3]) (int);
a[0] = a1;
a[1] = a2;
a[2] = a3;
int x1 = a[0](3);
int x2 = a[1](3);
int x3 = a[2](3);
printf("x1=%d\n",x1);
printf("x2=%d\n",x2);
printf("x3=%d\n",x3);
return 0;
}
int a1(int x){
printf("这是a1,其中x的值为:%d\n",x);
return x;
}
int a2(int x){
printf("这是a2,其中x的值为:%d\n",x);
return x;
}
int a3(int x){
printf("这是a3,其中x的值为:%d\n",x);
return x;
}
