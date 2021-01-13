/* ======================================== */
/*    程式实例: 9_7.c                       */
/*    插补搜索                              */
/* ======================================== */
#include <stdlib.h>
#define MAX  20                   /* 最大阵列容量         */

struct element                    /* 记录结构宣告         */
{
   int key;                       /* 搜索键值             */
};
typedef struct element record;    /* 结构新型态           */
record data[MAX] = {              /* 结构阵列宣告         */
       2,   5,   7,   9,  17,  21,  25,
      33,  46,  48,  51,  52,  63,  69,
      77,  78,  80,  89,  94,  99 };

/* ---------------------------------------- */
/*  插补搜索                                */
/* ---------------------------------------- */
int intersearch(int n,int key)
{
   if ( key < data[0].key || key > data[n-1].key )
      return -1;                  /* 没有找到             */
   else
      return interfind(key,0,n-1);  /* 递回呼叫         */
}

/* ---------------------------------------- */
/*  插补搜索递回处理                        */
/* ---------------------------------------- */
int interfind(int key,int left,int right)
{
   int next_guess;                /* 下一个可能索引       */
   int offset;                    /* 索引位移             */
   int range;                     /* 键值范围             */
   int index_range;               /* 索引范围             */
   int temp;

   if ( data[left].key == key )   /* 找到了               */
      return left;
   else
      /* 没有找到 */
      if ( left == right ||
           data[left].key == data[right].key )
         return -1;
      else
      {
         index_range = right - left;  /* 计算索引范围     */
         /* 计算键值范围 */
         range = data[right].key - data[left].key;
         offset = key - data[left].key;   /* 计算键值位移 */
         temp = ( offset * index_range )  / range;
         next_guess = left + temp;      /* 下一个可能索引 */
         if ( next_guess == left )      /* 己试过         */
            next_guess++;
         if ( key < data[next_guess].key )
            /* 左边部分递回呼叫插补搜索 */
            return interfind(key,left,next_guess - 1);
         else
            /* 右边部分递回呼叫插补搜索 */
            return interfind(key,next_guess,right);
      }
}

/* ---------------------------------------- */
/*  主程式: 在一个已排序的阵列, 接着输入    */
/*  值用插补搜索来找值.                     */
/* ---------------------------------------- */
void main()
{
   int found;                     /* 是否找到变数         */
   int value;                     /* 搜索值的内容         */

   while ( 1 )                    /* 主回路开始           */
   {
      printf("\n请输入搜索值(0-100) ==> ");
      scanf("%d",&value);         /* 读入搜索值           */
      if ( value != -1 )
      {
         found = intersearch(MAX,value);  /* 呼叫插补搜索 */
         if ( found != -1 )
            printf("找到搜索值:%d[%d]\n",value,found);
         else
            printf("没有找到搜索值:%d\n",value);
      }
      else
         exit(1);                 /* 结束程式             */
   }
}
