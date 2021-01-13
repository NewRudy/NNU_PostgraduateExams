#include<stdio.h>

//递归写法
void function1(int n,char A,char B,char C,int* count)
{
    if(n==0)    //结束条件
        return;
    else
    {
        //之间的关系：假设有n个圆盘，f(n)与f(n-1)的关系：是不是f(n-1)个圆盘都移到b
        // n-1 A B 
        // n A C 
        // n-1 B C
        function1(n-1,A,C,B,count);
        printf("将编号为%d的盘子从%c移到%c\n",n,A,C);
        ++(*count);
        function1(n-1,B,A,C,count);
    }
}

int main()
{
    int n;
    printf("Enter your n:\n");
    scanf("%d",&n);
    int* count = (int*)malloc(sizeof(int));
    *count = 0;
    function1(n,'A','B','C',count);
    printf("num:%d",*count);
    return 0;
}
//之间的关系：假设有n个圆盘，f(n)与f(n-1)的关系：是不是f(n-1)个圆盘都移到b
// n-1 A B 
// n A C 
// n-1 B C
//n A B C
//n-1 A C B
//
//n-1 B A C