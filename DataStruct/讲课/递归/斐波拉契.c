#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// 1 1 2 3 5 ··· n
//递归写法
int function1(int n)        //求第n个的fib数是多少
{
    if(n==1||n==2)          //结束条件
        return 1;
    return function1(n-1)+function1(n-2);     //函数关系
}
//循环写法
int function2(int n){
    int m1,m2,temp;
    m1 = m2 =1;
    for(int i=3;i<=n;++i){
        temp = m1 + m2;
        m1 = m2;
        m2 = temp;
    }
    return m2;
}
//递归优化
int function3(int n,int* arr){
    if(n==1||n==2)          //结束条件
        return 1;
    if(arr[n]==-1)          //函数关系
        return function3(n-1,arr)+function3(n-2,arr);
    else
        return arr[n];
}
int main()
{
    int n;
    printf("Enter your n:\n");
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);         //动态分配地址，int arr[n]是错误的写法
    memset(arr,-1,(n+1)*sizeof(int));               //memset,快速给数组所有值赋值，头文件memory.h
    // for(int i=0;i<=n;++i)
    //     arr[i] = -1;
    printf("递归结果：%d\n循环结果：%d\n递归优化：%d\n",function1(n),function2(n),function3(n,arr));
}