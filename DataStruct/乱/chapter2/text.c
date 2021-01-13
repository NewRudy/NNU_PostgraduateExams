#include<stdio.h>

int main(void)
{
    //普通结构型
    typedef struct 
    {
        int a;
        char b;
        float c;
    }TypeA;
    
    //链表结点
    typedef struct Node
    {
        int data;        //数据域，int可以改
        struct  Node *next;     //指针域，指向下一个结点
    }Node;

    //二叉树结点
    typedef struct BTNode
    {
        int data;       //数据域，默认是int型
        struct BTNode *lchild;      //指向左孩子结点指针
        struct BTNode *rchild;      //指向右孩子结点指针
    }BTNode;

    //二叉树制作新结点
    //第一种：BTNode BT;
    BTNode *BT;
    BT=(BTNode*)malloc(sizeof(BTNode));
}   
    
