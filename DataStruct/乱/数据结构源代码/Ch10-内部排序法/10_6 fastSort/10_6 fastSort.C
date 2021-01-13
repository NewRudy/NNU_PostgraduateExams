/* ======================================== */
/*    程序实例: 10_6.c                      */
/*    快速排序法                            */
/* ======================================== */
#include <stdlib.h>
#define MAX  20                   /* 最大字符串长度       */

/* ---------------------------------------- */
/*  快速排序法的递归处理                    */
/* ---------------------------------------- */
void q_sort(char *string,int left,int right)
{
   char partition;                /* 分割元素           */
   char temp;
   int i,j,k;

   if ( left < right )            /* 是否继续分割       */
   {
      i = left;                   /* 分割的最左         */
      j = right + 1;              /* 分割的最右         */
      partition = string[left];   /* 取第一个元素       */
      do {
         do {                     /* 从左往右找         */
            i++;
         } while( string[i] < partition );
         do {                     /* 从右往左找         */
            j--;
         } while( string[j] > partition );
         if ( i < j )
         {
            temp = string[i];     /* 交换数据           */
            string[i] = string[j];
            string[j] = temp;
         }
      } while( i < j );
      temp= string[left];         /* 交换数据           */
      string[left] = string[j];
      string[j] = temp;
      printf("输出结果: ");
      for ( k = left; k <= right; k++)  /* 输出处理字符串 */
         printf("%c",string[k]);
      printf("\n");               /* 换行               */
      q_sort(string,left,j-1);    /* 快速排序递归调用   */
      q_sort(string,j+1,right);   /* 快速排序递归调用   */
   }
}

/* ---------------------------------------- */
/*  快速排序法                              */
/* ---------------------------------------- */
void quick(char *string,int n)
{
   q_sort(string,0,n-1);
}

/* ---------------------------------------- */
/*  主程序: 输入字符串后将字符串排序           */
/* ---------------------------------------- */
void main()
{
   char string[MAX];              /* 字符串阵列           */
   int count;                     /* 字符串长度           */

   printf("输入要排序的字符串 ==> ");
   gets(string);                  /* 读取字符串           */
   count = strlen(string);        /* 计算字符串长度       */
   quick(string,count);           /* 快速排序法         */
   /* 输出排序后字符串 */
   printf("\n输出排序结果: [%s]\n",string);
}
