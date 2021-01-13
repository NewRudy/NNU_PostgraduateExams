/* ======================================== */
/*    程式实例: 9_6.c                       */
/*    费氏数组搜索                          */
/* ======================================== */
#include <stdlib.h>
#define MAX  21                   /* 最大阵列容量         */

struct element                    /* 记录结构宣告         */
{
   int key;                       /* dj寻键值             */
};
typedef struct element record;    /* 结构新型态           */
record data[MAX] = {              /* 结构阵列宣告         */
       2,   5,   7,   9,  17,  21,  25,
      33,  46,  89, 100, 121, 127, 139,
     237, 279, 302, 356, 455, 467, 500  };

/* ---------------------------------------- */
/*  费氏数组 - 计算费氏数                   */
/* ---------------------------------------- */
int fib(int n)
{
   if ( n <= 1 )                  /* N 是否小於壹         */
      return n;                   /* 传回N                */
   else
      return fib(n-2) + fib(n-1); /* 递回计算费氏数       */
}

/* ---------------------------------------- */
/*  计算费氏数组的 n 值当 Fn <= n + 1       */
/* ---------------------------------------- */
int fibindex(int n)
{
   int temp;

   temp = 1;                      /* 建定temp值           */
   while ( fib(temp) <= n + 1 )   /* 比较回路             */
      temp++;                     /* 如果成立temp加一     */
   return temp - 1;               /* 传回n                */
}

/* ---------------------------------------- */
/*  费氏数组搜索                            */
/* ---------------------------------------- */
int fibsearch(int n,int key)
{
   int index;                     /* 费氏数的n值          */
   int mid;                       /* 费氏数的变数         */
   int fn1;                       /* 前一个费氏数         */
   int fn2;                       /* 前二个费氏数         */
   int temp;

   index = fibindex(n + 1);       /* 计算Fn <= n + 1      */
   mid = fib(index - 1);          /* 起始的费氏数         */
   fn1 = fib(index - 2);          /* 前一个费氏数         */
   fn2 = fib(index - 3);          /* 前二个费氏数         */
   while ( mid != 0 )             /* 费氏搜索主回路       */
   {
      if ( key < data[mid-1].key )  /* 比较小             */
         if ( fn2 <= 0 )
            mid = 0;              /* 没有找到             */
         else
         {
            mid = mid - fn2;      /* 左子树新费氏数       */
            temp = fn1;
            fn1 = fn2;            /* 前一个费氏数         */
            fn2 = temp - fn2;     /* 前二个费氏数         */
         }
      else
         if ( key > data[mid-1].key ) /* 比较大           */
            if ( fn1 <= 1 )
               mid = 0;           /* 没有找到             */
            else
            {
               mid = mid + fn2;   /* 右子树新费氏数       */
               fn1 = fn1 - fn2;   /* 前一个费氏数         */
               fn2 = fn2 - fn1;   /* 前二个费氏数         */
            }
         else
            return mid - 1;       /* 找到了               */
   }
   return -1;                     /* 没有找到             */
}

/* ---------------------------------------- */
/*  主程式: 在一个已排序的阵列, 接着输入    */
/*  值用费氏数组搜索来找值.                 */
/* ---------------------------------------- */
void main()
{
   int found;                     /* 是否找到变数         */
   int value;                     /* 搜索值的内容         */

   while ( 1 )                    /* 主回路开始           */
   {
      printf("\n请输入搜索值(0-500) ==> ");
      scanf("%d",&value);         /* 读入搜索值           */
      if ( value != -1 )
      {
         found = fibsearch(MAX,value);  /*呼叫费氏数组搜索*/
         if ( found != -1 )
            printf("找到搜索值:%d[%d]\n",value,found);
         else
            printf("没有找到搜索值:%d\n",value);
      }
      else
         exit(1);                 /* 结束程式             */
   }
}
