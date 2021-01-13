/* ======================================== */
/*    程式实例: 5_2b.c                     */
/*    使用链结串列来构建两个栈            */
/* ======================================== */
#include <stdlib.h>

struct stack_node                 /* 栈的结构宣告     */
{
   int data;                      /* 栈资料           */
   struct stack_node *next;       /* 指向下一节点       */
};
typedef struct stack_node stack_list; /* 串列新型态     */
typedef stack_list *link;         /* 串列指标新型态     */

link stack1 = NULL;               /* 栈指标1          */
link stack2 = NULL;               /* 栈指标2          */

/* ---------------------------------------- */
/*  栈资料的存入                          */
/* ---------------------------------------- */
link push(link stack,int value)
{
   link new_node;                 /* 新节黠指标         */

   /* 配置节点记忆体 */
   new_node = ( link ) malloc(sizeof(stack_list));
   if ( !new_node )
   {
      printf("记忆体配置失败! \n");
      return NULL;                /* 存入失败           */
   }
   new_node->data = value;        /* 建立节点内容       */
   new_node->next = stack;        /* 新节点指向原开始   */
   stack = new_node;              /* 新节点成为栈开始 */
   return stack;
}

/* ---------------------------------------- */
/*  栈资料的取出                          */
/* ---------------------------------------- */
link pop(link stack,int *value)
{
   link top;                      /* 指向栈顶端       */

   if ( stack != NULL )
   {
      top = stack;                /* 指向栈顶端       */
      stack = stack->next;        /* 栈指标指向下节点 */
      *value = top->data;         /* 取出资料           */
      free(top);                  /* 释回节点记忆体     */
      return stack;               /* 传回栈指标       */
   }
   else
      *value = -1;
}

/* ---------------------------------------- */
/*  检查栈是否是空的                      */
/* ---------------------------------------- */
int empty(link stack)
{
   if ( stack == NULL )           /* 是否是空           */
      return 1;                   /* 空的               */
   else
      return 0;                   /* 不是空的           */
}

/* ---------------------------------------- */
/*  主程式: 用数组建立两个栈.             */
/* ---------------------------------------- */
void main()
{
   int list1[6] = { 1, 2, 3, 4, 5, 6 };  /* 数组1内容   */
   int list2[6] = { 7, 6, 9, 4, 3, 0 };  /* 数组2内容   */
   int i,temp;

   for ( i = 0; i < 6; i++ )      /* 推入数组内容       */
   {
      stack1 = push(stack1,list1[i]);    /* 存入至栈1 */
      stack2 = push(stack2,list2[i]);    /* 存入至栈2 */
   }
   printf("原来的数组顺序(1): ");
   for ( i = 0; i < 6; i++ )
      printf("[%d]",list1[i]);
   printf("\n");                  /* 换行               */
   printf("栈取出的顺序(1): ");
   while ( !empty(stack1) )       /* 取出全部栈内容   */
   {
      stack1 = pop(stack1,&temp); /* 取出栈1资料      */
      printf("[%d]",temp);
   }
   printf("\n");                  /* 换行               */
   printf("原来的数组顺序(2): ");
   for ( i = 0; i < 6; i++ )
      printf("[%d]",list2[i]);
   printf("\n");                  /* 换行               */
   printf("栈取出的顺序(2): ");
   while ( !empty(stack2) )       /* 取出全部栈内容   */
   {
      stack2 = pop(stack2,&temp); /* 取出栈1资料      */
      printf("[%d]",temp);
   }
   printf("\n");                  /* 换行               */
}
