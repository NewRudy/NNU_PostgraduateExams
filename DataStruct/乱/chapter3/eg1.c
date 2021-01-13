#include<stdio.h>
#include<stdlib.h>
#define maxSize 100

/*存储类型*/
typedef struct elem
{
    int data[maxSize];
    int top[2];
}elem;
//入栈
int push(elem* e,int x,int stackNum)
{
    if(e->top[0]+1==e->top[1])
        return 0;       //栈满
    else
    {
        if (stackNum==1)
            e->data[++e->top[0]] = x;
        else if(stackNum==2)
            e->data[--e->top[1]] = x;
    }
    return 1;
}
//出栈
int pop(elem* e,int *x,int stackNum)
{
    if(stackNum==1)
    {
        if(e->top[0]==-1) return 0;      //栈空
        *x = e->data[e->top[0]--];    //出栈
    }
    else if (stackNum==2)
    {
        if(e->top[1]==maxSize) return 0;     //栈空
        *x = e->data[e->top[1]++];    //出栈
    }
    return 1;
}
//实验
int main()
{
    elem* e = (elem*)malloc(sizeof(elem));    //初始化栈
    e->top[0] = -1;e->top[1] = maxSize;
    int judge = 1;
    while (judge)
    {
        printf("0:quit\n1:push\n2:pop\nEnter your judge:");
        scanf("%d",&judge);
        if(judge==1)
        {
            int x,stackNum;
            printf("Enter your x&&stackNum:\n");
            scanf("%d%d",&x,&stackNum);
            push(e,x,stackNum);
        }
        if(judge==2)
        {
            int x,stackNum;
            printf("Enter your stackNum:\n");
            scanf("%d",&stackNum);
            pop(e,&x,stackNum);
            printf("x = %d\n",x);
        }
    }
    
    return 0;
}