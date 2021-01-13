#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//结点存储类型
typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;
//链表村存储类型
typedef struct LiStack
{
    Node* top;
    int count;
}LiStack;

//进栈
int EnStack(LiStack* L,ElemType e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->top;
    L->top = p;
    L->count++;
    return 1;
}
//出栈
int OutStack(LiStack* L,ElemType *e)
{
    Node* p = L->top;
    *e = p->data;
    L->top = p->next;
    free(p);
    L->count--;
    return 1;
}
//输出栈
void Display(LiStack S)
{
    printf("The LiStack is :\n");
    while (S.top)
    {
        printf("%d  ",S.top->data);
        S.top = S.top->next;
    }
}

int main()
{
    LiStack L;
    L.count = 0;
    L.top = 0;
    ElemType e;
    int judge;
    while (judge)
    {
        printf("\nfunction:\n0:quit\n1.EnStack(LiStack* L,ElemType e)\n2.OutStack(LiStack* L,ElemType *e)\n\
3.Display(LiStack S)\n");
        scanf("%d",&judge);
        switch (judge)
        {
        case 1:
            printf("Enter e:");
            scanf("%d",&e);
            EnStack(&L,e);
            break;
        case 2:
            OutStack(&L,&e);
            printf("\ninput e = %d",e);
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