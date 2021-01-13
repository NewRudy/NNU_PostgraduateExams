/* ======================================== */
/*    程式实例: 4_3_3.c                                                 */
/*    双向链结串列的节点删除                                    */
/* ======================================== */
#include <stdlib.h>

struct dlist                      /* 双向串列结构宣告      */
{
   int data;                      /* 节点资料              */
   struct dlist *front;           /* 指向下一节点的指标    */
   struct dlist *back;            /* 指向前一节点的指标    */
};
typedef struct dlist dnode;       /* 双向串列新型态        */
typedef dnode *dlink;             /* 双向串列指标新型态    */

/* ---------------------------------------- */
/*  使用阵列值建立双向链结串列              */
/* ---------------------------------------- */
dlink createdlist(int *array,int len)
{
   dlink head;                    /* 双向串列的指标        */
   dlink before;                  /* 前一节点的指标        */
   dlink new_node;                /* 新节点的指标          */
   int i;

   /* 建立第一个节点 */
   /* 配置节点记忆体 */
   head = ( dlink ) malloc(sizeof(dnode));
   if ( !head )                   /* 检查记忆体指标        */
      return NULL;
   head->data = array[0];         /* 建立节点内容          */
   head->front = NULL;            /* 设定指标初值          */
   head->back = NULL;             /* 设定指标初值          */
   before = head;                 /* 指向第一个节点        */

   for ( i = 1; i < len; i++ )    /* 用回路建立其它节点    */
   {
      /* 配置节点记忆体 */
      new_node = ( dlink ) malloc(sizeof(dnode));
      if ( !new_node )            /* 检查记忆体指标        */
         return NULL;
      new_node->data = array[i];  /* 建立节点内容          */
      new_node->front = NULL;     /* 设定指标初值          */
      new_node->back = before;    /* 将新节点指向前节点    */
      before->front = new_node;   /* 将前节点指向新节点    */
      before = new_node;          /* 新节点成为前节点      */
   }
   return head;                   /* 传回串列起始指标      */
}

/* ---------------------------------------- */
/*  释回双向链结串列的记忆体                */
/* ---------------------------------------- */
void freedlist(dlink head)
{
   dlink ptr;                     /* 储存目前节点指标      */

   while ( head != NULL )         /* 串列走访回路          */
   {
      ptr = head;                 /* 保留目前节点指标      */
      head = head->front;         /* 指向下一个节点        */
      free(ptr);                  /* 释回目前节点记忆体    */
   }
}

/* ---------------------------------------- */
/*  双向链结串列的列印                      */
/* ---------------------------------------- */
void printdlist(dlink head,dlink now)
{
   while ( head != NULL )         /* 串列走访回路          */
   {
      if ( head == now )          /* 印出目前节点资料      */
         printf("#%d#",head->data);  /* 列印节点资料       */
      else
         printf("[%d]",head->data);  /* 列印节点资料       */
      head = head->front;         /* 指向下一个节点        */
   }
   printf("\n");                  /* 换行                  */
}

/* ---------------------------------------- */
/*  双向链结串列的节点删除                  */
/* ---------------------------------------- */
dlink deletenode(dlink head,dlink ptr)
{
   if ( ptr->back == NULL )       /* 是否有前节点          */
   {
      /* 第一种情况: 删除第一个节点 */
      head = head->front;         /* 指向下一个节点        */
      head->back = NULL;          /* 设定指向前节点指标    */
   }
   else
   {
      if ( ptr->front == NULL )   /* 是否有下一个节点      */
      {
         /* 第二种情况: 删除最後一个节点 */
         ptr->back->front = NULL; /* 前节点指向NULL        */
      }
      else
      {
         /* 第三种情况: 删除中间的节点 */
         ptr->back->front = ptr->front; /*前节点指向下一节点*/
         ptr->front->back = ptr->back;  /*下一节点指向前节点*/
      }
   }
   free(ptr);                     /* 释回删除节点记忆体    */
   return head;                   /* 传回串列起始指标      */
}

/* ---------------------------------------- */
/*  主程式:                                 */
/*  使用选项来移动节点後, 删除目前的节点且  */
/*  将列出串列内容.                         */
/* ---------------------------------------- */
void main()
{
   dlink head;                    /* 双向链结串列指标      */
   dlink now = NULL;              /* 目前节点指标          */
   int list[6] = { 1, 2, 3, 4, 5, 6 };   /* 阵列内容       */
   int select;                           /* 选择项1-4      */

   head = createdlist(list,6);   /* 建立双向链结串列      */
   if ( head == NULL )
   {
      printf("记忆体配置失败! \n");      /* 串列建立失败   */
      exit(1);                    /* 结束程式              */
   }

   while ( 1 )                    /* 主回路开始            */
   {
      if ( now == NULL )
         now = head;              /* 目前指向第一节点      */
      printf("链表内容是: ");
      printdlist(head,now);      /* 列印出内容            */
      /* 选项内容 */
      printf("[1]往下移动 [2]往回移动 [3]删除节点 [4]离开 ==> ");
      scanf("%d",&select);        /* 读入选项              */
      switch ( select )
      {
         /* 往下移动 */
         case 1: if ( now->front != NULL )
                    now = now->front;    /* 指向下一节点   */
                 else
                    printf("在链表结尾\n");
                 break;
         /* 往回移动 */
         case 2: if ( now->back != NULL )
                    now = now->back;     /* 指向前一节点   */
                 else
                    printf("在链表开始\n");
                 break;
         /* 删除目前节点 */
         case 3: if ( head != NULL )
                 {
                    head = deletenode(head,now);
                    now = head;   /* 目前指向第一节点      */
                 }
                 else
                    printf("链表是空的\n");
                 break;
         /* 离开 */
         case 4: freedlist(head); /* 释回串列记忆体        */
                 exit(1);         /* 结束程式              */
      }
   }
}
