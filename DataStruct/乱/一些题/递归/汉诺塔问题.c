#include<stdio.h>

void hanno(int n,char A,char B,char C)
{
    if(n==1)    
    {
        printf("将编号为%d的盘子从%c移到%c\n",n,A,C);
    }
    else
    {
        hanno(n-1,A,C,B);
        printf("将编号为%d的盘子从%c移到%c\n",n,A,C);
        hanno(n-1,B,A,C);
    }
}
int main()
{
    int n;
    printf("Enter your n:\n");
    scanf("%d",&n);
    hanno(n,'A','B','C');

    return 0;
}