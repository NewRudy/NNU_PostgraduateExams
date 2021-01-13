#include<stdio.h>
#include<stdlib.h>

//二叉树结点
typedef struct Node
{
    int data;
    struct Node* lchild,* rchild;
}Node;

//新建二叉树
Node* create_bitree()
{
    printf("Enter a number of 0:");
    int e;
    scanf("%d",&e);
    if(e)
    {
        Node* t = (Node*)malloc(sizeof(Node*));
        t->data = e;
        t->lchild = create_bitree();
        t->rchild = create_bitree();
        return t;
    }
    return 0;
}
//前序遍历二叉树
void PreOrderTraverse(Node* B)
{
    if(B)
    {
        printf("%5d",B->data);
        PreOrderTraverse(B->lchild);
        PreOrderTraverse(B->rchild);
    }
}
//中序遍历二叉树
void MidOrderTraverse(Node* B)
{
    if(B)
    {
        MidOrderTraverse(B->lchild);
        printf("%5d",B->data);
        MidOrderTraverse(B->rchild);
    }
}
//后序遍历二叉树
void PostOrderTraverse(Node* B)
{
    if(B)
    {
        PostOrderTraverse(B->lchild);
        PostOrderTraverse(B->rchild);
        printf("%5d",B->data);    
    }
}

int main()
{
    Node * B = create_bitree();
    MidOrderTraverse(B);
    return 0;
}
