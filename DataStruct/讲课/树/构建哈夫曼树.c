/*
 * @Author: wutian 
 * @Date: 2020-08-03 17:14:08 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-08-03 18:20:12
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 50
typedef struct node
{
    int data;
    struct node *lchild,*rchild;
}node;
void function(node *root,int *sum)      //计算树中有多少个结点
{
    if(!root)   return;
    ++(*sum);
    function(root->lchild,sum);
    function(root->rchild,sum);
}
void main()
{
    int n;
    printf("Enter your n:\n");
    scanf("%d",&n);
    node q[maxsize];        //队列的结点数组
    int front = 0,rear = n;
    for(int i=0;i<n;++i)        //结点初始化
    {
        q[i].data = 1;
        q[i].lchild = 0;
        q[i].rchild = 0;
    }
    while (front != rear-1)             //循环结束以后哈夫曼树的根节点是q[front]
    {
        int m = front;
        int n = (front+1)%maxsize;
        front = (front+2)%maxsize;
        q[rear].data = q[m].data +q[n].data;        //组成一个新的结点
        q[rear].lchild = &q[m];
        q[rear].rchild = &q[n];
        rear = (rear+1)%maxsize;
    }
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    function(&q[front],sum);
    printf("The result is %d.\n",*sum);
}
