/*
 * @Author: wutian 
 * @Date: 2020-07-19 15:07:56 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-07-19 17:22:10
 */
#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct node{
    char data;
    struct node* left,* right;
}node;
node* init(node* r){     //初始化二叉树
    if(!r)
        return 0;
    r = (node*)malloc(sizeof(node));
    printf("Enter data:\n");
    scanf(" %c",&r->data);
    int judge;
    printf("是否输入左结点(0为否)：\n");
    scanf("%d",&judge);
    if(judge)
        r->left = init(r->left);
    else
        r->left = 0;
    printf("是否输入右节点(0为否)：\n");
    scanf("%d",&judge);
    if(judge)
        r->right = init(r->right);
    else
        r->right = 0;
    return r;
}
node* init2(char* arr,int n,node* r,int i){        //第二种初始化
    if(!arr||!r||n<1||i>n)      //结束条件
        return 0;
    r = (node*)malloc(sizeof(node));
    r->data = arr[i-1];
    r->left = init2(arr,n,r->left,2*i);
    r->right = init2(arr,n,r->right,2*i+1);
    return r;
}
void preOrder(node* r){     //先序遍历输出
    if(!r)
        return;
    printf("%c -- ",r->data);       //可换成其它操作
    preOrder(r->left);
    preOrder(r->right);
}
void preOrder2(node* r){        //先序遍历，非递归的写法
    if(!r)
        return;
    node* stack[maxsize],*temp;      //栈
    int top = -1;
    stack[++top] = r;       //入栈
    while(top!=-1){
        temp = stack[top--];
        printf("%c -- ",temp->data);
        if(temp->right)     //右结点先入栈
            stack[++top] = temp->right;
        if(temp->left)
            stack[++top] = temp->left;
    }
}
void preOrder3(node* r){        //先序遍历，非递归的第二种写法
    if(!r)
        return;
    node* stack[maxsize],*temp = r;      //栈
    int top = -1;
    while(temp||top!=-1){
        if(temp){
            printf("%c -- ",temp->data);
            stack[++top] = temp;
            temp = temp->left;
        }
        else{
            temp = stack[top--];
            temp = temp->right;
        }
    }
}
void inOrder(node* r){      //中序遍历，递归写法
    if(!r)
        return;
    inOrder(r->left);
    printf("%c -- ",r->data);
    inOrder(r->right);
}
void inOrder2(node* r){     //中序遍历，非递归写法
    if(!r)
        return;
    node* stack[maxsize],*temp = r;      //栈
    int top = -1;
    while(temp||top!=-1){
        if(temp){       //temp 不为空，则将其入栈并遍历左子树
            stack[++top] = temp;
            temp = temp->left;
        }
        else{       //temp 为空，表面左子树遍历完成，开始遍历上一层结点的右子树
            temp = stack[top--];
            printf("%c -- ",temp->data);
            temp = temp->right;
        }
    }    
}
void postOrder(node* r){        //后序遍历
    if(!r)
        return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%c -- ",r->data);
}
void postOrder2(node* r){       //后序遍历，非递归实现
    if(!r)
        return;
    node* stack1[maxsize],* stack2[maxsize],* temp = r;      //需要两个栈
    int top1 = -1,top2 = -1;
    while(top1!=-1||temp){
        while(temp){
            stack2[++top2] = temp;
            stack1[++top1] = temp;
            temp = temp->right;
        }
        if(top1!=-1){
            temp = stack1[top1--];
            temp = temp->left;
        }
    }
    while(top2!=-1)
        printf("%c -- ",stack2[top2--]->data);
}
void hierOrder(node* r){        //层次遍历
    if(!r)
        return;
    node* queue[maxsize],*temp;       //初始化一个队列
    int front = 0,rear = 0;
    queue[++rear] = r;
    while(front!=rear){     //队列不空
        temp = queue[++front];
        printf("%c -- ",temp->data);
        if(temp->left)
            queue[++rear] = temp->left;
        if(temp->right)
            queue[++rear] = temp->right;
    }
}
int main(){
    node* r;        //初始化二叉树
    int judge;
    char arr[7] = {'1','2','3','4','5','6','7'};
    printf("Enter the num of init:\n");
    scanf("%d",&judge);
    if(judge==1)
        r = init(r);
    else
        r = init2(arr,7,r,1);
    int n;
    printf("Enter n(n means The traversal order):\n");
    scanf("%d",&n);
    printf("r:\n");
    switch(n){
        case 1:
            preOrder(r);
            printf("\n-------------------------\n");
            preOrder2(r);
            printf("\n-------------------------\n");
            preOrder3(r);
            break;
        case 2:
            inOrder(r);
            printf("\n-------------------------\n");
            inOrder2(r);
            printf("\n-------------------------\n");
            break;
        case 3:
            postOrder(r);
            printf("\n-------------------------\n");
            postOrder2(r);
            break;
        case 4:
            hierOrder(r);
            break;
        default:
            printf("n is one of 1,2,3,4\n");
    }
}