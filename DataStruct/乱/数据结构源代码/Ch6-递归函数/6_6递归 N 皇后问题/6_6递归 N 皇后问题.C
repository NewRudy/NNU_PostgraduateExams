/* ======================================== */
/*    程式实例: 6_6.c                       */
/*    应用递归来解 N 皇后问题               */
/*    数字 1: 表示是放置皇后                */
/*    数字 0: 表示没有放置                  */
/* ======================================== */
#define MAXQUEEN   8              /* 最大放置的皇后数   */

int pad[MAXQUEEN][MAXQUEEN] = {   /* N X N 的棋盘       */
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0  };

/* ---------------------------------------- */
/*  放 N 个皇后的递归函数                   */
/* ---------------------------------------- */
int put_queen(int x,int y,int times)
{
   int i,j,result = 0;

   if ( times > MAXQUEEN )        /* 终止条件           */
      return 1;
   else
      if ( place(x,y) )           /* 检查是否可放置皇后 */
      {
         pad[x][y] = 1;           /* 放置皇后           */
         for ( i = 0; i < MAXQUEEN; i++)
            for ( j = 0; j < MAXQUEEN; j++)
            {
               /* 递归调用放置下一个皇后 */
               result += put_queen(i,j,times + 1);
               if ( result > 0 )
                  break;
            }
         if ( result > 0 )        /* 找到了解           */
            return 1;
         else
         {
            pad[x][y] = 0;        /* 清除皇后           */
            return 0;
         }
      }
      else
         return 0;
}

/* ---------------------------------------- */
/*  检查皇后是否有相互攻击                  */
/* ---------------------------------------- */
int place(int x,int y)
{
   int x1,y1;

   if ( pad[x][y] != 0 )          /* 己放置皇后         */
      return 0;
   x1 = x - 1;                    /* 检查左上方         */
   y1 = y - 1;
   while ( x1 >= 0 && y1 >= 0 )
      if ( pad[x1--][y1--] != 0 )
         return 0;
   x1 = x + 1;                    /* 检查右下方         */
   y1 = y + 1;
   while ( x1 < MAXQUEEN && y1 < MAXQUEEN )
      if ( pad[x1++][y1++] != 0 )
         return 0;
   x1 = x + 1;                    /* 检查右上方         */
   y1 = y - 1;
   while ( x1 < MAXQUEEN && y1 >= 0 )
      if ( pad[x1++][y1--] != 0 )
         return 0;
   x1 = x - 1;                    /* 检查左下方         */
   y1 = y + 1;
   while ( x1 >=0 && y1 < MAXQUEEN )
      if ( pad[x1--][y1++] != 0 )
         return 0;
   x1 = x;                        /* 检查下方           */
   y1 = y + 1;
   while ( y1 < MAXQUEEN )
      if ( pad[x1][y1++] != 0 )
         return 0;
   x1 = x;                        /* 检查上方           */
   y1 = y - 1;
   while ( y1 >= 0 )
      if ( pad[x1][y1--] != 0 )
         return 0;
   x1 = x + 1;                    /* 检查右方           */
   y1 = y;
   while ( x1 < MAXQUEEN )
      if ( pad[x1++][y1] != 0 )
         return 0;
   x1 = x - 1;                    /* 检查左方           */
   y1 = y;
   while ( x1 >= 0 )
      if ( pad[x1--][y1] != 0 )
         return 0;
   return 1;
}

/* ---------------------------------------- */
/*  主程式: 用递归的方法解 N = 8 皇后问题.  */
/* ---------------------------------------- */
void main()
{
   int i,j;

   put_queen(0,0,1);              /* 调用递归函数       */
   printf("放置八皇后的棋盘图形:\n");
   for ( i = 0; i < MAXQUEEN; i++)   /* 印出棋盘的图形  */
   {
      for ( j = 0; j < MAXQUEEN; j++)
         printf("%d",pad[i][j]);  /* 印出各座标值       */
      printf("\n");               /* 换行               */
   }
}
