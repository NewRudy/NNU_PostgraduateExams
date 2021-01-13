/* ======================================== */
/*    程序实例: 1_2_3a.c                    */
/*    结构指针的应用                        */
/* ======================================== */
#include <stdlib.h>

int main()
{
   struct score                   /* 成绩结构声明     */
   {
      char id;                    /* 学生学号         */
      int math;                   /* 数学成绩         */
      int english;                /* 英语成绩         */
      int computer;               /* 电脑成绩         */
      struct score *next;
   };
   typedef struct score node;     /* 定义新类型     */
   node first,second;             /* 结构变量声明    */
   node *begin;                   /* 结构指针变量声明*/

   first.id = 'C';                /* 设置first的成绩  */
   first.math = 80;
   first.english = 85;
   first.computer = 83;
   first.next = NULL;             /* 初始结构指针     */
   second.id = 'A';               /* 设置second的成绩 */
   second.math = 75;
   second.english = 91;
   second.computer = 88;
   second.next = NULL;            /* 初始结构指针     */

   first.next = &second;          /* 连接两个结构指针 */
   begin = &first;

   printf("  id       math     english    computer \n");
   while ( begin != NULL )        /* 打印所连接的结构 */
   {
      printf("  %c        %d         %d         %d    \n",
              begin->id,begin->math,begin->english,begin->computer);
      begin = begin->next;               /* 下一个结构 */
   }

   return 0;
}
