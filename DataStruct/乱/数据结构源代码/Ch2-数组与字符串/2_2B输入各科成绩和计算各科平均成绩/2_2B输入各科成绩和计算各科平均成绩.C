/* ======================================== */
/*    程序实例: 2_2b.c                     */
/*    输入各科成绩和计算各科平均成绩        */
/* ======================================== */

int main()
{
   struct grade                   /* 成绩结构声明     */
   {
      int math;                   /* 数学成绩         */
      int english;                /* 英语成绩         */
      int computer;               /* 电脑成绩         */
   };
   struct grade student[5];       /* 结构数组变量声明 */
   int i;
   int num;                       /* 学生人数         */
   int m_sum,e_sum,c_sum;         /* 各科成绩总分变量 */
   float m_ave,e_ave,c_ave;       /* 各科平均成绩变量 */

   m_sum = e_sum = c_sum = 0;     /* 总分初值         */
   printf("请输入学生人数.(小于5) ==> ");
   scanf("%d",&num);              /* 读取学生人数     */
   for ( i = 0; i < num; i++ )
   {
      printf("学生编号: %d\n",i + 1);
      printf("请输入第 %d 个学生的数学成绩.   ==> ",i + 1);
      scanf("%d",&student[i].math);     /* 读取数学成绩 */
      m_sum += student[i].math;         /* 计算数学总分 */
      printf("请输入第 %d 个学生的英语成绩.   ==> ",i + 1);
      scanf("%d",&student[i].english);  /* 读取英文成绩 */
      e_sum += student[i].english;      /* 计算英文总分 */
      printf("请输入第 %d 个学生的计算机成绩. ==> ",i + 1);
      scanf("%d",&student[i].computer); /* 读取电脑成绩 */
      c_sum += student[i].computer;     /* 计算电脑总分 */
   }
   m_ave = (float) m_sum / (float) num; /* 计算数学平均 */
   e_ave = (float) e_sum / (float) num; /* 计算英语平均 */
   c_ave = (float) c_sum / (float) num; /* 计算电脑平均 */
   printf("数学平均成绩: %6.2f \n",m_ave);
   printf("英语平均成绩: %6.2f \n",e_ave);
   printf("计算机平均成绩: %6.2f \n",c_ave);

   return 0;
}
