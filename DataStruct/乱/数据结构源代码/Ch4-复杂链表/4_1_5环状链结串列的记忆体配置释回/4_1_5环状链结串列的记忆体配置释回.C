/* ======================================== */
/*    程式实例: 4_1_5.c                     */
/*    环状链结串列的记忆体配置释回          */
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
/*  链结串列的节点记忆体配置                */
/* ---------------------------------------- */
clink nodealloc(clink *memory)
{
   clink new_node;                /* 新节点的指标         */
   clink ptr;

   if ( (*memory) != NULL )       /* 串列是否是空         */
   {
      ptr = (*memory);
      *memory = (*memory)->next;  /* 指向下一个节点       */
      ptr->next = NULL;           /* 设定指标初值         */
      return ptr;                 /* 傅回新节点指标       */
   }
   else
   {
      /* 建立新节点配置节点记忆体 */
      new_node = ( clink ) malloc(sizeof(cnode));
      if ( !new_node )            /* 检查记忆体指标       */
         return NULL;
      new_node->next = NULL;      /* 设定指标初值         */
      return new_node;            /* 傅回新节点指标       */
   }
}

/* ---------------------------------------- */
/*  链结串列的节点记忆体释回                */
/* ---------------------------------------- */
void freenode(clink *memory,clink ptr)
{
   ptr->next = (*memory);         /* 插入串列开始         */
   (*memory) = ptr;               /* 设定串列指标         */
}

/* ---------------------------------------- */
/*  环状链结串列的列印                      */
/* ---------------------------------------- */
void printclist(clink head)
{
   clink ptr;

   printf("环链内容: ");
   ptr = head;                    /* 指向串列开始         */
   do                             /* 串列走访回路         */
   {
      printf("[%d]",ptr->data);   /* 列印节点资料         */
      ptr = ptr->next;            /* 指向下一个节点       */
   } while ( head != ptr );
   printf("\n");                  /* 换行                 */
}

/* ---------------------------------------- */
/*  列出记忆体串列内容                      */
/* ---------------------------------------- */
void printmemory(clink memory)
{
   clink ptr;

   printf("内存中链表的内容: ");
   ptr = memory;                  /* 指向串列开始         */
   while ( ptr != NULL )          /* 串列走访回路         */
   {
      printf("[%d]",ptr->data);   /* 列印节点资料         */
      ptr = ptr->next;            /* 指向下一个节点       */
   }
   printf("\n");                  /* 换行                 */
}

/* ---------------------------------------- */
/*  使用阵列值建立环状链结串列              */
/* ---------------------------------------- */
clink createclist(int *array,clink *memory,int len)
{
   clink head = NULL;             /* 环状串列的指标       */
   clink before;                  /* 前一节点的指标       */
   clink new_node;                /* 新节点的指标         */
   int i;

   /* 建立第一个节点 */
   head = nodealloc(memory);     /* 配置节点记忆体       */
   head->data = array[0];         /* 建立节点内容         */
   before = head;                 /* 指向第一个节点       */

   for ( i = 1; i < len; i++ )    /* 用回路建立其它节点   */
   {
      new_node = nodealloc(memory);  /* 配置节点记忆体   */
      new_node->data = array[i];  /* 建立节点内容         */
      before->next = new_node;    /* 将前节点指向新节点   */
      before = new_node;          /* 新节点成为前节点     */
   }
   new_node->next = head;         /* 建立环状链结         */

   return head;                   /* 传回串列起始指标     */
}

/* ---------------------------------------- */
/*  释回整个环状链结串列                    */
/* ---------------------------------------- */
void freeclist(clink head,clink *memory)
{
   clink ptr;                     /* 下一节点的指标       */

   if ( head != NULL )            /* 串列是否是空         */
   {
      ptr = head->next;           /* 指向下一节点         */
      head->next = *memory;       /* head指向memory       */
      *memory = ptr;              /* 新的记忆体串列开始   */
   }
}

/* ---------------------------------------- */
/*  主程式:                                 */
/*  使用记忆体管理方式来建立串列和作记忆体  */
/*  释回.                                   */
/* ---------------------------------------- */
void main()
{
   clink head = NULL;             /* 环状链结串列指标     */
   clink memory = NULL;           /* 记忆体管理指标       */
   clink ptr;
   int list[6] = { 1, 2, 3, 4, 5, 6 };   /* 阵列内容      */
   int i;


   /* 用回路建立记忆体串列, 总共7个节点 */
   for ( i = 0; i < 7; i++ )
   {
      /* 配置一个节点记忆体 */
      ptr = ( clink ) malloc(sizeof(cnode));
      if ( !ptr )                 /* 检查记忆体指标       */
         exit(1);
      ptr->next = NULL;
      ptr->data = 100 + i;        /* 建立节点内容         */
      freenode(&memory,ptr);     /* 释回一个节点记忆体   */
   }
   printmemory(memory);          /* 印出记忆体串列       */

   head = createclist(list,&memory,6); /*建立环状链结串列*/
   printclist(head);             /* 印出环状串列         */

   /* 环状链结串列的记忆体释回 */
   freeclist(head,&memory);

   printmemory(memory);          /* 印出记忆体串列       */
}
