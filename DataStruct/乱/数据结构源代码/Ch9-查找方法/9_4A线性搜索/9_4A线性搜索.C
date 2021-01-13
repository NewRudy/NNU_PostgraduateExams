/* ======================================== */
/*    程式实例: 9_4a.c                      */
/*    线性搜索                              */
/* ======================================== */
#include <stdlib.h>
#include <time.h>
#define MAX  100                  /* 最大阵列容量     */

struct element                    /* 记录结构宣告     */
{
   int key;                       /* 搜索键值         */
};
typedef struct element record;    /* 结构新型态       */
record data[MAX];                 /* 结构阵列宣告     */

/* ---------------------------------------- */
/*  线性搜索                                */
/* ---------------------------------------- */
int seq_search(int key)
{
   int pos;                       /* 阵列索引         */

   pos = 0;                       /* 从头开始找       */
   while ( pos < MAX )            /* 线性搜索主回路   */
   {
      if ( key == data[pos].key ) /* 是否找到         */
         return pos;
      pos ++;                     /* 下一个元素       */
   }
   return -1;
}

/* ---------------------------------------- */
/*  主程式: 用乱数来产生阵列元素, 接着输入  */
/*  值用线性搜索来找值.                     */
/* ---------------------------------------- */
void main()
{
   int checked[300];              /* 检查阵列         */
   int i,temp;
   long temptime;
   srand(time(&temptime) % 60);   /* 使用时间初始乱数 */
   for ( i = 0; i < 300; i++ )
      checked[i] = 0;             /* 清除检查阵列     */
   i = 0;
   while ( i != MAX )             /* 产生阵列值的回路 */
   {
      temp = rand() % 300;        /* 乱数取值 0-299   */
      if ( checked[temp] == 0 )   /* 是否是已有的值   */
      {
         data[i].key = temp;      /* 存入阵列中       */
         checked[temp] = 1;       /* 设定此值产生过   */
         i++;                     /* 下一个阵列值     */
      }
   }
   while ( 1 )                    /* 主回路开始       */
   {
      printf("\n请输入搜索值(0-299) ==> ");
      scanf("%d",&temp);          /* 读入搜索值       */
      if ( temp != -1 )
      {
         i = seq_search(temp);    /* 呼叫线性搜索     */
         if ( i != -1 )
            printf("找到搜索值:%d[%d]\n",temp,i);
         else
            printf("没有找到搜索值:%d\n",temp);
      }
      else
         exit(1);                 /* 结束程式         */
   }
}
