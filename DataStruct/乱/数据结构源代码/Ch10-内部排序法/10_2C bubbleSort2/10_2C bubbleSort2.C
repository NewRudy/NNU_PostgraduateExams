/* ======================================== */
/*    程序实例: 10_2c.c                    */
/*    冒泡排序法(另一种方法)                */
/* ======================================== */
#include <stdlib.h>
#define MAX  20                   /* 最大字符串长度           */

/* ---------------------------------------- */
/*  冒泡排序法                              */
/* ---------------------------------------- */
// 优化一下循环次数
void bubble(char *string,int count)
{
   int i, j, done;
   char temp;

   j = count; // 优化扫描个数

   done = 0;                      /* 建立变量               */
   while ( !done )
   {
      done = 1;
	  j--;

      for ( i = 0; i < j; i++ ) /* 第二层循环       */
         if ( string[i+1] < string[i] ) /*比较相邻的数组元素*/
         {
            temp = string[i+1];   /* 交换两字符             */
            string[i+1] = string[i];
            string[i] = temp;
            done = 0;             /* 有交换                 */
         }

      if ( !done )
         /* 输出交换后字符串 */
         printf("输出结果: [%s]\n",string);
   }
}

/* ---------------------------------------- */
/*  主程序: 输入字符串後将字符串排序           */
/* ---------------------------------------- */
int main()
{
   char string[MAX];              /* 字符串数组               */
   int count;                     /* 字符串长度               */

   printf("输入要排序的字符串 ==> ");
   gets(string);                  /* 读取字符串               */
   count = strlen(string);        /* 计算字符串长度           */
   bubble(string,count);          /* 冒泡排序法             */
   /* 输出排序后字符串 */
   printf("\n输出排序结果: [%s]\n",string);

   return 0;
}