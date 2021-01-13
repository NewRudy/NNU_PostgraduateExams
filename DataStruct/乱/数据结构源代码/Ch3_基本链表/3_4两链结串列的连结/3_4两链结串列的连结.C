/* ======================================== */
/*    程式实例: 3_4.c                     */
/*    两链结串列的连结                      */
/* ======================================== */
#include <stdlib.h>

struct llist                       /* 串列结构宣告      */
{
   int num;                       /* 邮寄编号          */
   struct llist *next;             /* 指向下一标签      */
};
typedef struct llist node;         /* 定义新型态        */
typedef node *llink;               /* 定义新型态指标    */

/* ---------------------------------------- */
/*  链结串列的列印                          */
/* ---------------------------------------- */
void printllist(llink ptr)
{
   while ( ptr != NULL )          /* 串列走访回路      */
   {
      printf("[%d]",ptr->num);    /* 列印节点资料      */
      ptr = ptr->next;            /* 指向下一节点      */
   }

   printf("\n");                  /* 换行              */
}

/* ---------------------------------------- */
/*  链结串列的建立                          */
/* ---------------------------------------- */
llink createllist(int *array,int len)
{
   llink head;                     /* 串列的开始指标    */
   llink ptr,ptr1;
   int i;

   /* 建立第一个节点 */
   head = ( llink ) malloc(sizeof(node)); /* 配置记忆体 */
   if ( !head )                   /* 检查指标          */
      return NULL;
   head->num = array[0];          /* 建立节点内容      */
   head->next = NULL;             /* 设定指标初值      */
   ptr = head;                    /* 将ptr指向串列开始 */
   for ( i = 1; i < len; i++ )    /* 建立其它节点回路  */
   {
       ptr1 = ( llink ) malloc(sizeof(node));      
       if ( !ptr1 )
          return NULL;
       ptr1->num = array[i];      /* 建立节点内容      */
       ptr1->next = NULL;         /* 设定指标初值      */
       ptr->next = ptr1;          /* 连结节点          */
       ptr = ptr->next;           /* 指向下一节点      */
   }

   return head;
}

/* ---------------------------------------- */
/*  链结串列的连结                          */
/* ---------------------------------------- */
llink concatllist(llink ptr1, llink ptr2)
{
   llink ptr;

   ptr = ptr1;                    /* 指向串列1的开始   */
   while ( ptr->next != NULL )    /* 找串列1的结束     */
      ptr = ptr->next;            /* 指向下一节点      */
   ptr->next = ptr2;              /* 连结串列2         */

   return ptr1;
}

/* ---------------------------------------- */
/*  主程式: 连结两个由阵列内容所建立的串列. */
/* ---------------------------------------- */
int main()
{
   int llist1[6] = { 1, 2, 3, 4, 5, 6 };  /* 阵列内容   */
   int llist2[5] = { 8, 19, 13, 24, 35 }; /* 阵列内容   */
   llink ptr,ptr1,ptr2;

   ptr1 = createllist(llist1,6);   /* 建立串列1         */
   if ( ptr1 == NULL )
   {
      printf("记忆体配置失败! \n");
      exit(1);
   }
   ptr2 = createllist(llist2,5);   /* 建立串列2         */
   if ( ptr2 == NULL )
   {
      printf("记忆体配置失败! \n");
      exit(1);
   }
   ptr = concatllist(ptr1,ptr2);  /* 连结两串列        */
   printllist(ptr);               /* 印出连结串列      */

   return 0;
}
