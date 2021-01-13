/* ======================================== */
/*    程式实例: 11_4.c                      */
/*    随机存取档案的快速排序法              */
/* ======================================== */
#include <stdio.h>
#define MAX  8                    /* 最大档案长度     */
#define LEN  sizeof(char)         /* 字元长度         */

/* ---------------------------------------- */
/*  档案读取字元                            */
/* ---------------------------------------- */
char get_char(FILE *fp,long int pos)
{
   char c;

   fseek(fp,LEN*pos,0);           /* 档案中找字元     */
   fread(&c,LEN,1,fp);            /* 从档案中取字元   */
   return c;                      /* 传回字元         */
}

/* ---------------------------------------- */
/*  档案字元交换                            */
/* ---------------------------------------- */
void swap_char(FILE *fp,long int pos1,long int pos2)
{
   char c1,c2;

   fseek(fp,LEN*pos1,0);          /* 找第一个元素     */
   fread(&c1,LEN,1,fp);           /* 取第一个元素     */
   fseek(fp,LEN*pos2,0);          /* 找第二个元素     */
   fread(&c2,LEN,1,fp);           /* 取第二个元素     */

   fseek(fp,LEN*pos1,0);          /* 找第一个元素     */
   fwrite(&c2,LEN,1,fp);          /* 存第二个元素     */
   fseek(fp,LEN*pos2,0);          /* 找第二个元素     */
   fwrite(&c1,LEN,1,fp);          /* 存第一个元素     */
}

/* ---------------------------------------- */
/*  快速排序法的递回处理                    */
/* ---------------------------------------- */
void q_sort(FILE *fp,long int left,long int right)
{
   char partition;                /* 分割元素         */
   int i,j;

   if ( left < right )            /* 是否继续分割     */
   {
      i = left;                   /* 分割的最左       */
      j = right + 1;              /* 分割的最右       */
      partition = get_char(fp,left);  /* 取第一个元素 */
      do {
         do {                     /* 从左往右找       */
            i++;
         } while( get_char(fp,i) < partition );
         do {                     /* 从右往左找       */
            j--;
         } while( get_char(fp,j) > partition );
         if ( i < j )
            swap_char(fp,i,j);    /* 交换资料         */
      } while( i < j );
      swap_char(fp,j,left);       /* 交换资料         */
      q_sort(fp,left,j-1);        /* 快速排序递回呼叫 */
      q_sort(fp,j+1,right);       /* 快速排序递回呼叫 */
   }
}

/* ---------------------------------------- */
/*  快速排序法                              */
/* ---------------------------------------- */
void quick(FILE *fp,int n)
{
   q_sort(fp,0l,( long )n-1);
}

/* ---------------------------------------- */
/*  主程式: 将档案data.txt的资料用快速排序  */
/*  法排序, 然後将结果存入档案result.txt    */
/* ---------------------------------------- */
void main()
{
   FILE *data;                    /* 资料档           */
   FILE *fp;                      /* 主档指标         */
   char c;
   int j;

   data = fopen("data.txt","r");  /* 开启资料档       */
   if ( data == NULL )
   {
      printf("资料档档开启错误! \n");
      exit(0);                    /* 离开             */
   }
   fp = fopen("result.txt","r+"); /* 开启主档         */
   if ( fp == NULL )
      printf("主档开启错误! \n");
   else
   {
      for ( j = 0; j < MAX; j++ ) /* 拷贝资料到主档   */
      {
         c = getc(data);          /* 读取资料         */
         putc(c,fp);              /* 存入资料         */
      }
      fclose(data);               /* 关资料档         */
      rewind(fp);                 /* 重设档案指标     */
      printf("正在处理数据，请稍等. . . \n");
      quick(fp,MAX);              /* 档案的快速排序法 */
      printf("数据处理完成! \n");
      fclose(fp);                 /* 关档             */
   }
}
