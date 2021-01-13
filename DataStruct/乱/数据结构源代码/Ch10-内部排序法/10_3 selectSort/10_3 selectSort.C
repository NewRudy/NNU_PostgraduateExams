/* ======================================== */
/*    程序实例: 10_3.c                    */
/*    选择排序法                            */
/* ======================================== */
#include <stdlib.h>
#define MAX  20                   /* 最大字符串长度         */

/* ---------------------------------------- */
/*  选择排序法                              */
/* ---------------------------------------- */
void select(char *string,int count)
{
   int pos;                       /* 目前最小的字符       */
   int i,j;
   char temp;

   for ( i = 0; i < count - 1; i++ )  /* 第一层循环       */
   {
      pos = i;
      temp = string[pos];
      /* 查找最小的字符 */
      for ( j = i + 1; j < count; j++ ) /* 第二层循环    */
         if ( string[j] < temp )        /* 是否更小       */
         {
            pos = j;              /* 新的最小字符         */
            temp = string[j];
         }
      string[pos] = string[i];    /* 交换两字符           */
      string[i] = temp;
      printf("输出结果: [%s]\n",string); /*输出交换后字符串 */
   }
}

/* ---------------------------------------- */
/*  主程序: 输入字符串后将字符串排序           */
/* ---------------------------------------- */
void main()
{
   char string[MAX];              /* 字符串数组            */
   int count;                     /* 字符串长度             */

   printf("输入要排序的字符串 ==> ");
   gets(string);                  /* 读取字符串             */
   count = strlen(string);        /* 计算字符串长度         */
   select(string,count);          /* 选择排序法           */
   /* 输出排序后字符串 */
   printf("\n输出排序结果: [%s]\n",string);
}
