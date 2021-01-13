/* ======================================== */
/*    程式实例: 5_12.c                      */
/*    使用链结串列来构建队列                */
/* ======================================== */
#include <stdlib.h>

struct queue_node                 /* 队列结构的宣告     */
{
   int data;                      /* 资料               */
   struct queue_node *next;       /* 结构指标           */
};
typedef struct queue_node queue_list;  /* 定义队列型态  */
typedef queue_list *link;         /* 定义队列指标型态   */

link front = NULL;                /* 队列的前端         */
link rear = NULL;                 /* 队列的后端         */

/* ---------------------------------------- */
/*  队列资料的存入                          */
/* ---------------------------------------- */
int enqueue(int value)
{
   link new_node;

   new_node = ( link ) malloc(sizeof(queue_list));
   if ( !new_node )               /* 检查配置记忆体     */
   {
      printf("记忆体配置失败! \n");
      return -1;                  /* 无法存入           */
   }
   new_node->data = value;        /* 存入队列节点       */
   new_node->next = NULL;         /* 设定初值           */
   if ( rear == NULL )            /* 是否是第一次存入   */
      front = new_node;           /* front指向new_node  */
   else
      rear->next = new_node;      /* 插入rear之后       */
   rear = new_node;               /* rear指向new_node   */
}

/* ---------------------------------------- */
/*  队列资料的取出                          */
/* ---------------------------------------- */
int dequeue()
{
   link top;
   int temp;

   if ( front != NULL )           /* 队列是否是空的     */
   {
      top = front;                /* top指向front       */
      front = front->next;        /* 删除之前节点       */
      temp = top->data;           /* 取出资料           */
      free(top);                  /* 释回记忆体         */
      return temp;                /* 队列取出           */
   }
   else
      return -1;                  /* 无法取出           */
}

/* ---------------------------------------- */
/*  主程式: 模拟队列操作                    */
/*  输出输入的内容都会储存於数组中, 接着列  */
/*  印出数组内容来看其结果.                 */
/* ---------------------------------------- */
void main()
{
   int input[100];                /* 储存输入的元素     */
   int output[100];               /* 储存取出的元素     */
   int select;                    /* 选择项1,2,或3      */
   int i_count = 0;               /* 数组input的索引    */
   int o_count = 0;               /* 数组output的索引   */
   int loop = 1;                  /* 回路控制           */
   int i,temp;

   while ( loop )                 /* 主回路开始         */
   {
      /* 选项内容 */
      printf("[1]输入 [2]取出 [3]列出全部内容 ==> ");
      scanf("%d",&select);        /* 读入选项           */
      switch ( select )
      {
         /* 输入值后将之存入队列 */
         case 1: printf("请输入存入队列的值(%d) ==> ",
                         i_count + 1);
                 scanf("%d",&temp);
                 if ( enqueue(temp) == -1 )
                    printf("队列全满.\n");
                 else
                    input[i_count++] = temp;
                 break;
         /* 取出队列的内容 */
         case 2: if ( (temp = dequeue()) == -1 )
                    printf("队列是空的.\n");
                 else
                 {
                    printf("取出队列元素: %d\n",temp);
                    output[o_count++] = temp;
                 }
                 break;
         /* 离开回路 */
         case 3: loop = 0;        /* 设定loop为零       */
                 break;
      }
   }
   printf("输入队列的元素: ");    /* 输出结果           */
   for ( i = 0; i < i_count; i++ )    /* 列印回路       */
      printf("[%d]",input[i]);
   printf("\n取出队列的元素: ");
   for ( i = 0; i < o_count; i++ )    /* 列印回路       */
      printf("[%d]",output[i]);
   printf("\n剩下队列的元素: ");
   while ( (temp = dequeue()) != -1 ) /*取出剩下队列元素*/
      printf("[%d]",temp);
   printf("\n");                      /* 换行           */
}
