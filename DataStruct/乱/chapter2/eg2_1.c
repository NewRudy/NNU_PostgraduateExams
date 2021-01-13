#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//顺序表结构体
typedef struct Slist
{
    ElemType data[100];
    int length;
}Slist;
//插入e
void insert(Slist* S,int x)
{
    int i=0;
    //找到插入的位置
    for(;x>S->data[i];i++);
    //插入
    for(int j=S->length;j>i;j--)
        S->data[j] = S->data[j-1];
    S->data[i] = x;
    S->length++;
}
int main()
{
    Slist* S = (Slist*)malloc(sizeof(Slist));
    S->length = 5;
    for(int i=0;i<S->length;i++)
        scanf("%d",&S->data[i]);
    printf("Enter x:");
    int x;
    scanf("%d",&x);
    insert(S,x);
    printf("The reseult:\n");
    for(int i=0;i<S->length;i++)
        printf("%5d",S->data[i]);

    return 0;
}