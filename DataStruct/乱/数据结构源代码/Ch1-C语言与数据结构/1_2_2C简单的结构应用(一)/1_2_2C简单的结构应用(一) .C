/* ======================================== */
/*    程序实例: 1_2_2c.c                    */
/*    简单的结构应用(一)                    */
/* ======================================== */

int main()
{
   struct score                   /* 成绩结构宣告     */
   {
      int math;                   /* 数学成绩         */
      int english;                /* 英语成绩         */
      int computer;               /* 电脑成绩         */
   };
   struct score chen;             /* 结构变量chen声明 */

   chen.math = 80;                /* 设置chen的成绩   */
   chen.english = 85;
   chen.computer = 83;
   /* 输出成绩 */
   printf("1:  name       math     english    computer \n");
   printf("2:  Chen        %d         %d         %d    \n",
           chen.math,chen.english,chen.computer);

   return 0;
}
