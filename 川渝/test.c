#include<stdio.h>
int main()
{
    int k=3;
    int nums[7]={1,2,3,4,5,6,7};
    int temp;
        int n=sizeof(nums)/sizeof(int);
        printf("%d\n",n);
        for(int i=1;i<=k;i++)
        {
            temp=nums[n-1];
            for(int j=0;j<n-1;j++){
                nums[n-1-j]=nums[n-2-j];
            }
            nums[0]=temp;
        }
        for(int i=0;i<n;i++)
        printf("%d ",nums[i]);
        return 0;
}