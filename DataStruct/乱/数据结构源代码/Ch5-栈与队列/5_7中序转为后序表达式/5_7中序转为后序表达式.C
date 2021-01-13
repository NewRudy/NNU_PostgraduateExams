/* ======================================== */
/*    程式实例: 5_7.c                     */
/*    中序转为后序表达式                    */
/* ======================================== */
#include <stdlib.h>

struct stack_node                 /* 栈的结构宣告      */
{
   int data;                      /* 栈资料            */
   struct stack_node *next;       /* 指向下一节点        */
};
typedef struct stack_node stack_list; /* 串列新型态      */
typedef stack_list *link;         /* 串列指标新型态      */

link operator = NULL;             /* 运算子栈指标      */

/* ---------------------------------------- */
/*  栈资料的存入                          */
/* ---------------------------------------- */
link push(link stack,int value)
{
   link new_node;                 /* 新节点指标          */

   /* 配置节点记忆体 */
   new_node = ( link ) malloc(sizeof(stack_list));
   if ( !new_node )
   {
      printf("记忆体配置失败! \n");
      return NULL;                /* 存入失败            */
   }
   new_node->data = value;        /* 建立节点内容        */
   new_node->next = stack;        /* 新节点指向原开始    */
   stack = new_node;              /* 新节点成为栈开始  */
   return stack;
}

/* ---------------------------------------- */
/*  栈资料的取出                          */
/* ---------------------------------------- */
link pop(link stack,int *value)
{
   link top;                      /* 指向栈顶端        */

   if ( stack != NULL )
   {
      top = stack;                /* 指向栈顶端        */
      stack = stack->next;        /* 栈指标指向下节点  */
      *value = top->data;         /* 取出资料            */
      free(top);                  /* 释回节点记忆体      */
      return stack;               /* 传回栈指标        */
   }
   else
      *value = -1;
}

/* ---------------------------------------- */
/*  检查栈是否是空的                      */
/* ---------------------------------------- */
int empty(link stack)
{
   if ( stack == NULL )           /* 是否是空            */
      return 1;                   /* 空的                */
   else
      return 0;                   /* 不是空的            */
}

/* ---------------------------------------- */
/*  运算子                                  */
/* ---------------------------------------- */
int isoperator(char op)
{
   switch ( op )
   {
      case '(':
      case ')':
      case '+':
      case '-':
      case '*':
      case '/': return 1;         /* 是运算子            */
      default:  return 0;         /* 不是运算子          */
   }
}

/* ---------------------------------------- */
/*  运算子的优先权                          */
/* ---------------------------------------- */
int priority(char op)
{
   switch ( op )
   {
      case '*':
      case '/': return 3;
      case '+':
      case '-': return 2;
      case '(': return 1;
      default:  return 0;
   }
}

/* ---------------------------------------- */
/*  主程式: 输入中序表达式后, 转成后序.     */
/* ---------------------------------------- */
void main()
{
   char infix[100];               /* 中序表达式字符串      */
   char result[100];              /* 结果表达式字符串      */
   int op = 0;                    /* 运算子变数          */
   int pos = 0;                   /* 目前表达式位置      */
   int rpos = 0;                  /* 结果表达式位置      */

   printf("请输入中序表达式 ==> ");
   gets(infix);                   /* 读取表达式          */
   while ( infix[pos] != '\0' && infix[pos] != '\n' )
   {
      if ( isoperator(infix[pos]) ) /* 是不是运算子      */
      {
         if ( empty(operator) || infix[pos] == '(' )
            /* 存入运算子至栈 */
            operator = push(operator,infix[pos]);
         else
         {
            if ( infix[pos] == ')' ) /* 处理括号         */
            {
               while ( operator->data != '(' )
               {
                  /* 取出运算子直到是'(' */
                  operator = pop(operator,&op);
                  result[rpos++] = op; /* 存入结果表达式 */
               }
               /* 取出运算子'(' */
               operator = pop(operator,&op);
            }
            else
            {
               /* 比较优先权 */
               while ( priority(infix[pos]) <=
                       priority(operator->data) &&
                       !empty(operator) )
               {
                  /* 取出运算子 */
                  operator = pop(operator,&op);
                  result[rpos++] = op; /* 存入结果表达式 */
               }
               /* 存入运算子至栈 */
               operator = push(operator,infix[pos]);
            }
         }
      }
      else
         result[rpos++] = infix[pos];  /* 存入结果表达式 */
      pos++;
   }
   while ( !empty(operator) )        /* 取出剩下的运算子 */
   {
      operator = pop(operator,&op);    /* 取出运算子     */
      result[rpos++] = op;             /* 存入结果表达式 */
   }
   result[rpos] = '\0';                /* 设定字符串结束   */
   printf("后序表达式是 %s\n",result);
}
