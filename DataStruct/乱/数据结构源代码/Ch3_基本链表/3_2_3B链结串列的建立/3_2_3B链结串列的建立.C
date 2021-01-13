/* ======================================== */
/*    程式实例: 3_2_3b.c                  */
/*    链结串列的建立                        */
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

int main()
{
   llink head;                     /* 串列的开始指标    */
   llink ptr,ptr1;
   int i;

   /* 建立第一个节点 */
   head = ( llink ) malloc(sizeof(node)); /* 配置记忆体 */
   if ( !head )                   /* 检查指标          */
   {
      printf("记忆体配置失败! \n");
      exit(1);
   }

   printf("输入六项邮寄资料:\n");
   printf("请输入编号 ==> ");
   scanf("%d",&head->num);        /* 读取编号          */
   printf("请输入编号(%d)的姓名 ==> ",ptr->num);
   scanf("%s",head->name);        /* 读取姓名          */
   head->next = NULL;             /* 设定指标初值      */
   ptr = head;                    /* 将ptr指向串列开始 */

   for ( i = 1; i < 6; i++ )      /* 建立其它节点回路  */
   {
       ptr1 = ( llink ) malloc(sizeof(node));
       if ( !ptr1 )
       {
          printf("记忆体配置失败! \n");
          exit(1);
       }

       printf("请输入编号 ==> ");
       scanf("%d",&ptr1->num);    /* 读取编号          */
       printf("请输入编号(%d)的姓名 ==> ",ptr1->num);
       scanf("%s",ptr1->name);    /* 读取姓名          */
       ptr1->next = NULL;         /* 设定指标初值      */
       ptr->next = ptr1;          /* 连结节点          */
       ptr = ptr->next;           /* 指向下一节点      */
   }

   printf("邮寄资料:\n");         /* 印出资料内容      */
   ptr = head;                    /* 将ptr指向串列开始 */
   for ( i = 0; i < 6; i++ )      /* 列印回路          */
   {
      printf("编号: %d\n",ptr->num);
      printf("  姓名: %s\n",ptr->name);
      ptr = ptr->next;            /* 指向下一节点      */
   }

   return 0;
}
