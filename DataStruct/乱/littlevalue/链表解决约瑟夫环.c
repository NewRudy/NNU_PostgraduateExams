#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int* function(int m,int n)
{
    int *stack = (int *)malloc(sizeof(int)*n),top = -1;
    node *L = (node*)malloc(sizeof(node));
    L->next = 0;
    node *rear = L;
    int i;
    for(i=0;i<n;++i)
    {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = i+1;
        temp->next = 0;
        rear->next = temp;
        rear = temp;
    }
    rear->next = L->next;
    node *p = L->next;
    while (p->next!=p)
    {
        for(i=0;i<m-2;++i)
            p = p->next;
        node *q = p->next;
        stack[++top] = q->data;
        p->next = q->next;
        p = p->next;
    }
    stack[++top] = p->data;
    return stack;
}
void main()
{
    int m,n;
    printf("Enter your m,n:\n");
    scanf("%d%d",&m,&n);
    int *result = function(m,n);
    printf("The result is :\n");
    for(int i=0;i<n;++i)
        printf("%d\t",result[i]);
}