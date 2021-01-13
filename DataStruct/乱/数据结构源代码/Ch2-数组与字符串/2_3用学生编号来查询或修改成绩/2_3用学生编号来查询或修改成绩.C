/* ======================================== */
/*    程序实例: 2_3.c                     */
/*    用学生编号来查询或修改成绩            */
/* ======================================== */

int main()
{
   int score[10] = { 76, 85, 90, 67, 59, 79, 82,
                     95, 91, 65 }; /* 学生成绩数组 */
   int num;                        /* 学生学号变量 */
   int grade;                      /* 学生成绩变量 */
   int select;                     /* 选项         */

   while ( 1 )
   {
      printf("操作选项:\n");       /* 输出菜单     */
      printf("1: 查询成绩\n");
      printf("2: 修改成绩\n");
      printf("3: 退出操作\n");
      printf("请输入选项( 1 到 3 ). ==> ");
      scanf("%d",&select);         /* 读入作业选项 */
      if ( select != 3 )
      {
         printf("请输入学生学号( 0 到 9). ==> ");
         scanf("%d",&num);         /* 读入学生学号 */
      }
      switch ( select )
      {
         case 1:                   /* 查询成绩     */
            grade = score[num];    /* 读取成绩     */
            printf("学生成绩: %d\n",grade);
            break;
         case 2:                   /* 修改成绩     */
            grade = score[num];
            printf("原来学生成绩: %d\n",grade);
            printf("请输入新成绩. ==> "); /* 读取新成绩 */
            scanf("%d",&grade);
            score[num] = grade;           /* 保存新成绩 */
            break;
         case 3:                          /* 结束作业   */
            exit(1);                      /* 退出       */
            break;
      }
   }

   return 0;
}
