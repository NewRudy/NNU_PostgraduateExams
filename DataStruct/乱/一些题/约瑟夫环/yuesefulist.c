#include <stdio.h>
#include <stdlib.h>

//定义存储结构
typedef struct Node
{
    int n;      //n为编号
    struct Node *next;
}Node;
//约瑟夫环函数,用链表实现
int function(Node* L,int length)
{
    int m;
    printf("Enter m:");
    scanf("%d",&m);
    if(L==0)     return -1;
    Node *p,*q;
    p = L->next;
    q = p->next;
    int i = 1,j = 0;
    while (i<length)
    {
        j = 0;
        while (j<m-2)
        {
            p = p->next;
            q = q->next;
            ++j;
        }
        p->next = q->next;
        free(q);        //删除结点
        p = p->next;
        q = p->next;
        ++i;
    }
    return p->n;
}
void initList(Node* L)
{
    int n;
    printf("Enter your n:");
    scanf("%d",&n);
    L->n = n;       //头结点存储链表长度
    Node *temp,*rear = L;
    for(int i=1;i<=n;++i)
    {
        temp = (Node*)malloc(sizeof(Node));
        temp->n = i;
        temp->next = 0;
        //尾插法
        rear->next = temp;
        rear = temp;
    }
    //尾指针指向头结点
    rear->next = L->next;
}
int main()
{
    //初始化链表
    Node *L = (Node*)malloc(sizeof(Node));
    initList(L);
    int result = function(L,L->n);
    printf("result is %d",result);

    return 0;
}
