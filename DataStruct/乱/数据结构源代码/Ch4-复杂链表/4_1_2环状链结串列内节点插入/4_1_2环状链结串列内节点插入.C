/* ======================================== */
/*    程式实例: 4_1_2.c                   */
/*    环状链结串列内节点插入                */
/* ======================================== */
#include <stdlib.h>

struct clist                      /* 环状串列结构宣告     */
{
   int data;                      /* 节点资料             */
   struct clist *next;            /* 指向前一节点的指标   */
};
typedef struct clist cnode;       /* 环状串列新型态       */
typedef cnode *clink;             /* 环状串列指标新型态   */

/* ---------------------------------------- */
/*  环状链结串列的列印                      */
/* ---------------------------------------- */
void printclist(clink head)
{
   clink ptr;

   ptr = head;                    /* 指向串列开始         */
   do                             /* 串列走访回路         */
   {
      printf("[%d]",ptr->data);   /* 列印节点资料         */
      ptr = ptr->next;            /* 指向下一个节点       */
   } while ( head != ptr && head != head->next );
   printf("\n");                  /* 换行                 */
}

/* ---------------------------------------- */
/*  环状链结串列的节点插入                  */
/* ---------------------------------------- */
clink insertnode(clink head,clink ptr,int value)
{
   clink new_node;                /* 新节点的指标         */
   clink previous;                /* 前一节点指标         */

   /* 建立新节点配置节点记忆体 */
   new_node = ( clink ) malloc(sizeof(cnode));
   if ( !new_node )               /* 检查记忆体指标       */
      return NULL;
   new_node->data = value;        /* 建立节点内容         */
   new_node->next = NULL;         /* 设定指标初值         */

   if ( head == NULL )            /* 如果串列是空的       */
   {
      new_node->next = new_node;  /* 指向自身节点         */
      return new_node;            /* 传回新节点指标       */
   }

   if ( ptr == NULL )
   {
      /* 第一种情况: 插在第一节点之前且成为串列开始 */
      new_node->next = head;
      previous = head;
      while ( previous->next != head ) /* 找最後一个节点  */
         previous = previous->next;    /* 指向下一个节点  */
      previous->next = new_node;  /* 前一节点指向新节点   */
      head = new_node;            /* 成为串列的开始       */
   }
   else
   {
      /* 第二种情况: 插在节点之後 */
      new_node->next = ptr->next; /* 新节点指向下一节点   */
      ptr->next = new_node;       /* 前一节点指向新节点   */
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
   clink head = NULL;             /* 环状链结串列指标     */
   int list[6] = { 1, 2, 3, 4, 5, 6 };   /* 阵列内容      */
   int i;

   head = insertnode(head,head,list[0]); /*建立第一个节点*/
   printclist(head);             /* 印出串列             */
   /* 第一种情况: 插在第一节点之前且成为串列开始 */
   head = insertnode(head,NULL,list[1]);
   printclist(head);             /* 印出串列             */
   for ( i = 2; i < 6; i++ )      /* 建立串列节点         */
   {
      /* 第二种情况: 插在第一节点之後 */
      head = insertnode(head,head,list[i]);
      printclist(head);          /* 印出串列             */
   }
}
