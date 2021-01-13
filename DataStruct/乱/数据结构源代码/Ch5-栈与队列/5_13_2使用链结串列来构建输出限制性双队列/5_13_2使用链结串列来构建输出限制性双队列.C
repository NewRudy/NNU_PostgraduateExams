/* ======================================== */
/*    程式实例: 5_13_2.c                    */
/*    使用链结串列来构建输出限制性双队列    */
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
/*  队列资料的存入(从后端)                  */
/* ---------------------------------------- */
int enqueue_rear(int value)
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
/*  队列资料的存入(从前端)                  */
/* ---------------------------------------- */
int enqueue_front(int value)
{
   link new_node;

   new_node = ( link ) malloc(sizeof(queue_list));
   if ( !new_node )               /* 检查配置记忆体     */
   {
      printf("记忆体配置失败! \n");
      return -1;                  /* 无法存入           */
   }
   new_node->data = value;        /* 存入队列节点       */
   if ( front == NULL )           /* 是否是第一次存入   */
   {
      new_node->next = NULL;      /* 设定初值           */
      rear = new_node;            /* rear指向new_node   */
   }
   else
      new_node->next = front;     /* 插入front之前      */
   front = new_node;              /* front指向new_node  */
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
/*  主程式: 模拟双队列操作                  */
/*  输出输入的内容都会储存於数组中, 模拟双  */
/*  队列存入, 接着列印出数组内容来看其结果. */
/* ---------------------------------------- */
void main()
{
   int input_list[6] =            /* 储存输入的元素     */
                       { 1, 2, 3, 4, 5, 6 };
   int select;                    /* 选择项1,2,或3      */
   int i,temp,pos = 0;

   for ( i = 0; i < 6; i++ )      /* 存入队列           */
   {
      /* 选项内容 */
      printf("[1]从后存入 [2]从前存入 ==> ");
      scanf("%d",&select);        /* 读入选项           */
      switch ( select )
      {
         /* 从后端存入队列的内容 */
         case 1: enqueue_rear(input_list[i]);
                 break;
         /* 从前端存入队列的内容 */
         case 2: enqueue_front(input_list[i]);
                 break;
         /* 内定从后端存入队列的内容 */
         default:
                 enqueue_rear(input_list[i]);
                 break;
      }
   }
   printf("原来数组的顺序: ");    /* 输出结果           */
   for ( i = 0; i < 6; i++ )      /* 列印回路           */
      printf("[%d]",input_list[i]);
   printf("\n队列取出的顺序: ");
   while ( (temp = dequeue()) != -1 ) /*取出剩下队列元素*/
      printf("[%d]",temp);
   printf("\n");                  /* 换行               */
}
