#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

//结点
typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;
//链队列
typedef struct LiQueue
{
    struct Node* front;
    struct Node* rear;
    int count;
}LiQueue;

//插入队列
int EnLiQueue(LiQueue* L,ElemType e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = 0;
    L->rear->next = p;
    L->rear = p;
    L->count++;
    return 1;
}
//输出元素
int OutLiQueue(LiQueue* L,ElemType* e)
{
    if(L->count==0) return 0;
    Node* p = L->front->next;
    *e = p->data;
    L->front->next = p->next;
    if(L->rear==p)
        L->rear == L->front;
    free(p);
    L->count--;
    return 1;
}
//显示队列
void Display(LiQueue L)
{
    Node* front = L.front->next;
    printf("\nThe Liqueue is :\n");
    for(int i=0;i<L.count;i++)
    {
        printf("%d  ",front->data);
        front = front->next;
    }
}

int main()
{
    //初始化队列
    LiQueue L;
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = 0;
    L.count = 0;
    L.front = head;
    L.rear = head;
    ElemType e;
    int judge=100;
    while(judge)
    {
        printf("\nfunctions:\n0.quit\n1.EnLiQueue(LiQueue* L,ElemType e)\n2.OutLiQueue(LiQueue* L,ElemType* e)\n\
3.Display(LiQueue L)\n");
        scanf("%d",&judge);
        switch (judge)
        {
        case 1:
            printf("Enter e:");
            scanf("%d",&e);
            EnLiQueue(&L,e);
            break;
        case 2:
            OutLiQueue(&L,&e);
            printf("Output is %d.\n",e);
            break;
        case 3:
            Display(L);
            break;
        default:
            printf("Nothing has done.\n");
            break;
        }
    }
}
