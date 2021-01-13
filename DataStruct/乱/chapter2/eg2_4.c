#include<stdlib.h>
typedef int ElemType;
//链表存储类型
typedef struct LiNode
{
    ElemType data;
    struct LiNode* next;
}LiNode,*LiList;

int findDelete(LiList C,ElemType x)
{
    LiNode *p,*q;
    p = C;
    /*查找链表中是否有x值 */
    while (p->next)
    {
        if(x==p->next->data) break;
        p = p->next;
    }
    if(!p->next) return 0;
    /*删除x值的结点 */
    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}
