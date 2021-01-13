/* ======================================== */
/*    程式实例: 5_8.c                     */
/*    应用栈来走迷宫                      */
/* ======================================== */
#include <stdlib.h>

struct stack_node                 /* 栈的结构宣告     */
{
   int x;                         /* 路径座标x          */
   int y;                         /* 路径座标y          */
   struct stack_node *next;       /* 指向下一节点       */
};
typedef struct stack_node stack_list; /* 串列新型态     */
typedef stack_list *link;         /* 串列指标新型态     */

link path = NULL;                 /* 路径栈指标       */

/* ---------------------------------------- */
/*  栈资料的存入                          */
/* ---------------------------------------- */
link push(link stack,int x,int y)
{
   link new_node;                 /* 新节黠指标         */

   /* 配置节点记忆体 */
   new_node = ( link ) malloc(sizeof(stack_list));
   if ( !new_node )
   {
      printf("记忆体配置失败! \n");
      return NULL;                /* 存入失败           */
   }
   new_node->x = x;               /* 存入路径座标x      */
   new_node->y = y;               /* 存入路径座标y      */
   new_node->next = stack;        /* 新节点指向原开始   */
   stack = new_node;              /* 新节点成为栈开始 */
   return stack;
}

/* ---------------------------------------- */
/*  栈资料的取出                          */
/* ---------------------------------------- */
link pop(link stack,int *x,int *y)
{
   link top;                      /* 指向栈顶端       */

   if ( stack != NULL )
   {
      top = stack;                /* 指向栈顶端       */
      stack = stack->next;        /* 栈指标指向下节点 */
      *x = stack->x;              /* 取出路径座标x      */
      *y = stack->y;              /* 取出路径座标y      */
      free(top);                  /* 释回节点记忆体     */
      return stack;               /* 传回栈指标       */
   }
   else
      *x = -1;
}

/* ---------------------------------------- */
/*  主程式: 用回溯的方法在数组迷宫找出口.   */
/*  数字 0: 表示是可走的路                  */
/*  数字 1: 表示是墙壁,不可走的路           */
/*  数字 2: 标示是走过的路                  */
/*  数字 3: 标表示是回溯的路                */
/* ---------------------------------------- */
void main()
{
   int maze[7][10] = {            /* 迷宫的数组         */
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
            1, 0, 1, 0, 1, 1, 1, 0, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
            1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int i,j;
   int x = 5;                     /* 迷宫的入口座标     */
   int y = 8;

   while ( x != 1 || y != 1 )     /* 是否是迷宫出口     */
   {
      maze[x][y] = 2;             /* 标示走过的路       */
      if ( maze[x-1][y] <= 0 )    /* 往上方走           */
      {
         x = x - 1;               /* 座标x减一          */
         path = push(path,x,y);   /* 存入路径           */
      }
      else
         if ( maze[x+1][y] <= 0 ) /* 往下方走           */
         {
            x = x + 1;            /* 座标x加一          */
            path = push(path,x,y);     /* 存入路径      */
         }
         else
            if ( maze[x][y-1] <= 0 )   /* 往左方走      */
            {
               y = y - 1;              /* 座标y减一     */
               path = push(path,x,y);  /* 存入路径      */
            }
            else
               if ( maze[x][y+1] <= 0 )  /* 往右方走    */
               {
                  y = y + 1;             /* 座标y加一   */
                  path = push(path,x,y); /* 存入路径    */
               }
               else               /* 没有路可走:回溯    */
               {
                  maze[x][y] = 3; /* 表示回溯的路       */
                  path = pop(path,&x,&y); /* 退回一步   */
               }
   }
   maze[x][y] = 2;                /* 标示最后一点       */
   printf("迷宫的路径如下图所示:\n");
   for ( i = 1; i < 6; i++)       /* 印出迷宫的图形     */
   {
      for ( j = 1; j < 9; j++)
         printf("%d",maze[i][j]); /* 印出各座标         */
      printf("\n");               /* 换行               */
   }
}
