/* ======================================== */
/*    程式实例:5_6.c                     */
/*    后序四则表达式的值                    */
/* ======================================== */
#include <stdlib.h>

struct stack_node                 /* 栈的结构宣告     */
{
   int data;                      /* 栈资料           */
   struct stack_node *next;       /* 指向下一节点       */
};
typedef struct stack_node stack_list; /* 串列新型态     */
typedef stack_list *link;         /* 串列指标新型态     */

link operand  = NULL;             /* 运算元栈指标     */

/* ---------------------------------------- */
/*  栈资料的存入                          */
/* ---------------------------------------- */
link push(link stack,int value)
{
   link new_node;                 /* 新节点指标         */

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
/*  是否是运算子                            */
/* ---------------------------------------- */
int isoperator(char op)
{
   switch ( op )
   {
      case '+':
      case '-':
      case '*':
      case '/': return 1;         /* 是运算子           */
      default:  return 0;         /* 不是运算子         */
   }
}

/* ---------------------------------------- */
/*  计算二元表达式的值                      */
/* ---------------------------------------- */
int get_value(int op,int operand1,int operand2)
{
   switch ( (char) op )
   {
      case '*': return ( operand2 * operand1 );
      case '/': return ( operand2 / operand1 );
      case '+': return ( operand2 + operand1 );
      case '-': return ( operand2 - operand1 );
   }
}

/* ---------------------------------------- */
/*  主程式: 输入后序表达式后, 计算其值.     */
/* ---------------------------------------- */
void main()
{
   char exp[100];                 /* 表达式字符串变数     */
   int operand1 = 0;              /* 前运算元变数       */
   int operand2 = 0;              /* 后运算元变数       */
   int result = 0;                /* 计算结果变数       */
   int pos = 0;                   /* 目前表达式位置     */

   printf("请输入后序表达式 ==> ");
   gets(exp);                     /* 读取表达式         */
   printf("后序表达式[%s]的结果是 ",exp);
   /* 剖析表达式字符串回路 */
   while ( exp[pos] != '\0' && exp[pos] != '\n' )
   {
      if ( isoperator(exp[pos]) ) /* 是不是运算子       */
      {
         /* 从栈取出一运算子和两运算元 */
         operand = pop(operand,&operand1);
         operand = pop(operand,&operand2);
         /* 计算取出运算子和元的值后, 存入栈 */
         operand = push(operand,
                        get_value(exp[pos],operand1,operand2));
      }
      else
         /* 是运算元, 存入运算元栈 */
         operand = push(operand,exp[pos]-48);
      pos++;                      /* 下一字符串位置       */
   }
   operand = pop(operand,&result); /* 取出结果          */
   printf(" %d\n",result);        /* 印出结果           */
}
