#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//递归写法
int function1(int n){			//传入参数n，求n!
    if(n<=2)
    	return n;
    return n*function1(n-1);
}
//循环写法
int function2(int n){
    int sum = 1;
    for(int i=2;i<=n;++i)
        sum *= i;
    return sum;
}
//递归优化
int function3(int n,int* arr){			//传入参数n，求n!
    if(n<=2)
    	return n;
    if(arr[n]==-1)			//假设arr数组初始化为-1
    	arr[n] = n*function3(n-1,arr);
	else
    	return arr[n];
}
int main(){
    int n;
    printf("Enter n:\n");
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);         //动态分配地址，int arr[n]是错误的写法
    memset(arr,-1,(n+1)*sizeof(int));               //memset,快速给数组所有值赋值，头文件memory.h
    // for(int i=0;i<=n;++i)
    //     arr[i] = -1;
    printf("递归结果：%d\n循环结果：%d\n递归优化：%d\n",function1(n),function2(n),function3(n,arr));
}