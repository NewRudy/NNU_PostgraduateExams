#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

//单链表存储结构
typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node,*LiList;

//判断链表中是否有e值
int locate(LiList L,ElemType e)
{
    //指向第一个结点的指针
    Node* p = L->next;
    while (p)
    {
        //如果存在e
        if(e==p->data) return 1;
        p = p->next;
    }
    return 0;   //如果不存在
}
//单链表中插入e值，不破坏原来的顺序
void insert(LiList L,ElemType e)
{
    Node* p = L;      //p指向单链表头指针
    while(p)
    {
        if(e<=p->next->data)  break;      //e小于该结点说明再此处插入
        p = p->next;
    }
    /*插入e值 */
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
}
//将B中A不存在的值按非递减有序插入A中
LiList merge(LiList A,LiList B)
{
    Node* p = B->next;      //p指向B的开始结点
    while (p)
    {
        /*如果p的数据域再A中不存再，则按非递减顺序插入 */
        if(!locate(A,p->data))
            insert(A,p->data);
    }
    return A;
}




/*解法二 */
LiList merge(LiList A,LiList B)
{
    LiList C = (LiList)malloc(sizeof(Node));    //新建C链表
    Node* p = (Node*)malloc(sizeof(Node));      //p一直指向C的最后个结点
    C->next = p;
    Node* a = A->next;
    Node* b = B->next;      //a,b一直指向A,B的开始结点
    /*如果A，B还有结点，则一直循环 */
    while (a&&b)
    {
        //将A，B中最小的结点插入C中
        if (a->data<b->data)
        {
            p->next = a;
            a = a->next;
        }
        else
        {
            p->next = b;
            b = b->next;
        }
    }
    if(!a)  p->next = b;
    if(!b)  p->next = a;

    return C;
}


/*主要链表中的头插法和尾插法 */