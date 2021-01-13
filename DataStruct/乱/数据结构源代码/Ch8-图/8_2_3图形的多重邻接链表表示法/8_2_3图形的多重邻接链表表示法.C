/* ======================================== */
/*    程式实例: 8_2_3.c                     */
/*    图形的多重邻接链表表示法              */
/* ======================================== */
#include <stdlib.h>

struct edge                       /* 图形边线结构宣告     */
{
   int vertex1;                   /* 顶点1资料            */
   int vertex2;                   /* 顶点2资料            */
   struct edge *edge1;            /* 顶点1下一边线        */
   struct edge *edge2;            /* 顶点2下一边线        */
};
typedef struct edge *nextedge;    /* 图形的边线新型态     */

struct node                       /* 图形顶点结构宣告     */
{
   int vertex;                    /* 顶点资料             */
   struct edge *edge;             /* 顶点下一边线         */
};
typedef struct node *graph;       /* 图形的结构新型态     */
struct node head[6];              /* 图形顶点结构数组     */

/* ---------------------------------------- */
/*  建立图形                                */
/* ---------------------------------------- */
void creategraph(int *node,int num)
{
   nextedge newnode;              /* 新边线指标           */
   nextedge previous;             /* 前一边线指标         */
   nextedge ptr;                  /* 目前边线指标         */
   int from;                      /* 边线的起点           */
   int to;                        /* 边线的终点           */
   int i;

   for ( i = 0; i < num; i++ )    /* 读取边线的回路       */
   {
      from = node[i*2];           /* 边线的起点           */
      to = node[i*2+1];           /* 边线的终点           */
      /* 建立新边线记忆体 */
      newnode = ( nextedge ) malloc(sizeof(struct edge));
      newnode->vertex1 = from;    /* 建立顶点内容         */
      newnode->vertex2 = to;      /* 建立顶点内容         */
      newnode->edge1 = NULL;      /* 设定指标初值         */
      newnode->edge2 = NULL;      /* 设定指标初值         */
      previous = NULL;            /* 前一边线指标         */
      ptr = head[from].edge;      /* 目前边线指标         */
      while ( ptr != NULL )       /* 遍历到最后边线       */
      {
         previous = ptr;          /* 保留前一边线         */
         if ( ptr->vertex1 == from )  /* 决定走的边线     */
            ptr = ptr->edge1;     /* 下一边线             */
         else
            ptr = ptr->edge2;     /* 下一边线             */
      }
      if ( previous == NULL )
         head[from].edge = newnode;   /* 设定顶点边线指标 */
      else
         if ( previous->vertex1 == from ) /* 决定走的边线 */
            previous->edge1 = newnode;    /* 连接下一边线 */
         else
            previous->edge2 = newnode;    /* 连接下一边线 */
      previous = NULL;                    /* 前一边线指标 */
      ptr = head[to].edge;                /* 目前边线指标 */
      while ( ptr != NULL )       /* 遍历到最后边线       */
      {
         previous = ptr;          /* 保留前一边线         */
         if ( ptr->vertex1 == to )  /* 决定走的边线       */
            ptr = ptr->edge1;     /* 下一边线             */
         else
            ptr = ptr->edge2;     /* 下一边线             */
      }
      if ( previous == NULL )
         head[to].edge = newnode; /* 设定顶点边线指标     */
      else
         if ( previous->vertex1 == to ) /* 决定走的边线   */
            previous->edge1 = newnode;  /* 连接下一边线   */
         else
            previous->edge2 = newnode;  /* 连接下一边线   */
   }
}

/* ---------------------------------------- */
/*  主程式: 建立图形后,将边线列印出.        */
/* ---------------------------------------- */
void main()
{
   nextedge ptr;
   int node[6][2] = {  {1, 2},    /* 边线数组             */
                       {1, 3},
                       {2, 3},
                       {2, 4},
                       {3, 5},
                       {4, 5}, };
   int i;

   for ( i = 1; i <= 5; i++ )
   {
      head[i].vertex = i;         /* 设定顶点值           */
      head[i].edge = NULL;        /* 清除图形指标         */
   }
   creategraph(node,6);           /* 建立图形             */
   printf("图形的多重邻接链表内容:\n");
   for ( i = 1; i <= 5; i++ )
   {
      printf("顶点%d =>",head[i].vertex); /* 顶点值       */
      ptr = head[i].edge;                 /* 边线位置     */
      while ( ptr != NULL )       /* 遍历至链表尾         */
      {
         /* 印出边线 */
         printf("(%d,%d)",ptr->vertex1,ptr->vertex2);
         /* 决定下一边线指标 */
         if ( head[i].vertex == ptr->vertex1 )
            ptr = ptr->edge1;     /* 下一个边线           */
         else
            ptr = ptr->edge2;     /* 下一个边线           */
      }
      printf("\n");               /* 换行                 */
   }
}
