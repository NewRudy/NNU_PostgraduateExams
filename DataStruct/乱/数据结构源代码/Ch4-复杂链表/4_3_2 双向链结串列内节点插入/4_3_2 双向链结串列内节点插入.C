/* ======================================== */
/*    程式实例: 4_3_2.c                   */
/*    双向链结串列内节点插入                */
/* ======================================== */
#include <stdlib.h>

struct dlist                      /* 双向串列结构宣告     */
{
   int data;                      /* 节点资料             */
   struct dlist *front;           /* 指向下一节点的指标   */
   struct dlist *back;            /* 指向前一节点的指标   */
};
typedef struct dlist dnode;       /* 双向串列新型态       */
typedef dnode *dlink;             /* 双向串列指标新型态   */

/* ---------------------------------------- */
/*  双向链结串列的列印                      */
/* ---------------------------------------- */
void printdlist(dlink head)
{
   while ( head != NULL )         /* 串列走访回路         */
   {
      printf("[%d]",head->data);  /* 列印节点资料         */
      head = head->front;         /* 指向下一个节点       */
   }
   printf("\n");                  /* 换行                 */
}

/* ---------------------------------------- */
/*  双向链结串列的节点插入                  */
/* ---------------------------------------- */
dlink insertnode(dlink head,dlink ptr,int value)
{
   dlink new_node;                /* 新节点的指标         */

   /* 建立新节点,配置节点记忆体 */
   new_node = ( dlink ) malloc(sizeof(dnode));
   if ( !new_node )               /* 检查记忆体指标       */
      return NULL;
   new_node->data = value;        /* 建立节点内容         */
   new_node->front = NULL;        /* 设定指标初值         */
   new_node->back = NULL;         /* 设定指标初值         */

   if ( head == NULL )            /* 如果串列是空的       */
      return new_node;            /* 传回新节点指标       */

   if ( ptr == NULL )
   {
      /* 第一种情况: 插在第一个节点之前, 成为串列开始 */
      new_node->front = head;     /* 新节点指向串列开始   */
      head->back = new_node;      /* 原节点指向新节点     */
      head = new_node;            /* 新节点成为串列开始   */
   }
   else
   {
      if ( ptr->front == NULL )   /* 是否有下一个节点     */
      {
         /* 第二种情况: 插在串列的最後 */
         ptr->front = new_node;   /* 最後节点指向新节点   */
         new_node->back = ptr;    /* 新节点指回最後节点   */
      }
      else
      {
         /* 第三种情况: 插入节点至串列中间节点内 */
         ptr->front->back = new_node; /*下一节点指回新节点*/
         new_node->front = ptr->front;/*新节点指向下一节点*/
         new_node->back = ptr;    /* 新节点指回插入节点   */
         ptr->front = new_node;   /* 插入节点指向新节点   */
      }
   }
   return head;                   /* 传回串列起始指标     */
}

/* ---------------------------------------- */
/*  主程式:                                 */
/*  使用插入节点的方式来建立串列, 完成後将  */
/*  串列内容印出.                           */
/* ---------------------------------------- */
void main()
{
   dlink head = NULL;             /* 环状链结串列指标     */
   dlink tail = NULL;             /* 串列最後的指标       */
   int list[6] = { 1, 2, 3, 4, 5, 6 };   /* 阵列内容      */
   int i;

   head = insertnode(head,head,list[0]); /*建立第一个节点*/
   printdlist(head);             /* 印出串列             */
   tail = head;                   /* 保留串列最後指标     */
   /* 第一种情况: 插在第一个节点之前 */
   head = insertnode(head,NULL,list[1]);
   printdlist(head);             /* 印出串列             */
   /* 第二种情况: 插在串列的最後 */
   head = insertnode(head,tail,list[2]);
   printdlist(head);             /* 印出串列             */
   for ( i = 3; i < 6; i++ )      /* 建立串列节点         */
   {
      /* 第三种情况: 插入节点至串列中间节点内 */
      head = insertnode(head,head,list[i]);
      printdlist(head);          /* 印出串列             */
   }
}
