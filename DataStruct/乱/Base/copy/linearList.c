#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#define EOF (-1)
typedef struct _iobuf FILE;

//定义结点
typedef  struct LNode
{
    int data;
    struct  LNode *next;
} LNode;
 
void Print(LNode *L)///输出函数
{
    LNode *p;
    p=L;
    while((p->next)!=NULL)
    {
        printf("%d ",p->next->data);
        p = p->next;
    }
}
 
///建立链表及初始化
LNode *CreatL()
{
    LNode *L = (LNode *)malloc(sizeof(LNode));   //申请头结点空间
    L->next = NULL;                  //初始化一个空链表
    LNode *r;
    r = L;                          //r始终指向终端结点，开始时指向头结点
    int x;                         //x为链表数据域中的数据
    FILE *fp;
    fp=fopen("liList_data.txt","r");
    while((fscanf(fp,"%d",&x))!=EOF)
    {
 
        LNode *p;
        p = (LNode *)malloc(sizeof(LNode));   //申请新的结点
        p->data = x;                     //结点数据域赋值
        r->next =p;
        r = p;                 //将结点插入到表头L-->|1|-->|2|-->NULL
    }
    fclose(fp);
    r->next=NULL;
    return L;
}
void delet(LNode *L,int i)
{
    LNode *p=L;
    int count=0;
    //找到第i个结点的前一个位置p
    while(p->next)
    {
        count++;
        if(count==i)
        {
            break;
        }
        p=p->next;
    }
    LNode *q=p->next;
    p->next=p->next->next;
    free(q);
}
 
int main()
{
    LNode *L;
    printf("建立链表：");
 
    L=CreatL();//建立链表与初始化
    Print(L);//打印链表
 
    delet(L,3);
    printf("\n删除第三个元素后链表：");
    Print(L);//打印链表
    return 0;
}

 