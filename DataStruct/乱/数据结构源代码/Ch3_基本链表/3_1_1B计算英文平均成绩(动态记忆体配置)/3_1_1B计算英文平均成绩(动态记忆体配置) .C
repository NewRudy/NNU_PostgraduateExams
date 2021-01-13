/* ======================================== */
/*    程式实例: 3_1_1b.c                  */
/*    计算英文平均成绩(动态记忆体配置)      */
/* ======================================== */
#include <stdlib.h>

int main()
{
   int *score;                    /* 整数指标宣告 */
   int i;
   int num;                       /* 学生人数     */
   int sum;                       /* 成绩总分变数 */
   float ave;                     /* 平均成绩变数 */

   sum = 0;                       /* 设定总分初值 */
   printf("请输入学生人数 ==> ");
   scanf("%d", &num);              /* 读取学生人数 */
   /* 配置成绩阵列的记忆体 */
   score = (int *) malloc(num * sizeof(int));
   if ( !score )                  /* 检查指标     */
   {
      printf("内存分配失败! \n");
      exit(1);
   }

   for ( i = 0; i < num; i++ )
   {
      printf("请输入英语成绩. ==> ");
      scanf("%d", &score[i]);      /* 读取英文成绩 */
      sum += *(score + i);        /* 计算总分     */
   }

   ave = (float) sum / (float) num;  /* 计算平均  */
   printf("平均成绩: %6.2f \n",ave);

   return 0;
}
