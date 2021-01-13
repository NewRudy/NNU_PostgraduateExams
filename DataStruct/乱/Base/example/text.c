#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int main(void)
{
    //顺序表结构定义
    typedef struct
    {
        int data[MAXSIZE];
        int length;
    }Sqlist;
    //考试中
    int A[MAXSIZE];
    int length;

    //单链表结点定义
    typedef struct LNode
    {
        int data;   //结点数据域
        struct  LNode *next;    //指向后继结点的指针
    }LNode;
    
    //双链表结点定义
    typedef struct DLNode
    {
        int data;   //结点数据域
        struct DLNode *prior;   //指向前驱结点的指针
        struct DLNode *next;    //指向后继结点的指针
    }DLNode;

    /*
    说明：结点内存中一片又用户分配的空间，只有一个地址显示它的存在，没有显示的名称，因此我们会在分配链表结点
    空间的时候，同时定义一个指针来存储该地址，通常用该指针的名称来作为结点的名称
     */
    LNode *A = (LNode*)malloc(sizeof(LNode));   //A命名了结点和指向该结点的指针
    //指针变量所需的存储空间是系统分配的，不需要用户调用free()函数来释放，只有用户分配的空间才需要用户自己十分


}