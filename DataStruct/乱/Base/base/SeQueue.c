#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int ElemType;

//存储结构
typedef struct SeQueue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SeQueue;

//插入元素进队列
int EnSeQueue(SeQueue* S,ElemType e)
{
    if((S->rear+1)%MAXSIZE==S->front)   //队列满
        return 0;
    S->data[S->rear] = e;
    S->rear = (S->rear+1)%MAXSIZE;
    return 1;
}
//删除元属
int OutSeQueue(SeQueue* S,ElemType *e)
{
    if(S->front==S->rear)
        return 0;
    *e = S->data[S->front];
    S->front = (S->front+1)%MAXSIZE;
    return 1;
}
//显示队列
void Display(SeQueue S)
{
    printf("\nThe Queue is :\n");
    int n = (S.rear-S.front+MAXSIZE)%MAXSIZE;
    int front = S.front;
    if(S.front!=S.rear)
    {
        for(int i=0;i<n;i<=i++)
        {
            printf("%d  ",S.data[front]);
            front = (front+1)%MAXSIZE;
        }
    }
}

int main()
{
    SeQueue S;
    S.front = 0;
    S.rear = 0;
    ElemType e;
    int judge=10;
    while (judge)
    {
        printf("\nfunctions:\n0.quit\n1.EnSeQueue(SeQueue* S,ElemType e)\n2.OutSeQueue(SeQueue* S,ElemType *e)\n\
3.Display(SeQueue S)\n");
        scanf("%d",&judge);
        switch (judge)
        {
        case 1:
            printf("Enter your e:");
            scanf("%d",&e);
            EnSeQueue(&S,e);
            break;
        case 2:
            OutSeQueue(&S,&e);
            printf("output e = %d",e);
            break;
        case 3:
            Display(S);
            break;
        default:
            printf("Nothing has done.");
            break;
        }
    }
    
}