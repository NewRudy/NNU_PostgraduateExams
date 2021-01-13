#include<stdio.h>
#include<stdlib.h>

void func(int *arr,int m,int r,int *result,int R)
{
    if(r==0)    //结束条件
    {
        for(int i=0;i<R;++i)
            printf("%d\t",result[i]);
        printf("\n");
        return;
    }
    for(int i=m;i>=r;--i)       //回溯，从r到m中选择一个数
    {
        result[r-1] = arr[i-1];
        func(arr,i-1,r-1,result,R);
    }
}
int main()
{
    int m,r;
    printf("Enter your m,r:\n");
    scanf("%d%d",&m,&r);
    int *arr = (int*)malloc(sizeof(int)*m);
    printf("Enter your arr:\n");
    for(int i=0;i<m;++i)
    {
        printf("Enter arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int *result = (int*)malloc(sizeof(int)*m);
    func(arr,m,r,result,r);

    return 0;
}