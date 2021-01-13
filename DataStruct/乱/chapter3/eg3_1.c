#include<stdio.h>
#include<stdlib.h>
#define maxSize 100

int match(char exp[],int n)
{
    char stack[maxSize];int top = -1;   //初始化栈

    for(int i=0;i<n;++i)
    {
        if(*(exp+i)=='(')
            stack[++top] = '(';     //入栈  
        if(*(exp+i)==')')
        {
            if(top == -1)
                return 0;
            else
                --top;     //出栈
        }
    }

    if(top == -1)
        return 1;
    else
        return 0;
}
//主函数试验
int main()
{
    char* exp = (char*)malloc(20*sizeof(char));
    printf("Enter your exp:");
    scanf("%s",exp);
    if(match(exp,20))
        printf("True.\n");
    else
        printf("False.\n");

    return 0;
}