/* ======================================== */
/*    程式实例: 5_2a.c                      */
/*    使用链结串列来构建栈                */
/* ======================================== */
#include <time.h>
#include <stdlib.h>

struct stack_node                 /* 栈的结构宣告     */
{
   int data;                      /* 栈资料           */
   struct stack_node *next;       /* 指向下一节点       */
};
typedef struct stack_node stack_list;  /* 串列新型态    */
typedef stack_list *link;         /* 串列指标新型态     */

link stack = NULL;                /* 栈指标           */

/* ---------------------------------------- */
/*  栈资料的存入                          */
/* ---------------------------------------- */
int push(int value)
{
   link new_node;                 /* 新节点指标         */

   /* 配置节点记忆体 */
   new_node = ( link ) malloc(sizeof(stack_list));
   if ( !new_node )
   {
      printf("记忆体配置失败! \n");
      return -1;                  /* 存入失败           */
   }
   new_node->data = value;        /* 建立节点内容       */
   new_node->next = stack;        /* 新节点指向原开始   */
   stack = new_node;              /* 新节点成为栈开始 */
}

/* ---------------------------------------- */
/*  栈资料的取出                          */
/* ---------------------------------------- */
int pop()
{
   link top;                      /* 指向栈顶端       */
   int temp;

   if ( stack != NULL )           /* 栈是否是空的     */
   {
      top = stack;                /* 指向栈顶端       */
      stack = stack->next;        /* 栈指标指向下节点 */
      temp = top->data;           /* 取出资料           */
      free(top);                  /* 释回节点记忆体     */
      return temp;                /* 栈取出           */
   }
   else
      return -1;
}

/* ---------------------------------------- */
/*  检查栈是否是空的                      */
/* ---------------------------------------- */
int empty()
{
   if ( stack == NULL )           /* 是否是空           */
      return 1;                   /* 空的               */
   else
      return 0;                   /* 不是空的           */
}

/* ---------------------------------------- */
/*  主程式: 洗牌后, 将牌发给四个人.         */
/*     红心: 数组  0 - 12                   */
/*     方块: 数组 13 - 25                   */
/*     梅花: 数组 26 - 38                   */
/*     黑桃: 数组 39 - 51                   */
/* ---------------------------------------- */
void main()
{
   int card[52];                  /* 朴克牌数组         */
   int pos;                       /* 牌代码             */
   int i,temp;
   long temptime;
   srand(time(&temptime) % 60);   /* 使用时间初始乱数   */
   for ( i = 0; i < 52; i++ )
      card[i] = 0;                /* 清除朴克牌数组     */
   i = 0;
   while ( i != 52 )              /* 洗牌回路           */
   {
      pos = rand() % 52;          /* 乱数取值 0-51      */
      if ( card[pos] == 0 )       /* 是否是未洗牌       */
      {
         push(pos);               /* 存此张牌进栈     */
         card[pos] = 1;           /* 设定此张牌洗过     */
         i++;                     /* 下一张牌           */
      }
   }
   printf("    1      2      3      4 \n");
   printf(" ==========================\n");
   for ( i = 0; i < 5; i++ )      /* 发牌给四人的回路   */
   {
      temp = pop();               /* 取出栈资料       */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = pop();               /* 取出栈资料       */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = pop();               /* 取出栈资料       */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = pop();               /* 取出栈资料       */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      printf("\n");               /* 换行               */
   }
}
