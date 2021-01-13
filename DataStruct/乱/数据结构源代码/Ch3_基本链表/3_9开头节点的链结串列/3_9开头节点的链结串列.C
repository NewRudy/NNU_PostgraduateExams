/* ======================================== */
/*    程式实例: 3_9.c                                                     */
/*    开头节点的链结串列                                            */
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
void printllist(llink head)
{
   llink ptr;

   ptr = head->next;              /* 指向真正的起始    */
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

   /* 建立开头节点 */
   head = ( llink ) malloc(sizeof(node)); /* 配置记忆体 */
   if ( !head )                   /* 检查指标          */
      return NULL;
   ptr = head;                    /* 将ptr指向串列开始 */
   for ( i = 0; i < len; i++ )    /* 建立其它节点回路  */
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
/*  链结串列的节点插入                      */
/* ---------------------------------------- */
llink insertnode(llink head,llink ptr,int value)
{
   llink new;                      /* 新节点指标变数    */

   new = ( llink ) malloc(sizeof(node));  /* 建立新节点 */
   if ( !new )
      return NULL;
   new->num = value;              /* 建立节点内容      */
   new->next = NULL;              /* 设定指标初值      */
   /* 如果ptr等於开头节点则是插入第一个节点 */
   new->next = ptr->next;        /* 新节点指向下一节点 */
   ptr->next = new;               /* 节点ptr指向新节点 */
   return head;
}

/* ---------------------------------------- */
/*  链结串列的节点删除                      */
/* ---------------------------------------- */
llink deletenode(llink head,llink ptr)
{
   llink previous;

   previous = head;
   while ( previous->next != ptr ) /* 找节点ptr前一节点 */
      previous = previous->next;
   previous->next = ptr->next;    /* 删除中间节点      */
   free(ptr);                     /* 释回节点记忆体    */
   return head;
}

/* ---------------------------------------- */
/*  主程式: 开头节点插入删除操作.           */
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
   head = insertnode(head,head,0); /* 插入新节点      */

   if ( !head )
   {
      printf("记忆体配置失败! \n");
      exit(1);
   }
   /* 删除串列内节点 */
   head = deletenode(head,head->next->next->next);
   printf("最后的链表: ");
   printllist(head);              /* 列印结果串列      */

   return 0;
}
