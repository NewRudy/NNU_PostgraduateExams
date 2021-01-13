/* ======================================== */
/*    程式实例: 4_1_3.c                   */
/*    环状链结串列内节点删除                */
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
/*  使用阵列值建立环状链结串列              */
/* ---------------------------------------- */
clink createclist(int *array,int len)
{
   clink head;                    /* 环状串列的指标       */
   clink before;                  /* 前一节点的指标       */
   clink new_node;                /* 新节点的指标         */
   int i;

   /* 建立第一个节点 */
   /* 配置节点记忆体 */
   head = ( clink ) malloc(sizeof(cnode));
   if ( !head )                   /* 检查记忆体指标       */
      return NULL;
   head->data = array[0];         /* 建立节点内容         */
   head->next = NULL;             /* 设定指标初值         */
   before = head;                 /* 指向第一个节点       */

   for ( i = 1; i < len; i++ )    /* 用回路建立其它节点   */
   {
      /* 配置节点记忆体 */
      new_node = ( clink ) malloc(sizeof(cnode));
      if ( !new_node )            /* 检查记忆体指标       */
         return NULL;
      new_node->data = array[i];  /* 建立节点内容         */
      new_node->next = NULL;      /* 设定指标初值         */
      before->next = new_node;    /* 将前节点指向新节点   */
      before = new_node;          /* 新节点成为前节点     */
   }
   new_node->next = head;         /* 建立环状链结         */
   return head;                   /* 传回串列起始指标     */
}

/* ---------------------------------------- */
/*  环状链结串列的走访                      */
/* ---------------------------------------- */
clink findnode(clink head,int value)
{
   clink ptr;

   ptr = head;                    /* 指向串列开始         */
   do                             /* 串列走访回路         */
   {
      if ( ptr->data == value )   /* 比较值               */
         return ptr;              /* 找到值               */
      ptr = ptr->next;            /* 指向下一个节点       */
   } while ( head != ptr && head != head->next );
   return NULL;                   /* 没有找到值           */
}

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
/*  环状链结串列的节点删除                  */
/* ---------------------------------------- */
clink deletenode(clink head,clink ptr)
{
   clink previous;                /* 前一节点指标         */

   if ( head == NULL )            /* 如果串列是空的       */
      return NULL;

   previous = head;
   if ( head != head->next )      /* 串列多於一个节点     */
      while ( previous->next != ptr )  /*找节点ptr的前节点*/
         previous = previous->next;    /* 移至下一个节点  */

   if ( ptr == head )             /* 如果是第一节点       */
   {
      /* 第一种情况: 删除第一个节点 */
      head = head->next;          /* 移至下一个节点       */
      previous->next = ptr->next; /* 前节点指向下节点     */
   }
   else
      /* 第二种情况: 删除中间节点 */
      previous->next = ptr->next; /* 前节点指向下节点     */
   free(ptr);                     /* 释回节点记忆体       */
   return head;                   /* 传回串列起始指标     */
}

/* ---------------------------------------- */
/*  主程式:                                 */
/*  输入值, 用走访方式在环状链结串列中找寻. */
/*  找到就将之删除. 输入-1离开.             */
/* ---------------------------------------- */
void main()
{
   clink head;                    /* 环状链结串列指标     */
   clink find;                    /* 找到的串列节点       */
   int list[6] = { 9, 7, 3, 4, 5, 6 };   /* 阵列内容      */
   int value;                            /* 欲找寻值      */

   head = createclist(list,6);   /* 建立环状链结串列     */
   if ( head == NULL )
   {
      printf("记忆体配置失败! \n");    /* 串列建立失败    */
      exit(1);                    /* 结束程式             */
   }
   printf("链表内容是: ");
   printclist(head);             /* 印出串列内容         */
   while ( 1 )                    /* 主回路开始           */
   {
      printf("请输入查询值 ==> ");
      scanf("%d",&value);         /* 读入值               */
      if ( value == -1 )
      {
         printclist(head);       /* 印出删除後串列内容   */
         exit(1);                 /* 结束程式             */
      }
      find = findnode(head,value);    /* 在串列中找寻值  */
      if ( find != NULL )
      {
         printf("删除值: %d\n",find->data);
         head = deletenode(head,find);  /* 删除find节点  */
         printclist(head);       /* 印出串列内容         */
      }
      else
         printf("找不到搜索值\n");
   }
}
