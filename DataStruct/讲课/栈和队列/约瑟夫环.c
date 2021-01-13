#include <stdio.h>
#define N 100
int josef(int n,int m)		//约瑟夫环的实现，n个人，数m
{
    int a[100];
    for(int i=0;i<n;i++)	//初始化
        a[i]=i+1;
    int i,j,k=0;
    for(i=0;i<n-1;i++)		//循环n次，每次出列一人
    {
        j=1;
        while(j<m)		//数数，数m-1次
        {
            while(a[k]==0)		//找到不等于0的人
            	k=(k+1)%n;
            j++;		//加一次代表数了一次数
            k=(k+1)%n;
        }
        while(a[k]==0)      //找到第m个人
        	k=(k+1)%n;
        printf("%d ",a[k]);
        a[k]=0;     //变成0，出列
    }
    for(int i=0;i<n;++i)
        if(a[i]!=0)
            return a[i];
}
int main()
{
    
    int i,j,m,n;
    printf("input n and m：\n");
    scanf("%d%d",&n,&m);
    printf("\n output：\n");
    
    printf("result:\t%d",josef(n,m));
    return 0;
}