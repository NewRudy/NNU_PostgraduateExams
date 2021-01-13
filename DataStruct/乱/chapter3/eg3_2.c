#include<stdio.h>
#include<stdlib.h>
#define maxSize 20

int opereter(int a,char op,int b)
{
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/')
    {
        if(b==0)
        {
            printf("error.\n");
            return 0;
        }
        else 
            return a/b;
    }
}
int com(char *exp)
{
    int a,b,c;      //a,b作为操作数，c保存结果
    char op;        //op保存运算符
    int stack[maxSize];int top = -1;    //初始化栈
    for(int i;*(exp+i)!='\0';i++)
    {
        if(*(exp+i)>='0'&&*(exp+i)<='9')
            stack[++top] = *(exp+i) - '0';
        else
        {
            op = *(exp+i);
            b = stack[top--];
            a = stack[top--];
            c = opereter(a,op,b);
            stack[++top] = c;
        }
    }
    
    return stack[top];
}

int main()
{
    char* exp = (char*)malloc(20*sizeof(char));
    printf("Enter your exp:\n");
    scanf("%s",exp);
    int result = com(exp);
    printf("result = %d",result);

    return 0;
}