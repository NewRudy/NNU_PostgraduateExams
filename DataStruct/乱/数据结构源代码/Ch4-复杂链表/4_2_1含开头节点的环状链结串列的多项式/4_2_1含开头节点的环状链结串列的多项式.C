/* ======================================== */
/*    程式实例: 4_2_1.c                     */
/*    含开头节点的环状链结串列的多项式      */
/* ======================================== */
#include <stdlib.h>

struct plist                      /* 多项式结构宣告       */
{
   int coef;                      /* 多项式的系数         */
   int exp;                       /* 多项式的指数         */
   struct plist *next;            /* 指向下一节点的指标   */
};
typedef struct plist pnode;       /* 多项式新型态         */
typedef pnode *plink;             /* 多项式指标新型态     */

/* ---------------------------------------- */
/*  多项式含开头节点的环状链结串列的列印    */
/* ---------------------------------------- */
void printpoly(plink poly)
{
   plink ptr;

   ptr = poly->next;              /* 指向串列开始         */
   while ( poly != ptr )          /* 串列走访回路         */
   {
      /* 列印节点资料 */
      printf("%dX^%d",ptr->coef,ptr->exp);
      ptr = ptr->next;            /* 指向下一个节点       */
      if ( poly != ptr)
         printf("+");
   }
   printf("\n");                  /* 换行                 */
}

/* ---------------------------------------- */
/*  使用阵列值建立多项式                    */
/* ---------------------------------------- */
plink createpoly(int *array,int len)
{
   plink head;                    /* 环状串列的指标       */
   plink before;                  /* 前一节点的指标       */
   plink new_node;                /* 新节点的指标         */
   int i;

   /* 建立开头节点 */
   /* 配置节点记忆体 */
   head = ( plink ) malloc(sizeof(pnode));
   if ( !head )                   /* 检查记忆体指标       */
      return NULL;
   head->exp = -1;                /* 建立节点内容         */
   before = head;                 /* 指向第一个节点       */

   for ( i = len - 1; i >= 0; i-- ) /* 用回路建立其它节点 */
      if ( array[i] != 0 )
      {
         /* 配置节点记忆体 */
         new_node = ( plink ) malloc(sizeof(pnode));
         if ( !new_node )         /* 检查记忆体指标       */
            return NULL;
         new_node->coef = array[i]; /* 建立系数内容       */
         new_node->exp = i;       /* 建立指数内容         */
         new_node->next = NULL;   /* 设定指标初值         */
         before->next = new_node; /* 将前节点指向新节点   */
         before = new_node;       /* 新节点成为前节点     */
      }
   new_node->next = head;         /* 建立环状链结         */

   return head;                   /* 传回串列起始指标     */
}

/* ---------------------------------------- */
/*  多项式相加                              */
/* ---------------------------------------- */
plink polyadd(plink poly1,plink poly2)
{
   plink head1;                   /* 多项式1的开始        */
   plink head2;                   /* 多项式2的开始        */
   plink result;                  /* 多项式的结果         */
   plink before;                  /* 前一节点的指标       */
   plink new_node;                /* 新节点的指标         */

   head1 = poly1->next;           /* 指向多项式1的开始    */
   head2 = poly2->next;           /* 指向多项式2的开始    */

   /* 建立开头节点且配置节点记忆体 */
   result = ( plink ) malloc(sizeof(pnode));
   if ( !result )                 /* 检查记忆体指标       */
      return NULL;
   result->exp = -1;              /* 建立节点内容         */
   before = result;               /* 指向第一个节点       */

   while ( poly1 != head1 || poly2 != head2 )
   {
      /* 配置节点记忆体 */
      new_node = ( plink ) malloc(sizeof(pnode));
      if ( !new_node )            /* 检查记忆体指标       */
         return NULL;
      if ( head1->exp < head2->exp )  /* 多项式2的指数大  */
      {
         new_node->coef = head2->coef;  /* 设定系数       */
         new_node->exp = head2->exp;    /* 设定指数       */
         head2 = head2->next;     /* 指向下一节点         */
      }
      else
         if ( head1->exp > head2->exp ) /*多项式1的指数大 */
         {
            new_node->coef = head1->coef; /* 设定系数     */
            new_node->exp = head1->exp;   /* 设定指数     */
            head1 = head1->next;  /* 指向下一节点         */
         }
         else                     /* 多项式的指数相等     */
         {
            /* 系数相加 */
            new_node->coef = head1->coef + head2->coef;
            new_node->exp = head1->exp;  /* 设定指数      */
            head1 = head1->next;  /* 指向下一节点         */
            head2 = head2->next;  /* 指向下一节点         */
         }
      before->next = new_node;    /* 将前节点指向新节点   */
      before = new_node;          /* 新节点成为前节点     */
   }
   new_node->next = result;       /* 建立环状链结         */

   return result;                 /* 传回多项式的指标     */
}

/* ---------------------------------------- */
/*  主程式: 多项式相加                      */
/* ---------------------------------------- */
void main()
{
   plink poly1;                   /* 多项式1的指标        */
   plink poly2;                   /* 多项式2的指标        */
   plink result;                  /* 多项式结果的指标     */
   int list1[6] = { 4, 0, 3, 0, 7, 0 };  /* 阵列1内容     */
   int list2[6] = { 9, 7, 1, 0, 5, 6 };  /* 阵列2内容     */

   poly1 = createpoly(list1,6);  /* 建立多项式1          */
   printf("多项式1内容:    ");
   printpoly(poly1);             /* 印出多项式1          */
   poly2 = createpoly(list2,6);  /* 建立多项式2          */
   printf("多项式2内容:    ");
   printpoly(poly2);             /* 印出多项式2          */

   result = polyadd(poly1,poly2);  /* 多项式相加         */
   printf("多项式相加结果: ");
   printpoly(result);            /* 印出多项式结果       */
}
