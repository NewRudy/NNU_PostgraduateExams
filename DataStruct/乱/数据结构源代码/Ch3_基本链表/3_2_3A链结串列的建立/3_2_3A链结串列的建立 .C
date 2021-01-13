/* ======================================== */
/*    程式实例: 3_2_3a.c                    */
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
typedef node *llink;              /* 定义新型态指标    */

int main()
{
   llink head;                     /* 串列的开始指标    */
   llink ptr;
   int i;

   head = ( llink ) malloc(sizeof(node)); /* 配置记忆体 */
   if ( !head )                   /* 检查指标          */
   {
      printf("记忆体配置失败! \n");
      exit(1);
   }
   head->next = NULL;             /* 设定指标初值      */
   ptr = head;                    /* 将ptr指向串列开始 */
   printf("输入六项邮寄资料:\n");

   for ( i = 0; i < 6; i++ )      /* 建立其它节点回路  */
   {
       printf("请输入编号 ==> ");
       scanf("%d",&ptr->num);     /* 读取编号          */
       printf("请输入编号(%d)的姓名 ==> ",ptr->num);
       scanf("%s",ptr->name);     /* 读取姓名          */
       ptr->next = ( llink ) malloc(sizeof(node));
       if ( !ptr->next )
       {
          printf("记忆体配置失败! \n");
          exit(1);
       }
       ptr->next->next = NULL;    /* 设定指标初值      */
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