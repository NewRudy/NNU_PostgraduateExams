#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LiNode
{
    ElemType data;
    struct LiNode* next;
}LiNode,*LiList;
typedef struct SeList
{
    ElemType data[100];
    int length;
}SeList;


int search(LiNode* head,int k)
{
    SeList* S = (SeList*)malloc(sizeof(SeList));
    S->length = 0;
    /*将链表转为顺序表 */
    while (head)
    {
        S->data[S->length] = head->data;
        head = head->next;
        S->length++;
    }
    if(k>S->length) return 0;
    else return S->data[S->length-k];
}
//初始化
LiNode* InitLinkList(LiNode* L)
{
    L = (LiNode*)malloc(sizeof(LiNode));    //头结点
    L->next = 0;    
    L->data = 0;     //头结点数据域存放链表长度
    int length=0,value=0;
    printf("Enter your length:\n");
    scanf("%d",&length);
    LiNode *p,*r;
    r = L;
    for(int i=0;i<length;i++)
    {
        p = (LiNode*)malloc(sizeof(LiNode));
        p->next = 0;
        printf("Enter your value of %d: ",i+1);
        scanf("%d",&value);
        p->data = value;
        r->next = p;
        r = p;
        L->data++;
    }
    return L;
}

int main()
{
    LiList A;
    A = InitLinkList(A);
    printf("The result : %5d.\n",search(A,4));

    return 0;
}


/*
傻了
解法:设置两个指针即可，两个指针的间隔为k，第二个指针移到序列末尾
 */