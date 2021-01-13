/* ======================================== */
/*    程式实例: 3_3.c                     */
/*    链结串列的走访                        */
/* ======================================== */
#include <stdlib.h>

struct llist                      /* 串列结构宣告      */
{
   int num;                       /* 邮寄编号          */
   char name[10];                 /* 邮寄姓名          */
   struct llist *next;            /* 指向下一标签      */
};
typedef struct llist node;        /* 定义新型态        */
typedef node *llink;               /* 定义新型态指标    */

/* ---------------------------------------- */
/*  链结串列的建立                          */
/* ---------------------------------------- */
llink createllist()
{
   llink head;                     /* 串列的开始指标    */
   llink ptr,ptr1;
   int i;

   /* 建立第一个节点 */
   head = ( llink ) malloc(sizeof(node)); /* 配置记忆体 */
   if ( !head )                   /* 检查指标          */
      return NULL;
   printf("输入六项邮寄资料:\n");
   printf("请输入编号 ==> ");
   scanf("%d",&head->num);        /* 读取编号          */
   printf("请输入编号(%d)的姓名 ==> ",head->num);
   scanf("%s",head->name);        /* 读取姓名          */
   head->next = NULL;             /* 设定指标初值      */
   ptr = head;                    /* 将ptr指向串列开始 */

   for ( i = 1; i < 6; i++ )      /* 建立其它节点回路  */
   {
       ptr1 = ( llink ) malloc(sizeof(node));
       if ( !ptr1 )
          return NULL;
       printf("请输入编号 ==> ");
       scanf("%d",&ptr1->num);    /* 读取编号          */
       printf("请输入编号(%d)的姓名 ==> ",ptr1->num);
       scanf("%s",ptr1->name);    /* 读取姓名          */
       ptr1->next = NULL;         /* 设定指标初值      */
       ptr->next = ptr1;          /* 连结节点          */
       ptr = ptr->next;           /* 指向下一节点      */
   }

   return head;
}

/* ---------------------------------------- */
/*  链结串列的节点走访                      */
/* ---------------------------------------- */
llink findnode(llink head,int num)
{
   llink ptr;

   ptr = head;                    /* 指向串列起始      */
   while ( ptr != NULL )          /* 走访串列          */
   {
      if ( ptr->num == num )      /* 找寻编号          */
         return ptr;
      ptr = ptr->next;            /* 指向下一节点      */
   }
   return ptr;
}

/* ---------------------------------------- */
/*  主程式: 输入编号找寻邮寄姓名            */
/* ---------------------------------------- */
int main()
{
   llink head;                     /* 串列的开始指标    */
   llink ptr;
   int num;                       /* 邮寄编号变数      */

   head = createllist();          /* 建立链结串列      */
   if ( !head )                   /* 检查指标          */
   {
      printf("记忆体配置失败! \n");
      exit(1);
   }

   while ( 1 )
   {
      printf("请输入欲找寻的邮寄编号 ==> ");
      scanf("%d",&num);           /* 读取邮寄编号      */
      if ( num != 0 )
      {
         ptr = findnode(head,num);  /* 串列走访        */
         if ( !ptr )              /* 是否找到          */
            printf("没有找到\n");
         else
            printf("  姓名: %s\n",ptr->name);
      }
      else
         exit(1);                 /* 结束离开          */
   }

   return 0;
}
