/* ======================================== */
/*    程式实例: 2_8d.c                     */
/*    输入字串且将之印出                    */
/* ======================================== */
#include <stdio.h>

int main()
{
   char string[100];              /* 字串阵列宣告      */
   char ch;                       /* 输入字元          */
   int i;

   putchar('?');                  /* 列出提示输入讯息  */
   i = 1;                         /* 从第二个元素开始  */
   while ( (ch = getchar()) != '\n' )  /* 输入字元     */
   {
      string[i] = ch;             /* 存入字串内        */
      i++;
   }

   string[0] = i - 1;             /* 存入字串长度      */

   for ( i = 1; i <= string[0]; i++ )  /* 印出字串内容 */
      putchar(string[i]);
   putchar('\n');                 /* 换行              */

   return 0;
}
