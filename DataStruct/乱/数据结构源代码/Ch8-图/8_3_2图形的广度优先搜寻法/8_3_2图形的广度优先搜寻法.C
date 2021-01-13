/* ======================================== */
/*    程式实例: 8_3_2.c                     */
/*    图形的广度优先搜寻法                  */
/* ======================================== */
#include <stdlib.h>
#define MAXQUEUE 10               /* 伫列的最大容量       */

struct node                       /* 图形顶点结构宣告     */
{
   int vertex;                    /* 顶点资料             */
   struct node *nextnode;         /* 指下一顶点的指标     */
};
typedef struct node *graph;       /* 图形的结构新型态     */
struct node head[9];              /* 图形顶点结构数组     */
int visited[9];                   /* 遍历记录数组         */

int queue[MAXQUEUE];              /* 伫列的数组宣告       */
int front = -1;                   /* 伫列的前端           */
int rear = -1;                    /* 伫列的后端           */

/* ---------------------------------------- */
/*  建立图形                                */
/* ---------------------------------------- */
void creategraph(int *node,int num)
{
   graph newnode;                 /* 新顶点指标           */
   graph ptr;
   int from;                      /* 边线的起点           */
   int to;                        /* 边线的终点           */
   int i;

   for ( i = 0; i < num; i++ )    /* 读取边线的回路       */
   {
      from = node[i*2];           /* 边线的起点           */
      to = node[i*2+1];           /* 边线的终点           */
      /* 建立新顶点记忆体 */
      newnode = ( graph ) malloc(sizeof(struct node));
      newnode->vertex = to;       /* 建立顶点内容         */
      newnode->nextnode = NULL;   /* 设定指标初值         */
      ptr = &(head[from]);        /* 顶点位置             */
      while ( ptr->nextnode != NULL ) /* 遍历至链表尾     */
         ptr = ptr->nextnode;         /* 下一个顶点       */
      ptr->nextnode = newnode;        /* 插入结尾         */
   }
}

/* ---------------------------------------- */
/*  伫列资料的存入                          */
/* ---------------------------------------- */
int enqueue(int value)
{
   if ( rear >= MAXQUEUE )        /* 检查伫列是否全满     */
      return -1;                  /* 无法存入             */
   rear++;                        /* 后端指标往前移       */
   queue[rear] = value;           /* 存入伫列             */
}

/* ---------------------------------------- */
/*  伫列资料的取出                          */
/* ---------------------------------------- */
int dequeue()
{
   if ( front  == rear )          /* 检查伫列是否是空     */
      return -1;                  /* 无法取出             */
   front++;                       /* 前端指标往前移       */
   return queue[front];           /* 伫列取出             */
}

/* ---------------------------------------- */
/*  图形的广度优先搜寻法                    */
/* ---------------------------------------- */
void bfs(int current)
{
   graph ptr;

   /* 处理第一个顶点 */
   enqueue(current);              /* 将顶点存入伫列       */
   visited[current] = 1;          /* 记录已遍历过         */
   printf("顶点[%d] ",current);   /* 印出遍历顶点值       */
   while ( front != rear )        /* 伫列是否是空的       */
   {
      current = dequeue();        /* 将顶点从伫列取出     */
      ptr = head[current].nextnode;   /* 顶点位置         */
      while ( ptr != NULL )           /* 遍历至链表尾     */
      {
         if ( visited[ptr->vertex] == 0 ) /* 如过没遍历过 */
         {
            enqueue(ptr->vertex);     /* 递回遍历呼叫     */
            visited[ptr->vertex] = 1; /* 记录已遍历过     */
            /* 印出遍历顶点值 */
            printf("顶点[%d] ",ptr->vertex);
         }
         ptr = ptr->nextnode;     /* 下一个顶点           */
      }
   }
}

/* ---------------------------------------- */
/*  主程式: 建立图形后,将遍历内容印出.      */
/* ---------------------------------------- */
void main()
{
   graph ptr;
   int node[20][2] = { {1, 2}, {2, 1},  /* 边线数组       */
                       {1, 3}, {3, 1},
                       {2, 4}, {4, 2},
                       {2, 5}, {5, 2},
                       {3, 6}, {6, 3},
                       {3, 7}, {7, 3},
                       {4, 8}, {8, 4},
                       {5, 8}, {8, 5},
                       {6, 8}, {8, 6},
                       {7, 8}, {8, 7} };
   int i;

   for ( i = 1; i <= 8; i++ )
   {
      head[i].vertex = i;         /* 设定顶点值           */
      head[i].nextnode = NULL;    /* 清除图形指标         */
      visited[i] = 0;             /* 设定遍历初值         */
   }
   creategraph(node,20);          /* 建立图形             */
   printf("图形的邻接链表内容:\n");
   for ( i = 1; i <= 8; i++ )
   {
      printf("顶点%d =>",head[i].vertex); /* 顶点值       */
      ptr = head[i].nextnode;             /* 顶点位置     */
      while ( ptr != NULL )       /* 遍历至链表尾         */
      {
         printf(" %d ",ptr->vertex);  /* 印出顶点内容     */
         ptr = ptr->nextnode;         /* 下一个顶点       */
      }
      printf("\n");               /* 换行                 */
   }
   printf("图形的广度优先遍历内容:\n");
   bfs(1);                        /* 印出遍历过程         */
   printf("\n");                  /* 换行                 */
}
