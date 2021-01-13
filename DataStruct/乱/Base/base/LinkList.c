#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define null 0

//定义链表结构体
typedef struct  LiNode
{
    ElemType data;
    struct LiNode *next;
}LiNode,*LiList;

//初始化
LiNode* InitLinkList(LiList L)
{
    L = (LiNode*)malloc(sizeof(LiNode));    //头结点
    L->next = null;    
    L->data = 0;     //头结点数据域存放链表长度
    int length=0,value=0;
    printf("Enter your length:\n");
    scanf("%d",&length);
    LiNode *p,*r;
    r = L;
    for(int i=0;i<length;i++)
    {
        p = (LiNode*)malloc(sizeof(LiNode));
        p->next = null;
        printf("Enter your value of %d: ",i+1);
        scanf("%d",&value);
        p->data = value;
        r->next = p;
        r = p;
        L->data++;
    }
    return L;
}
//销毁链表
void DestoryLinkList(LiNode** L)
{
    LiNode* p;
    while(*L)
    {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    if(!*L) printf("Destroyint is successful");
}
//查找链表
void SeLinkList(LiNode* L)
{
    ElemType e;
    printf("Enter a number to search:   ");
    scanf("%d",&e);
    LiNode* p = L->next;
    while (p)
    {
        if(p->data==e)
        {
            printf("The LinkList has %d.\n",e);
            break;
        }
        p = p->next;
    }
    if(!p) printf("The LinkList hasn't %d.\n",e);
}
//插入链表
void InsertLinkList(LiNode** L)
{
    ElemType e;
    int location=0,i;
    printf("Enter your location and e:");
    scanf("%d%d",&location,&e);
    LiNode* p = *L;
    for(i=1;i<location;i++) p = p->next;
    if(p)
    {
        LiNode* q = (LiNode*)malloc(sizeof(LiNode));
        q->next = p->next;
        p->next = q;
        q->data = e;
        printf("Inserting is successful.");
        (*L)->data++;
    }
}
//删除结点
void DeleteNode(LiNode** L)
{
    int location=0,i;
    printf("Enter your location");
    scanf("%d",&location);
    LiNode* p = *L;
    for(i=1;i<location;i++) p = p->next;
    if(p)
    {
        LiNode* q = p->next;
        p->next = q->next;
        free(q);
        printf("Deleting is succeful.\n");
        (*L)->data--;
    }
}
//输出链表
void display(LiNode* L)
{
    printf("The LinkList is : \n");
    LiNode* p = L->next;
    while (p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
}

int main(void)
{
    LiList L;
    L = InitLinkList(L);
    display(L);
    int judge=10;
    while (judge)
    {
    printf("\nfunction:\n0.quit\n1.SeLinkList(LiNode* L)\n2.InsertLinkList(LiNode** L)\n\
3.DeleteNode(LiNode** L)\n4.display(LiNode* L)\n5.DestoryLinkList(LiNode** L)");
    scanf("%d",&judge);
    switch (judge)
    {
    case 1:
        SeLinkList(L);
        break;
    case 2:
        InsertLinkList(&L);
        break;
    case 3:
        DeleteNode(&L);
        break;
    case 4:
        display(L);
        break;
    case 5:
        DestoryLinkList(&L);
        break;
    default:
        printf("Nothing is doing.\n");
        break;
    }
    }
    printf("\nQuiting.");

}
