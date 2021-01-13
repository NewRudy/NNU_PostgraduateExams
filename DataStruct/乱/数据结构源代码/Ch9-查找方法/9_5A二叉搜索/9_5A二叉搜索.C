/* ======================================== */
/*    程式实例: 9_5a.c                      */
/*    二叉搜索                              */
/* ======================================== */
#include <stdlib.h>
#define MAX  21                   /* 最大阵列容量       */

struct element                    /* 记录结构宣告       */
{
   int key;                       /* 搜索键值           */
};
typedef struct element record;    /* 结构新型态         */
record data[MAX] = {              /* 结构阵列宣告       */
       2,   5,   7,   9,  17,  21,  25,
      33,  46,  89, 100, 121, 127, 139,
     237, 279, 302, 356, 455, 467, 500  };

/* ---------------------------------------- */
/*  二叉搜索                                */
/* ---------------------------------------- */
int binarysearch(int key)
{
   int low;                       /* 阵列开始变数       */
   int high;                      /* 阵列结束变数       */
   int mid;                       /* 阵列中间变数       */

   low = 0;                       /* 阵列开始           */
   high = MAX - 1;                /* 阵列结束           */
   while ( low <= high )          /* 二叉搜索主回路     */
   {
      mid = ( low + high ) / 2;   /* 计算阵列中间值     */
      if ( key < data[mid].key )  /* 比较小             */
         high = mid - 1;          /* 前一半             */
      else
         if ( key > data[mid].key )   /* 比较大         */
            low = mid + 1;        /* 后一半             */
         else
            return mid;           /* 找到了             */
   }
   return -1;                     /* 没有找到           */
}

/* ---------------------------------------- */
/*  主程式: 在一个已排序的阵列, 接着输入    */
/*  值用二叉搜索来找值.                     */
/* ---------------------------------------- */
void main()
{
   int found;                     /* 是否找到变数       */
   int value;                     /* 搜索值的内容       */

   while ( 1 )                    /* 主回路开始         */
   {
      printf("\n请输入搜索值(0-500) ==> ");
      scanf("%d",&value);         /* 读入搜索值         */
      if ( value != -1 )
      {
         found = binarysearch(value);   /* 呼叫二叉搜索 */
         if ( found != -1 )
            printf("找到搜索值:%d[%d]\n",value,found);
         else
            printf("没有找到搜索值:%d\n",value);
      }
      else
         exit(1);                 /* 结束程式           */
   }
}
