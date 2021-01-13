#include <stdlib.h>
#include <stdio.h>
#define maxsize 100
#define NULL 0
#define EOF (-1)
typedef struct _iobuf FILE;

// 定义结点类型
typedef struct btnode
{
    int data;
    struct btnode *lchild,*rchild;
} btnode;
FILE *fp;///使用文件读取数据
 
//二叉树
btnode* creat_bitree()
{
    int a;
    fscanf(fp,"%d",&a);
    btnode *node=NULL;
    if(a!=0)
    {
        node=(btnode *)malloc(sizeof(btnode));
        node->data=a;
        node->lchild =creat_bitree();
        node->rchild =creat_bitree();
    }
    return node;
}
 
//前序遍历
void pre (btnode *bt)
{
    if(bt)
    {
        printf("%d ",bt->data);
        pre(bt->lchild);
        pre(bt->rchild);
    }
 
}
int main()
{
    fp=fopen("bitree_data.txt","r");
    btnode *bt=creat_bitree();
    printf("\n前序遍历：\n");
    pre(bt);
}
