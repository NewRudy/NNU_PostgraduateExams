/* ======================================== */
/*    程式实例: 12_5_1.cpp                  */
/*    堆叠类别实作 - 阵列                   */
/* ======================================== */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define MAXSTACK 100              /* 堆叠的最大容量     */

class stack                       /* stack类别宣告      */  
{
private:
   int data[MAXSTACK];            /* 宣告堆叠阵列       */
   int top;                       /* 堆叠指标           */
public:
   stack() { top = -1; }          /* 建构函数           */
   ~stack() { }                   /* 除构函数           */
   int isEmpty();                 /* 成员函数宣告       */
   int push(int);
   int pop();
};

/* ---------------------------------------- */
/*  成员函数: 检查堆叠是否是空的            */
/* ---------------------------------------- */
int stack::isEmpty()
{
   if ( top == -1 )               /* 检查top指标        */
      return 1;                   /* 是空的             */
   else
      return 0;                   /* 不是空的           */
}

/* ---------------------------------------- */
/*  成员函数: 将资料存入堆叠                */
/* ---------------------------------------- */
int stack::push(int d)
{
   if ( top >= MAXSTACK )         /* 是否超过堆叠容量   */
     return -1;                   /* 存入失败           */
   else
   {
      top++;                      /* 堆叠指标加一       */
      data[top] = d;              /* 存入堆叠           */
      return 1;                   /* 存入成功           */
   }
}

/* ---------------------------------------- */
/*  成员函数: 从堆叠取出资料                */
/* ---------------------------------------- */
int stack::pop()
{
   int temp;
   if ( isEmpty() )                /* 是否堆叠是空      */
      return -1;                   /* 取出失败       */
   else
   {

      temp = data[top];            /* 取出资料       */
      top --;                      /* 堆叠指标减一   */
      return temp;                 /* 堆叠取出       */
   }
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
