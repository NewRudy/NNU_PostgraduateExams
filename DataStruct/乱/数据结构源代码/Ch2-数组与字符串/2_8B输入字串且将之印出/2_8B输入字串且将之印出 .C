/* ======================================== */
/*    程式实例: 2_8b.c                     */
/*    输入字串且将之印出                    */
/* ======================================== */
/* 加结束字符 */

#include <stdio.h>

int main()
{
   char string[100];              /* 字串阵列宣告     */
   char ch;                       /* 输入字元         */
   int i;

   putchar('?');                  /* 列出提示输入讯息 */
   i = 0;
   while ( (ch = getchar()) != '\n' )  /* 输入字元    */
   {
      string[i] = ch;             /* 存入字串内       */
      i++;
   }

   string[i] = '\0';              /* 加结束字元       */
   for ( i = 0; string[i] != '\0'; i++ ) 
      putchar(string[i]);         /* 印出字串内容     */
   putchar('\n');                 /* 换行             */

   return 0;
}
