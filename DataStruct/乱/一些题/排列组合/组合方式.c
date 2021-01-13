#include<stdio.h>
#include<stdlib.h>

void func(int *arr,int m,int r,int *result,int len,int n)        //从m个数中找r个数的组合方式
{
     if(len==r)     //终止条件，找到了r个数了
     {
        for(int i=0;i<r;++i)
            printf("%d\t",result[i]);
        printf("\n");
        return;
     }
     for(int i=n;i<m;++i)
     {
         result[len] = arr[i];
         func(arr,m,r,result,len+1,n+1);     //进入递归，但是还会回溯
     }
}
int main()
{
    int m,r,i,j;
    printf("Enter your m,r:\n");
    scanf("%d%d",&m,&r);
    int *arr = (int*)malloc(sizeof(int)*m);     //变量得动态分配一下内存
    for(i=0;i<m;++i)
    {
        printf("Enter arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int *result = (int*)malloc(sizeof(int)*r);    //组合方式保存在这里
    func(arr,m,r,result,0,0);

    return 0;
}