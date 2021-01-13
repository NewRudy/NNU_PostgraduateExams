/* ======================================== */
/*    程式实例: 4_3_1.c                   */
/*    双向链结串列的建立                    */
/* ======================================== */
#include <stdlib.h>

struct dlist                      /* 双向串列结构宣告   */
{
   int data;                      /* 节点资料           */
   struct dlist *front;           /* 指向下一节点的指标 */
   struct dlist *back;            /* 指向前一节点的指标 */
};
typedef struct dlist dnode;       /* 双向串列新型态     */
typedef dnode *dlink;             /* 双向串列指标新型态 */

/* ---------------------------------------- */
/*  使用阵列值建立双向链结串列              */
/* ---------------------------------------- */
dlink createdlist(int *array,int len)
{
   dlink head;                    /* 双向串列的指标     */
   dlink before;                  /* 前一节点的指标     */
   dlink new_node;                /* 新节点的指标       */
   int i;

   /* 建立第一个节点 */
   /* 配置节点记忆体 */
   head = ( dlink ) malloc(sizeof(dnode));
   if ( !head )                   /* 检查记忆体指标     */
      return NULL;
   head->data = array[0];         /* 建立节点内容       */
   head->front = NULL;            /* 设定指标初值       */
   head->back = NULL;             /* 设定指标初值       */
   before = head;                 /* 指向第一个节点     */

   for ( i = 1; i < len; i++ )    /* 用回路建立其它节点 */
   {
      /* 配置节点记忆体 */
      new_node = ( dlink ) malloc(sizeof(dnode));
      if ( !new_node )            /* 检查记忆体指标     */
         return NULL;
      new_node->data = array[i];  /* 建立节点内容       */
      new_node->front = NULL;     /* 设定指标初值       */
      new_node->back = before;    /* 将新节点指向前节点 */
      before->front = new_node;   /* 将前节点指向新节点 */
      before = new_node;          /* 新节点成为前节点   */
   }
   return head;                   /* 传回串列起始指标   */
}

/* ---------------------------------------- */
/*  双向链结串列的列印                      */
/* ---------------------------------------- */
void printdlist(dlink head,dlink now)
{
   while ( head != NULL )         /* 串列走访回路       */
   {
      if ( head == now )          /* 印出目前节点资料   */
         printf("#%d#",head->data);  /* 列印节点资料    */
      else
         printf("[%d]",head->data);  /* 列印节点资料    */
      head = head->front;         /* 指向下一个节点     */
   }
   printf("\n");                  /* 换行               */
}

/* ---------------------------------------- */
/*  主程式: 模拟双向串列的移动              */
/*  使用选项来移动节点, 且将值和节点编号印  */
/*  出.                                     */
/* ---------------------------------------- */
void main()
{
   dlink head;                    /* 双向链结串列指标   */
   dlink now = NULL;              /* 目前节点指标       */
   int list[6] = { 1, 2, 3, 4, 5, 6 };   /* 阵列内容    */
   int select;                    /* 选择项1,2或3       */

   head = createdlist(list,6);   /* 建立双向链结串列   */
   if ( head == NULL )
   {
      printf("记忆体配置失败! \n");     /* 串列建立失败 */
      exit(1);                    /* 结束程式           */
   }

   now = head;                    /* 目前指向第一节点   */
   while ( 1 )                    /* 主回路开始         */
   {
      printf("链表内容是: ");
      printdlist(head,now);      /* 列印出内容         */
      /* 选项内容 */
      printf("[1]往下移动 [2]往回移动 [3]离开 ==> ");
      scanf("%d",&select);        /* 读入选项           */
      switch ( select )
      {
         /* 往下移动 */
         case 1: if ( now->front != NULL )
                    now = now->front;   /* 指向下一节点 */
                 break;
         /* 往回移动 */
         case 2: if ( now->back != NULL )
                    now = now->back;    /* 指向前一节点 */
                 break;
         /* 离开 */
         case 3: exit(1);         /* 结束程式           */
      }
   }
}
