/* ======================================== */
/*    程式实例: 9_9_2.c                     */
/*    线性探测法的哈希搜索                  */
/* ======================================== */
#include <stdlib.h>
#include <time.h>
#define MAX    10                 /* 最大阵列容量       */
#define NUM     8                 /* 乱数产生的个数     */
#define BLANK  -1                 /* 空白空间           */

int hashtable[MAX];              /* 哈希表宣告         */

/* ---------------------------------------- */
/*  哈希函数                                */
/* ---------------------------------------- */
int hashfunc(int value)
{
   return value % MAX;            /* 馀数               */
}

/* ---------------------------------------- */
/*  线性探测法                              */
/* ---------------------------------------- */
int linehash(int key)
{
   int pos;                       /* 位置变数           */
   int temp;

   /* 呼叫哈希函数计算位置 */
   pos = hashfunc(key);
   temp = pos;                    /* 保留开始位置       */
   while ( hashtable[temp] != key &&   /* 线性探测回路 */
           hashtable[temp] != BLANK )
   {
      /* 使用馀数将阵列变为环状 */
      temp = ( temp + 1 ) % MAX;  /* 下一个位置         */
      if ( pos == temp )          /* 查询结束           */
         return -1;               /* 没有找到           */
   }
   if ( hashtable[temp] == BLANK )   /* 是否是空白     */
      return -1;                  /* 没有找到           */
   else
      return temp;                /* 找到了             */
}

/* ---------------------------------------- */
/*  建立哈希表                              */
/* ---------------------------------------- */
void createtable(int key)
{
   int pos;                       /* 位置变数           */
   int temp;

   /* 呼叫哈希函数计算位置 */
   pos = hashfunc(key);
   temp = pos;                    /* 保留开始位置       */
   while ( hashtable[temp] != BLANK )  /* 寻找存入位置 */
   {
      temp = ( temp + 1 ) % MAX;  /* 下一个位置         */
      if ( pos == temp )          /* 哈希表是否己满     */
      {
         printf("哈希表己满!\n");
         return;
      }
   }
   hashtable[temp] = key;        /* 存入哈希表         */
}

/* ---------------------------------------- */
/*  主程式: 哈希搜索法.                     */
/* ---------------------------------------- */
void main()
{
   int checked[50];               /* 检查阵列           */
   int i,j,temp;
   long temptime;
   for ( i = 0; i < MAX; i++ )
      hashtable[i] = BLANK;       /* 清除哈希表         */
   for ( i = 0; i < 50; i++ )
      checked[i] = 0;             /* 清除检查阵列       */

   printf("哈希表内容:\n");
   srand(time(&temptime) % 60);   /* 使用时间初始乱数   */
   i = 0;
   while ( i != NUM )             /* 产生阵列值的回路   */
   {
      temp = rand() % 50;         /* 乱数取值 0-49      */
      if ( checked[temp] == 0 )   /* 是否是已有的值     */
      {
         createtable(temp);       /* 建立哈希表         */
         printf("%2d => ",temp);
         for ( j = 0; j < MAX; j++ )  /* 列印哈希表     */
            printf("[%2d]",hashtable[j]);
         printf("\n");            /* 换行               */
         checked[temp] = 1;       /* 设定此值产生过     */
         i++;                     /* 下一个阵列值       */
      }
   }
   while ( 1 )                    /* 主回路开始         */
   {
      printf("\n请输入搜索值(0-49) ==> ");
      scanf("%d",&temp);          /* 读入搜索值         */
      if ( temp != -1 )
      {
         i = linehash(temp);      /* 呼叫哈希搜索       */
         if ( i != -1 )
            printf("找到搜索值:%d[%d]\n",temp,i);
         else
            printf("没有找到搜索值:%d\n",temp);
      }
      else
         exit(1);                 /* 结束程式           */
   }
}
