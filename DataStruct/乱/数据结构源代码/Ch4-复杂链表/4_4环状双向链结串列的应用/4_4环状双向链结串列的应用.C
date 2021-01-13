/* ======================================== */
/*    程式实例: 4_4.c                     */
/*    环状双向链结串列的应用                */
/* ======================================== */
#include <stdlib.h>

struct cdlist                     /* 环状双向串列宣告     */
{
   int data;                      /* 节点资料             */
   struct cdlist *front;          /* 指向下一节点的指标   */
   struct cdlist *back;           /* 指向前一节点的指标   */
};
typedef struct cdlist cdnode;     /* 环状双向串列新型态   */
typedef cdnode *cdlink;           /* 串列指标新型态       */

/* ---------------------------------------- */
/*  环状双向链结串列的列印                  */
/* ---------------------------------------- */
void printcdlist(cdlink head,cdlink now)
{
   cdlink ptr;

   if ( head != NULL )            /* 串列是空的           */
   {
      ptr = head;                 /* 指向串列开始         */
      do                          /* 串列走访回路         */
      {
         if ( ptr == now )        /* 印出目前节点资料     */
            printf("#%d#",ptr->data);   /* 列印节点资料   */
         else
            printf("[%d]",ptr->data);   /* 列印节点资料   */
         ptr = ptr->front;        /* 指向下一个节点       */
      } while ( head != ptr && head != head->front );
      printf("\n");               /* 换行                 */
   }
}

/* ---------------------------------------- */
/*  环状双向链结串列的节点删除              */
/* ---------------------------------------- */
cdlink deletenode(cdlink head,cdlink ptr)
{
   if ( head == NULL )            /* 如果串列是空的       */
      return NULL;

   if ( ptr == head )             /* 如果是第一节点       */
   {
      /* 第一种情况: 删除第一个节点 */
      head = head->front;         /* 移至下一个节点       */
      ptr->back->front = ptr->front; /* 前节点指向下节点  */
      ptr->front->back = ptr->back;  /* 下节点指向前节点  */
   }
   else
   {
      /* 第二种情况: 删除中间节点 */
      ptr->back->front = ptr->front; /* 前节点指向下节点  */
      ptr->front->back = ptr->back;  /* 下节点指向前节点  */
   }
   free(ptr);                     /* 释回节点记忆体       */
   return head;                   /* 传回串列起始指标     */
}

/* ---------------------------------------- */
/*  环状双向链结串列的节点插入              */
/* ---------------------------------------- */
cdlink insertnode(cdlink head,cdlink ptr,int value)
{
   cdlink new_node;               /* 新节点的指标         */

   /* 建立新节点配置节点记忆体 */
   new_node = ( cdlink ) malloc(sizeof(cdnode));
   if ( !new_node )               /* 检查记忆体指标       */
      return NULL;
   new_node->data = value;        /* 建立节点内容         */

   if ( head == NULL )            /* 如果串列是空的       */
   {
      new_node->front = new_node; /* 指向自身节点         */
      new_node->back = new_node;  /* 指向自身节点         */
      return new_node;            /* 传回新节点指标       */
   }

   if ( ptr == NULL )
   {
      /* 第一种情况: 插在第一节点之前且成为串列开始 */
      head->back->front = new_node; /* 前一节点指回新节点 */
      new_node->front = head;       /* 新节点指向开始节点 */
      new_node->back = head->back;  /* 新节点指回前一节点 */
      head->back = new_node;        /* 开始节点指向新节点 */
      head = new_node;              /* 成为串列的开始     */
   }
   else
   {
      /* 第二种情况: 插在节点之後 */
      ptr->front->back = new_node;  /* 下一节点指回新节点 */
      new_node->front = ptr->front; /* 新节点指向下一节点 */
      new_node->back = ptr;         /* 新节点指回插入节点 */
      ptr->front = new_node;        /* 插入节点指向新节点 */
   }
   return head;                     /* 传回串列起始指标   */
}

/* ---------------------------------------- */
/*  主程式: 环状双向串列的基本操作          */
/*  使用选项来移动节点, 且将串列节点内容印  */
/*  出. 选项功能有节点插入和删除.           */
/* ---------------------------------------- */
void main()
{
   cdlink head= NULL;             /* 环状双向串列指标     */
   cdlink now = NULL;             /* 目前节点指标         */
   int list[6] = { 1, 2, 3, 4, 5, 6 };  /* 阵列内容       */
   int select;                    /* 选择项1-6            */
   int value = 7;                 /* 插入内容计数         */
   int i;

   for ( i = 0; i < 6; i++ )      /* 建立双向链结串列     */
      head = insertnode(head,NULL,list[i]);

   while ( 1 )                    /* 主回路开始           */
   {
      if ( now == NULL )
         now = head;              /* 目前指向第一节点     */
      printf("链表内容是: ");
      printcdlist(head,now);     /* 列印出内容           */
      /* 选项内容 */
      printf("[1]往下移动 [2]往回移动 [3]删除节点 ");
      printf("\n[4]插入开始节点 [5]插入节点后 [6]离开 ==> ");
      scanf("%d",&select);        /* 读入选项             */
      switch ( select )
      {
         /* 往下移动 */
         case 1: now = now->front;  /* 指向下一节点       */
                 break;
         /* 往回移动 */
         case 2: now = now->back;   /* 指向前一节点       */
                 break;
         /* 删除目前节点 */
         case 3: if ( head != NULL )
                 {
                    head = deletenode(head,now);
                    now = head;   /* 目前指向第一节点     */
                 }
                 else
                    printf("链表是空的\n");
                 break;
         /* 将value的内容插入目前节点前 */
         case 4: head = insertnode(head,NULL,value);
                 value++;         /* 插入值加一           */
                 break;
         /* 将value的内容插入目前节点後 */
         case 5: head = insertnode(head,now,value);
                 value++;         /* 插入值加一           */
                 break;
         /* 离开 */
         case 6: exit(1);         /* 结束程式             */
      }
   }
}
