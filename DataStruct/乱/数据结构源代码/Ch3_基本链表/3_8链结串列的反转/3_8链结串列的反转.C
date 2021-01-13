/* ======================================== */
/*    程式实例: 3_8.c                     */
/*    链结串列的反转                        */
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
/*  键结串列的列印                          */
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
/*  链结串列的反转                          */
/* ---------------------------------------- */
llink invertllist(llink head)
{
   llink mid,last;

   mid = NULL;                    /* mid是head的前节点 */
   while ( head != NULL )
   {
      last = mid;                 /* last是mid的前节点 */
      mid = head;
      head = head->next;          /* 下一个节点        */
      mid->next = last;           /* mid指向前节点last */
   }
   return mid;
}

/* ---------------------------------------- */
/*  链结串列的记忆体释回                    */
/* ---------------------------------------- */
void freellist(llink head)
{
   llink ptr;

   while ( head != NULL )         /* 走访串列回路      */
   {
      ptr = head;
      head = head->next;          /* 指向下一节点      */
      free(ptr);                  /* 释回节点记忆体    */
   }
}

/* ---------------------------------------- */
/*  主程式: 反转串列                        */
/* ---------------------------------------- */
int main()
{
   int llist1[6] = { 1, 2, 3, 4, 5, 6 };  /* 阵列内容   */
   llink head;                     /* 指向串列开始      */

   head = createllist(llist1,6);   /* 建立串列          */
   if ( !head )
   {
      printf("记忆体配置失败! \n");
      exit(1);
   }
   printf("原来的链表: ");
   printllist(head);              /* 列印原来串列      */
   head = invertllist(head);      /* 反转串列          */
   printf("反转后的链表: ");
   printllist(head);              /* 列印反转後串列    */
   freellist(head);               /* 释回串列记忆体    */

   return 0;
}
