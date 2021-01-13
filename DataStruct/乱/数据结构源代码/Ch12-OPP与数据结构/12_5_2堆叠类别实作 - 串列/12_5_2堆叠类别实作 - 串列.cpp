/* ======================================== */
/*    ��ʽʵ��: 12_5_2.cpp                  */
/*    �ѵ����ʵ�� - ����                   */
/* ======================================== */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct stack_node                 /* �ѵ��Ľṹ����     */
{
   int data;                      /* �ѵ�����           */
   stack_node *next;              /* ָ����һ�ڵ�       */
};

class stack                       /* stack�������      */  
{
private:
   stack_node *top;               /* �ѵ�ָ��           */
public:
   stack() { top = NULL; }        /* ��������           */
   ~stack() { }                   /* ��������           */
   int isEmpty();                 /* ��Ա��������       */
   void push(int);
   int pop();
};

/* ---------------------------------------- */
/*  ��Ա����: ���ѵ��Ƿ��ǿյ�            */
/* ---------------------------------------- */
int stack::isEmpty()
{
   if ( top == NULL )             /* ���topָ��        */
      return 1;                   /* �ǿյ�             */
   else
      return 0;                   /* ���ǿյ�           */
}

/* ---------------------------------------- */
/*  ��Ա����: �����ϴ���ѵ�                */
/* ---------------------------------------- */
void stack::push(int d)
{
   /* ���ýڵ������ */
   stack_node *new_node = new stack_node; 

   new_node->data = d;            /* �����ڵ�����       */
   new_node->next = top;          /* �½ڵ�ָ��ԭ��ʼ   */
   top = new_node;                /* �½ڵ��Ϊ�ѵ���ʼ */
}

/* ---------------------------------------- */
/*  ��Ա����: �Ӷѵ�ȡ������                */
/* ---------------------------------------- */
int stack::pop()
{
   stack_node *node;              /* ָ��ѵ�����       */
   int temp;

   if ( !isEmpty() )              /* �ѵ��Ƿ��ǿյ�     */
   {
      node = top;                 /* ָ��ѵ�����       */
      top = top->next;            /* �ѵ�ָ��ָ���½ڵ� */
      temp = node->data;          /* ȡ������           */
      delete node;                /* �ͻؽڵ������     */
      return temp;                /* �ѵ�ȡ��           */
   }
   else
      return -1;                  /* ���ضѵ��ǿյ�     */
}

/* ---------------------------------------- */
/*  ����ʽ: ϴ����, ���Ʒ����ĸ���.         */
/*     ����: ����  0 - 12                   */
/*     ����: ���� 13 - 25                   */
/*     ÷��: ���� 26 - 38                   */
/*     ����: ���� 39 - 51                   */
/* ---------------------------------------- */
void main()
{
   stack playcard;
   int card[52];                  /* �ӿ�������     */
   int pos;                       /* �ƴ���         */
   int i,temp;
   long temptime;
   
   srand(time(&temptime) % 60);   /* ʹ��ʱ���ʼ���� */
   for ( i = 0; i < 52; i++ )
      card[i] = 0;                /* ����ӿ������� */
   i = 0;
   while ( i != 52 )              /* ϴ�ƻ�·       */
   {
      pos = rand() % 52;          /* ����ȡֵ0-51   */
      if ( card[pos] == 0 )       /* �Ƿ���δϴ��   */
      {
         playcard.push(pos);      /* ������ƽ��ѵ� */
         card[pos] = 1;           /* �趨������ϴ�� */
         i++;                     /* ��һ����       */
      }
   }
   cout << "    1      2      3      4 \n";
   cout << " ==========================\n";
   for ( i = 0; i < 5; i++ )      /* ���Ƹ����˵Ļ�· */
   {
      temp = playcard.pop();      /* ȡ���ѵ�����   */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = playcard.pop();      /* ȡ���ѵ�����   */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = playcard.pop();      /* ȡ���ѵ�����   */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      temp = playcard.pop();      /* ȡ���ѵ�����   */
      printf(" [%c%2d] ",temp / 13 + 3,temp % 13 + 1);
      cout << "\n";               /* ����           */
   }
}

