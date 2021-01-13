/* ======================================== */
/*    程序实例: 1_2_2e.c                    */
/*    简单的结构应用(三)                    */
/* ======================================== */

int main()
{
   struct score                   /* 成绩结构声明   */
   {
      int math;                   /* 数学成绩       */
      int english;                /* 英语成绩       */
      int computer;               /* 电脑成绩       */
   };
   typedef struct score node;     /* 定义新类型     */
   node jslin,chen;                /* 结构变量声明   */

   jslin.math = 80;                /* 设置jslin的成绩 */
   jslin.english = 85;
   jslin.computer = 83;
   chen.math = 75;                /* 设置chen的成绩 */
   chen.english = 91;
   chen.computer = 88;
   /* 输出成绩 */
   printf("1:  name       math     english    computer \n");
   printf("2:  JSLin        %d         %d         %d    \n",
           jslin.math,jslin.english,jslin.computer);
   printf("3:  Chen         %d         %d         %d    \n",
           chen.math,chen.english,chen.computer);

   return 0;
}
 