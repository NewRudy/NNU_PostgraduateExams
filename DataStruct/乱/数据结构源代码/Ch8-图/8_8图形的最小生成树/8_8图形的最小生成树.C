/* ======================================== */
/*    程式实例: 8_8.c                    */
/*    图形的最小生成树                  */
/* ======================================== */
#include <stdlib.h>

struct edge                       /* 图形边线结构宣告     */
{
   int from;                      /* 开始顶点资料         */
   int to;                        /* 终点顶点资料         */
   int weight;                    /* 成本                 */
   struct edge *nextedge;         /* 指下一边线的指标     */
};
typedef struct edge *edgelist;    /* 边线的结构新型态     */
edgelist list = NULL;             /* 边线链表开始指标     */
int node[6];                      /* 顶点数组             */

/* ---------------------------------------- */
/*  建立边线链表                            */
/* ---------------------------------------- */
edgelist createedgelist(edgelist list,int *edges,int num)
{
   edgelist newnode;              /* 新边线节点指标       */
   edgelist last;                 /* 最后边线节点指标     */
   int i;

   for ( i = 0; i < num; i++ )    /* 建立边线链表回路     */
   {
      /* 建立新边线记忆体 */
      newnode = ( edgelist ) malloc (sizeof( struct edge ));
      newnode->from = edges[3*i]; /* 边线的起点           */
      newnode->to = edges[3*i+1]; /* 边线的终点           */
      newnode->weight = edges[3*i+2]; /* 建立成本内容     */
      newnode->nextedge = NULL;   /* 设定指标初值         */
      if ( list == NULL )         /* 第一个节点           */
      {
         list = newnode;          /* 建立链表开始指标     */
         last = list;             /* 保留最后节点指标     */
      }
      else
      {
         last->nextedge = newnode;  /* 链结至最后节点     */
         last = newnode;          /* 保留最后节点指标     */
      }
   }
   return list;                   /* 传回链表开始指标     */
}

/* ---------------------------------------- */
/*  结合成同一集合                          */
/* ---------------------------------------- */
int uniongroup(int from,int to)
{
   int to_root;

   to_root = to;                  /* 从终点顶点找         */
   while ( node[to_root] > 0 )
      to_root = node[to_root];
   node[to_root] = from;          /* 结合两个顶点         */
}

/* ---------------------------------------- */
/*  是否存在同一集合                        */
/* ---------------------------------------- */
int samegroup(int from,int to)
{
   int from_root;
   int to_root;

   from_root = from;              /* 从开始顶点找         */
   while ( node[from_root] > 0 )
      from_root = node[from_root];
   to_root = to;                  /* 从终点顶点找         */
   while ( node[to_root] > 0 )
      to_root = node[to_root];
   if ( from_root == to_root )    /* 是否同一集合         */
      return 1;
   else
      return 0;
}

/* ---------------------------------------- */
/*  图形的最小生成树                    */
/* ---------------------------------------- */
void minspantree()
{
   edgelist ptr;

   ptr = list;                    /* 指向链表开始         */
   while ( ptr != NULL )
   {
      /* 是否存在同一集合 */
      if ( !samegroup(ptr->from,ptr->to) )
      {
         /* 印出最小成本的边缎 */
         printf(" 从顶点: %d 到: %d 成本: %d\n",ptr->from,
                  ptr->to,ptr->weight);
         uniongroup(ptr->from,ptr->to); /* 结合成同一集合 */
      }
      ptr = ptr->nextedge;        /* 下一边线             */
   }
}

/* ---------------------------------------- */
/*  主程式: 图形的最小生成树            */
/* ---------------------------------------- */
void main()
{
   int edges[8][3] = { { 1, 2, 2 }, /* 成本边线数组       */
                       { 2, 4, 3 },
                       { 1, 4, 4 },
                       { 3, 5, 5 },
                       { 2, 5, 6 },
                       { 2, 3, 8 },
                       { 3, 4, 10 },
                       { 4, 5, 15 } };
   int i;

   list = createedgelist(list,edges,8);   /* 建立边线链表 */
   for ( i = 1; i <= 5; i++ )     /* 初始顶点数组         */
      node[i] = -1;
   printf("图形的最小生成树:\n");
   minspantree();                 /* 建立最小生成树   */
   printf("顶点数组内容:\n");
   for ( i = 1; i <= 5; i++ )
      printf("[%d]",node[i]);     /* 印出顶点数组         */
   printf("\n");                  /* 换行                 */
}

