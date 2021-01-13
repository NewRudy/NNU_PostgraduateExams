/* ======================================== */
/*    程式实例: 12_5_2.cpp                  */
/*    堆叠类别实作 - 串列                   */
/* ======================================== */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct stack_node                 /* 堆叠的结构宣告     */
{
   int data;                      /* 堆叠资料           */
   stack_node *next;              /* 指向下一节点       */
};

class stack                       /* stack类别宣告      */  
{
private:
   stack_node *top;               /* 堆叠指标           */
public:
   stack() { top = NULL; }        /* 建构函数           */
   ~stack() { }                   /* 除构函数           */
   int isEmpty();                 /* 成员函数宣告       */
   void push(int);
   int pop();
};

/* ---------------------------------------- */
/*  成员函数: 检查堆叠是否是空的            */
/* ---------------------------------------- */
int stack::isEmpty()
{
   if ( top == NULL )             /* 检查top指标        */
      return 1;                   /* 是空的             */
   else
      return 0;                   /* 不是空的           */
}

/* ---------------------------------------- */
/*  成员函数: 将资料存入堆叠                */
/* ---------------------------------------- */
void stack::push(int d)
{
   /* 配置节点记忆体 */
   stack_node *new_node = new stack_node; 

   new_node->data = d;            /* 建立节点内容       */
   new_node->next = top;          /* 新节点指向原开始   */
   top = new_node;                /* 新节点成为堆叠开始 */
}

/* ---------------------------------------- */
/*  成员函数: 从堆叠取出资料                */
/* ---------------------------------------- */
int stack::pop()
{
   stack_node *node;              /* 指向堆叠顶端       */
   int temp;

   if ( !isEmpty() )              /* 堆叠是否是空的     */
   {
      node = top;                 /* 指向堆叠顶端       */
      top = top->next;            /* 堆叠指标指向下节点 */
      temp = node->data;          /* 取出资料           */
      delete node;                /* 释回节点记忆体     */
      return temp;                /* 堆叠取出           */
   }
   else
      return -1;                  /* 传回堆叠是空的     */
}

/* ---------------------------------------- */
/*  主程式: 洗牌後, 将牌发给四个人.         */
/*     红心: 阵列  0 - 12                   */
/*     方块: 阵列 13 - 25                   */
/*     梅花: 阵列 26 - 38                   */
/*     黑桃: 阵列 39 - 51                   */
/* ---------------------------------------- */
void main()
{
   stack playcard;
   int card[52];                  /* 朴克牌阵列     */
   int pos;                       /* 牌代码         */
   int i,temp;
   long temptime;
   
   srand(time(&temptime) % 60);   /* 使用时间初始乱数 */
   for ( i = 0; i < 52; i++ )
      card[i] = 0;                /* 清除朴克牌阵列 */
   i = 0;
   while ( i != 52 )              /* 洗牌回路       */
   {
      pos = rand() % 52;          /* 乱数取值0-51   */
      if ( card[pos] == 0 )       /* 是否是未洗牌   */
      {
         playcard.push(pos);      /* 存此张牌进堆叠 */
         card[pos] = 1;           /* 设定此张牌洗过 */
         i++;                     /* 下一张牌       */
      }
   }
   cout << "    1      2      3      4 \n";
   cout << " ==========================\n";
   for ( i = 0; i < 5; i++ )      /* 发牌给四人的回路 */
   {
      temp = playcard.pop();      /* 取出堆叠资料   */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = playcard.pop();      /* 取出堆叠资料   */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = playcard.pop();      /* 取出堆叠资料   */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = playcard.pop();      /* 取出堆叠资料   */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      cout << "\n";               /* 换行           */
   }
}

