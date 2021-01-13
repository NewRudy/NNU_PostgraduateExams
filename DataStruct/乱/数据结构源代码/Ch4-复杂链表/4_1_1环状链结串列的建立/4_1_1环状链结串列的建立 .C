/* ======================================== */
/*    程式实例: 4_1_1.c                   */
/*    环状链结串列的建立                    */
/* ======================================== */
#include <stdlib.h>

struct clist                      /* 环状串列结构宣告   */
{
   int data;                      /* 节点资料           */
   struct clist *next;            /* 指向下一节点的指标 */
};
typedef struct clist cnode;       /* 环状串列新型态     */
typedef cnode *clink;             /* 环状串列指标新型态 */

/* ---------------------------------------- */
/*  使用阵列值建立环状链结串列              */
/* ---------------------------------------- */
clink createclist(int *array,int len)
{
   clink head;                    /* 环状串列的指标     */
   clink before;                  /* 前一节点的指标     */
   clink new_node;                /* 新节点的指标       */
   int i;

   /* 建立第一个节点 */
   /* 配置节点记忆体 */
   head = ( clink ) malloc(sizeof(cnode));
   if ( !head )                   /* 检查记忆体指标     */
      return NULL;
   head->data = array[0];         /* 建立节点内容       */
   head->next = NULL;             /* 设定指标初值       */
   before = head;                 /* 指向第一个节点     */

   for ( i = 1; i < len; i++ )    /* 用回路建立其它节点 */
   {
      /* 配置节点记忆体 */
      new_node = ( clink ) malloc(sizeof(cnode));
      if ( !new_node )            /* 检查记忆体指标     */
         return NULL;
      new_node->data = array[i];  /* 建立节点内容       */
      new_node->next = NULL;      /* 设定指标初值       */
      before->next = new_node;    /* 将前节点指向新节点 */
      before = new_node;          /* 新节点成为前节点   */
   }
   new_node->next = head;         /* 建立环状链结       */
   return head;                   /* 传回串列起始指标   */
}

/* ---------------------------------------- */
/*  主程式:                                 */
/*  使用阵列的内容来建立环状链结串列        */
/* ---------------------------------------- */
int main()
{
   clink head;                    /* 环状链结串列指标   */
   clink ptr;                     /* 列印用的串列指标   */
   int list[6] = { 9, 7, 3, 4, 5, 6 };   /* 阵列内容    */
   int i;

   head = createclist(list,6);   /* 建立环状链结串列   */
   if ( head == NULL )
   {
      printf("记忆体配置失败! \n");   /* 串列建立失败   */
      exit(1);                    /* 结束程式           */
   }

   printf("数组内容: ");
   for ( i = 0; i < 6; i++ )
      printf("[%d]",list[i]);     /* 列印阵列内容       */

   /* 串列的列印 */
   printf("\n链表内容: ");
   ptr = head;                    /* 指向串列开始       */
   do                             /* 串列走访回路       */
   {
      printf("[%d]",ptr->data);   /* 列印串列内容       */
      ptr = ptr->next;            /* 指向下一个节点     */
   } while ( head != ptr );
   printf("\n");                  /* 换行               */

   return 0;
}
