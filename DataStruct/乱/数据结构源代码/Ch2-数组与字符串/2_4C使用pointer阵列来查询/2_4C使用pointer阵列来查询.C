/* ======================================== */
/*    程式实例: 2_4c.c                     */
/*    使用pointer阵列来查询                */
/*    由值索引索引                           */
/* ======================================== */

int main()
{
   int score[10] = { 76, 85, 90, 67, 59, 79, 82,
                     95, 91, 65 }; /* 学生成绩阵列      */
   int pointer[101];               /* 指标阵列          */
   int index;                      /* 阵列索引变数      */
   int grade;                      /* 学生成绩变数      */
   int i;

   /* 第一部分:建立指标阵列 */
   for ( i = 0; i <= 101; i++ )
      pointer[i] = -1;             /* 设定阵列初值为 -1 */

   for ( i = 0; i < 10; i++ )      /* 走访成绩阵列      */
   {
      index = score[i];
      pointer[index] = i;          /* 建立pointer阵列   */
   }
   /* 第二部分:查询学生学号 */
   while ( 1 )
   {
      printf("请输入学生成绩( 0 到 100). ==> ");
      scanf("%d",&grade);          /* 读取学生成绩     */
      if ( grade != -1 )
      {
         index = pointer[grade];   /* 查询学号         */
         if ( index != -1 )
            printf("学生学号是: %d\n",index);
         else
            printf("没有此成绩的学生\n");
      }
      else
         exit(1);                  /* 结束回路离开    */
   }

   return 0;
}
