/* ======================================== */
/*    程序实例: 2_2a.c                     */
/*    输入英语成绩和计算平均成绩            */
/* ======================================== */
#include<stdio.h>

int main()
{
   int score[10];                 /* 学生成绩阵列 */
   int i;
   int num;                       /* 学生人数     */
   int sum;                       /* 成绩总分变量 */
   float ave;                     /* 平均成绩变量 */

   sum = 0;                       /* 设置总分初值 */
   printf("请输入学生人数.(小於10) ==> ");
   scanf("%d",&num);              /* 读取学生人数 */
   for ( i = 0; i < num; i++ )
   {
      printf("请输入第%d个学生的英语成绩. ==> ",i+1);
      scanf("%d",&score[i]);      /* 读取英语成绩 */
      sum += score[i];            /* 计算总分     */
   }
   ave = (float) sum / (float) num;   /* 计算平均分 */
   printf("平均成绩: %6.2f \n",ave);

   return 0;
}