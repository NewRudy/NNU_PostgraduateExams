/* ======================================== */
/*    程式实例: 8_2_2.c                     */
/*    图形的邻接链表表示法                  */
/* ======================================== */
#include <stdlib.h>
#include <stdio.h>
struct node                       /* 图形顶点结构宣告    */
{
   int vertex;                    /* 顶点资料            */
   struct node *nextnode;         /* 指下一顶点的指标    */
};
typedef struct node *graph;       /* 图形的结构新型态    */
struct node head[6];              /* 图形顶点结构数组    */

/* ---------------------------------------- */
/*  建立图形                                */
/* ---------------------------------------- */
void creategraph(int *node,int num)
{
   graph newnode;                 /* 新顶点指标          */
   graph ptr;
   int from;                      /* 边线的起点          */
   int to;                        /* 边线的终点          */
   int i;

   for ( i = 0; i < num; i++ )    /* 读取边线的回路      */
   {
      from = node[i*2];           /* 边线的起点          */
      to = node[i*2+1];           /* 边线的终点          */
      /* 建立新顶点记忆体 */
      newnode = ( graph ) malloc(sizeof(struct node));
      newnode->vertex = to;       /* 建立顶点内容        */
      newnode->nextnode = 0;   /* 设定指标初值        */
      ptr = &(head[from]);        /* 顶点位置            */
      while ( ptr->nextnode != 0 ) /* 遍历至链表尾    */
         ptr = ptr->nextnode;     /* 下一个顶点          */
      ptr->nextnode = newnode;    /* 插入结尾            */
   }
}

/* ---------------------------------------- */
/*  主程式: 建立图形后,将邻接链表印出.      */
/* ---------------------------------------- */
void main()
{
   graph ptr;
   int node[12][2] = { {1, 2}, {2, 1},   /* 边线数组     */
                       {1, 3}, {3, 1},
                       {2, 3}, {3, 2},
                       {2, 4}, {4, 2},
                       {3, 5}, {5, 3},
                       {4, 5}, {5, 4} };
   int i;

   for ( i = 1; i <= 5; i++ )
   {
      head[i].vertex = i;         /* 设定顶点值          */
      head[i].nextnode = NULL;    /* 清除图形指标        */
   }
   creategraph(node,12);          /* 建立图形            */
   printf("图形的邻接链表内容:\n");
   for ( i = 1; i <= 5; i++ )
   {
      printf("顶点%d =>",head[i].vertex);/* 顶点值       */
      ptr = head[i].nextnode;            /* 顶点位置     */
      while ( ptr != NULL )              /* 遍历至链表尾 */
      {
         printf(" %d ",ptr->vertex);     /* 印出顶点内容 */
         ptr = ptr->nextnode;            /* 下一个顶点   */
      }
      printf("\n");                      /* 换行         */
   }
}
