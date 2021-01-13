/* ======================================== */
/*    程式实例: 3_2_2.c                   */
/*    动态资料结构的宣告和记忆体处理        */
/* ======================================== */
#include <stdlib.h>

struct llist                      /* 串列结构宣告     */
{
   int num;                       /* 邮寄编号         */
   char name[10];                 /* 邮寄姓名         */
   char address[50];              /* 邮寄地址         */
   struct llist *next;            /* 指向下一标签     */
};
typedef struct llist node;        /* 定义新型态       */
typedef node *llink;              /* 定义新型态指标   */

int main()
{
   llink ptr;

   ptr = ( llink ) malloc(sizeof(node)); /* 配置记忆体 */
   if ( !ptr )                    /* 检查指标         */
   {
      printf("记忆体配置失败! \n");
      exit(1);
   }

   printf("请输入编号 ==> ");
   scanf("%d",&ptr->num);         /* 读取编号         */
   printf("请输入姓名 ==> ");
   scanf("%s",ptr->name);         /* 读取姓名         */
   printf("请输入地址 ==> ");
   scanf("%s",ptr->address);      /* 读取地址         */
   ptr->next = NULL;              /* 设定指标初值   ?  */

   printf("\n邮寄资料:\n");
   printf("编号: %d\n",ptr->num); /* 印出资料项       */
   printf("姓名: %s\n",ptr->name);
   printf("地址: %s\n",ptr->address);

   return 0;
}
