/* ======================================== */
/*    程式实例: 11_3.c                      */
/*    直接合并排序                          */
/* ======================================== */
#include <stdio.h>
#define LEN  8                    /* 最大元素个数         */

/* ---------------------------------------- */
/*  直接合并排序                            */
/* ---------------------------------------- */
void merge_sort(FILE *merge,FILE *sort1,FILE *sort2,int len)
{
   int s1,s2;                     /* 资料计数             */
   int i,j,k;
   char c,c1,c2;

   for ( i = 1; i < len; i *= 2 )
   {
      /* 分割档案 */
      for ( j = 0; j < len / 2; j++ ) /* 分到档案一       */
      {
         c = getc(merge);
         putc(c,sort1);
      }
      for ( ; j < len; j++ )      /* 分到档案二           */
      {
         c = getc(merge);
         putc(c,sort2);
      }
      rewind(merge);              /* 重设档案指标         */
      rewind(sort1);
      rewind(sort2);
      for ( k = 0; k < len / 2; k += i )  /* 合并回路     */
      {
         c1 = getc(sort1);        /* 读取第一分割档       */
         c2 = getc(sort2);        /* 读取第二分割档       */
         s1 = s2 = 0;             /* 设定计数初值         */
         while ( 1 )
         {
            if ( c1 < c2 )        /* 比较两个值           */
            {
               /* 第一分割档小, 存入主档 */
               putc(c1,merge);
               s1++;              /* 计数加一             */
               if ( s1 < i )      /* 是否未读完           */
                  c1 = getc(sort1);   /* 读取第一分割档   */
               else
                  break;          /* 跳出回路             */
            }
            else
            {
               /* 第二分割档小, 存入主档 */
               putc(c2,merge);
               s2++;              /* 计数加一             */
               if ( s2 < i )      /* 是否未读完           */
                  c2 = getc(sort2);   /* 读取第一分割档   */
               else
                  break;          /* 跳出回路             */
            }
         }
         /* 第一分割档是否是最後一笔 */
         if ( s1 < i )            /* 处理最後一笔         */
         {
            putc(c1,merge);       /* 存入主档             */
            s1++;                 /* 计数加一             */
         }
         /* 第二分割档是否是最後一笔 */
         if ( s2 < i )            /* 处理最後一笔         */
         {
            putc(c2,merge);       /* 存入主档             */
            s2++;                 /* 计数加一             */
         }
         /* 第一分割档 */
         while ( s1 < i )         /* 取出剩下的资料       */
         {
            c = getc(sort1);      /* 读取第一分割档       */
            putc(c,merge);        /* 存入主档             */
            s1++;                 /* 计数加一             */
         }
         /* 第二分割档 */
         while ( s2 < i )         /* 取出剩下的资料       */
         {
            c = getc(sort2);      /* 读取第二分割档       */
            putc(c,merge);        /* 存入主档             */
            s2++;                 /* 计数加一             */
         }
      }
      rewind(merge);              /* 重设档案指标         */
      rewind(sort1);
      rewind(sort2);
   }
}

/* ---------------------------------------- */
/*  主程式: 读取两个档案内容, 接着用直接合  */
/*  并排序法来排序.                         */
/* ---------------------------------------- */
void main()
{
   FILE *data;                    /* 资料档               */
   FILE *fp;                      /* 主档指标             */
   FILE *fp1;                     /* 第一分割档案指标     */
   FILE *fp2;                     /* 第二分割档案指标     */
   char c;
   int j;

   data = fopen("data.txt","r");  /* 开启资料档           */
   if ( data == NULL )
   {
      printf("资料档档开启错误! \n");
      exit(0);                    /* 离开                 */
   }
   fp = fopen("result.txt","r+"); /* 开启主档             */
   if ( fp == NULL )
      printf("主档开启错误! \n");
   else
   {
      for ( j = 0; j < LEN; j++ ) /* 拷贝资料到主档       */
      {
         c = getc(data);          /* 读取资料             */
         putc(c,fp);              /* 存入资料             */
      }
      fclose(data);               /* 关资料档             */
      rewind(fp);                 /* 重设档案指标         */
      fp1 = fopen("split1.txt","r+"); /* 开启第一分割档案 */
      if ( fp1 == NULL )
         printf("第一分割档开启错误! \n");
      else
      {
         fp2 = fopen("split2.txt","r+"); /*开启第二分割档案*/
         if ( fp2 == NULL )
            printf("第二分割档开启错误! \n");
         else
         {
            printf("正在处理数据，请稍等. . . \n");
            merge_sort(fp,fp1,fp2,LEN);  /* 直接合并排序法 */
            printf("数据处理完成! \n");
            fclose(fp);                  /* 关档           */
            fclose(fp1);
            fclose(fp2);
         }
      }
   }
}
