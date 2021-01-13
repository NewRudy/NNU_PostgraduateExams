/* ======================================== */
/*    程式实例: 8_6.c                       */
/*    使用拓扑排序来找图回路              */
/* ======================================== */
#include <stdlib.h>
#define MAXQUEUE 20               /* 伫列的最大容量       */

struct node                       /* 图顶点结构宣告     */
{
   int vertex;                    /* 顶点资料             */
   struct node *nextnode;         /* 指下一顶点的指标     */
};
typedef struct node *graph;       /* 图的结构新型态     */
struct node head1[8];             /* 图顶点结构数组     */
struct node head2[8];             /* 图顶点结构数组     */

int queue[MAXQUEUE];              /* 伫列的数组宣告       */
int front = -1;                   /* 伫列的前端           */
int rear = -1;                    /* 伫列的后端           */

/* ---------------------------------------- */
/*  建立含分支度的图                      */
/* ---------------------------------------- */
void creategraph(graph head,int *node,int num)
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
      head[to].vertex += 1;       /* 内分支度加一         */
      /* 建立新顶点记忆体 */
      newnode = ( graph ) malloc(sizeof(struct node));
      newnode->vertex = to;       /* 建立顶点内容         */
      newnode->nextnode = NULL;   /* 设定指标初值         */
      ptr = &(head[from]);        /* 顶点位置             */
      while ( ptr->nextnode != NULL ) /* 遍历至链表尾     */
         ptr = ptr->nextnode;     /* 下一个顶点           */
      ptr->nextnode = newnode;    /* 插入结尾             */
   }
}

/* ---------------------------------------- */
/*  图的拓扑排序                          */
/* ---------------------------------------- */
int toposort(graph head,int num)
{
   graph ptr;
   int i;

   /* 将内分支度为零页的顶点存入伫列的回路 */
   for ( i = 1; i <= num; i++ )
      if ( head[i].vertex == 0 )  /* 如果分支度是零       */
         enqueue(i);              /* 存顶点至伫列         */
   while ( ( i = dequeue() ) != -1 )
   {
      printf(" %d ",i);           /* 印出拓扑排序顶点     */
      ptr = head[i].nextnode;     /* 顶点位置             */
      while ( ptr != NULL )       /* 遍历至链表尾         */
      {
         i = ptr->vertex;         /* 得到顶点值           */
         head[i].vertex --;       /* 顶点内分支度减一     */
         if ( head[i].vertex == 0  )  /* 如果内分支度是零 */
            enqueue(i);           /* 存顶点至伫列         */
         ptr = ptr->nextnode;     /* 下一个顶点           */
      }
   }
   printf("\n");                  /* 换行                 */
   for ( i = 1; i <= num; i++ )   /* 检查是否有回路       */
      if ( head[i].vertex != 0 )  /* 内分支度不是零       */
         return 1;                /* 有回路               */
   return 0;                      /* 没有回路             */
}

/* ---------------------------------------- */
/*  伫列资料的存入                          */
/* ---------------------------------------- */
int enqueue(int value)
{
   if ( rear + 1 == front ||      /* 检查伫列是否全满     */
        (rear == (MAXQUEUE - 1) && front <= 0) )
      return -1;                  /* 无法存入             */
   rear++;                        /* 后端指标往前移       */
   if ( rear == MAXQUEUE )        /* 是否超过界限         */
      rear = 0;                   /* 从头开始             */
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
   if ( front == MAXQUEUE )       /* 是否超过界限         */
      front = 0;                  /* 从头开始             */
   return queue[front];           /* 伫列取出             */
}

/* ---------------------------------------- */
/*  主程式: 建立图后,找寻图内是否有回路.  */
/* ---------------------------------------- */
void main()
{
   graph ptr;
   int node[10][2] = { {3, 2},    /* 边线数组             */
                       {2, 1},
                       {2, 5},
                       {2, 6},
                       {1, 4},
                       {5, 4},
                       {7, 4},
                       {6, 7},
                       {5, 6},
                       {7, 5} };
   int i;

   for ( i = 1; i <= 7; i++ )
   {
      head1[i].vertex = 0;        /* 设定顶点值           */
      head1[i].nextnode = NULL;   /* 清除图1指标        */
      head2[i].vertex = 0;        /* 设定顶点值           */
      head2[i].nextnode = NULL;   /* 清除图2指标        */
   }
   creategraph(head1,node,8);     /* 建立图1            */
   creategraph(head2,node,10);    /* 建立图2            */
   printf("图1 - 含入度的邻接表内容:\n");
   for ( i = 1; i <= 7; i++ )
   {
      printf("顶点%d(%d) =>",i,head1[i].vertex);
      ptr = head1[i].nextnode;    /* 顶点位置             */
      while ( ptr != NULL )       /* 遍历至链表尾         */
      {
         printf(" %d ",ptr->vertex);  /* 印出顶点内容     */
         ptr = ptr->nextnode;     /* 下一个顶点           */
      }
      printf("\n");               /* 换行                 */
   }
   printf("图1 - 拓扑排序的内容:\n");
   if ( toposort(head1,7) )       /* 拓扑排序             */
      printf("图有回路\n");
   else
      printf("图没有回路\n");
   front = rear = -1;             /* 清除伫列             */
   printf("\n图2 - 含入度的邻接表内容:\n");
   for ( i = 1; i <= 7; i++ )
   {
      printf("顶点%d(%d) =>",i,head2[i].vertex);
      ptr = head2[i].nextnode;    /* 顶点位置             */
      while ( ptr != NULL )       /* 遍历至链表尾         */
      {
         printf(" %d ",ptr->vertex);  /* 印出顶点内容     */
         ptr = ptr->nextnode;     /* 下一个顶点           */
      }
      printf("\n");               /* 换行                 */
   }
   printf("图2 - 拓扑排序的内容:\n");
   if ( toposort(head2,7) )       /* 拓扑排序             */
      printf("图有回路\n");
   else
      printf("图没有回路\n");
}
