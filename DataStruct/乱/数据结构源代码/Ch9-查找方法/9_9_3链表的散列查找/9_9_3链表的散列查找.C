/* ======================================== */
/*    程序实例: 9_9_3.c                     */
/*    链表的散列查找                    */
/* ======================================== */
#include <stdlib.h>
#include <time.h>
#define MAX    10                 /* 最大数组容量     */
#define NUM    10                 /* 随机数产生的个数   */

struct list                       /* 链表结构声明     */
{
   int key;                       /* 键值             */
   struct list *next;             /* 指向下一结点     */
};
typedef struct list node;         /* 定义新类型       */
typedef node *link;               /* 定义新类型指针   */

node hashtable[MAX];              /* 散列表声明       */

/* ---------------------------------------- */
/*  散列函数                                */
/* ---------------------------------------- */
int hashfunc(int value)
{
   return value % MAX;            /* 余数             */
}

/* ---------------------------------------- */
/*  链表的散列查找                      */
/* ---------------------------------------- */
int linkhash(int key)
{
   link ptr;                      /* 开始指针         */
   int pos;                       /* 位置变量         */

   /* 调用散列函数计算位置 */
   pos = hashfunc(key);
   ptr = hashtable[pos].next;     /* 取得开始指针     */
   while ( ptr != NULL )          /* 线性探测回路     */
      if ( ptr->key == key )      /* 是否找到了       */
         return 1;
      else
         ptr = ptr->next;         /* 下一个节点       */
   return 0;
}

/* ---------------------------------------- */
/*  建立散列表                              */
/* ---------------------------------------- */
void createtable(int key)
{
   link ptr;                      /* 开始指针         */
   link new;                      /* 串列的开始指针   */
   int pos;                       /* 位置变数         */

   /* 建立一个节点 */
   new = ( link ) malloc(sizeof(node)); /* 配置记忆体 */
   new->key = key;                /* 存入散列表       */
   new->next = NULL;              /* 建立指针初值     */

   /* 呼叫散列函数计算位置 */
   pos = hashfunc(key);
   ptr = hashtable[pos].next;     /* 取得开始指针     */
   if ( ptr != NULL )             /* 寻找存入位置     */
   {
      new->next = ptr;            /* 插入节点         */
      hashtable[pos].next = new; /* 链结节点         */
   }
   else
      hashtable[pos].next = new; /* 链结节点         */
}

/* ---------------------------------------- */
/*  主程序: 散列查找法.                     */
/* ---------------------------------------- */
void main()
{
   link ptr;                      /* 开始指针         */
   int checked[50];               /* 检查数组         */
   int i,temp;
   long temptime;
   for ( i = 0; i < MAX; i++ )
      hashtable[i].next = NULL;   /* 清除散列表       */
   for ( i = 0; i < 50; i++ )
      checked[i] = 0;             /* 清除检查数组     */

   srand(time(&temptime) % 60);   /* 使用时间初始随机数 */
   i = 0;
   while ( i != NUM )             /* 产生数组值的回路 */
   {
      temp = rand() % 50;         /* 随机数取值 0-49    */
      if ( checked[temp] == 0 )   /* 是否是已有的值   */
      {
         createtable(temp);       /* 建立散列表       */
         checked[temp] = 1;       /* 设定此值产生过   */
         i++;                     /* 下一个数组值     */
      }
   }
   printf("散列表内容:\n");
   for ( i = 0; i < MAX; i++ )    /* 列印结构数组     */
   {
      printf("\n%2d ==> ",i);
      ptr = hashtable[i].next;   /* 取得开始指针     */
      while ( ptr != NULL )       /* 列印串列回路     */
      {
         printf("[%2d]",ptr->key);  /* 印出内容       */
         ptr = ptr->next;         /* 下一节点         */
      }
   }
   while ( 1 )                    /* 主回路开始       */
   {
      printf("\n请输入查找值(0-49) ==> ");
      scanf("%d",&temp);          /* 读入查找值       */
      if ( temp != -1 )
      {
         i = linkhash(temp);      /* 呼叫散列查找     */
         if ( i != 0 )
            printf("找到查找值:%d\n",temp);
         else
            printf("没有找到查找值:%d\n",temp);
      }
      else
         exit(1);                 /* 结束程序         */
   }
}
