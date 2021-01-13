#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
/*单链表存储结构 */
typedef struct LiNode
{
    ElemType data;
    struct LiNode* next;
}LiNode,*LiList;

LiList sort(LiList A,LiList B,int m,int n)
{
    LiList C = (LiList)malloc(sizeof(LiNode));
    LiNode* r = C;      //r指向C的尾端
    LiNode* p = A->next;      //p指向A序列开始结点
    LiNode* q = B->next;        //q指向B序列开始结点
    /*如果有B序列的q指针指向最后了，则退出循环 */
    while (p&&q)
    {
        if(p->data<q->data) p = p->next;
        else if(p->data==q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            LiNode* term = (LiNode*)malloc(sizeof(LiNode));
            term->data = q->data;
            term->next = 0;
            r->next = term;
            r = term;
            q = q->next;
        }
    }
    if(!p) r->next = q;
    return C;
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
int main()
{
    LiList A,B;
    A = InitLinkList(A);
    B = InitLinkList(B);
    A = sort(A,B,7,4);
    display(A);
}

/*第二中解法，将A中B存在的元素全部删除 */
LiList sort2(LiList A,LiList B,int m,int n)
{
    LiNode* p = A->next;LiNode* q = B->next;
    LiNode* pre = A,*r;        //pre指针指向p的前一位
    while (p&&q)
    {
        if(p->data==q->data)
        {
            pre->next = p->next;
            p = p->next;
            r = p;
            free(r);
        }
        else if(p->data<q->data)
        {
            p = p->next;
            pre = pre->next;
        }
        else
            q = q->next;
    }
    return A;
}