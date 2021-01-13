#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
//结点存储结构
typedef struct 
{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

//进栈
int EnStack(SqStack* S,ElemType e)
{
    if(S->top==MAXSIZE-1) return 0;
    S->data[S->top]=e;
    S->top++;
    return 1;
}
//出栈
int OutStack(SqStack* S,ElemType* e)
{
    if(S->top==-1) return 0;
    *e = S->data[S->top];
    S->top--;
    return 1;
}
//显示stack
void Display(SqStack S)
{
    printf("Now the stack is :\n");
    for(int i=0;i<S.top;i++)
        printf("%d  ",S.data[i]);
}

int main()
{
    SqStack S;
    ElemType e;
    int judge;
    S.top = 0;
    while (judge)
    {
        printf("\nFunction:\n0:quit\n1:EnStack(SqStack* S,ElemType e)\n2.OutStack(SqStack* S,ElemType* e)\n\
3.Display(SqStack S)\n");
        scanf("%d",&judge);
        switch (judge)
        {
        case 1:
            printf("input e:\n");
            scanf("%d",&e);
            EnStack(&S,e);
            break;
        case 2:
            OutStack(&S,&e);
            printf("e = %d",e);
            break;
        case 3:
            Display(S);
            break;
        default:
            printf("Nothing is done.\n");
            break;
        }
    }
    
}