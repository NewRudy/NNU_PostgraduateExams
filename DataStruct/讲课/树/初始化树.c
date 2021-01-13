/*
 * @Author: wutian 
 * @Date: 2020-07-19 11:43:49 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-07-19 20:12:38
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{        //结点结构
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
        r->left = init(r->left);        //递归的来构建左子树
    else
        r->left = 0;
    printf("是否输入右节点(0为否)：\n");
    scanf("%d",&judge);
    if(judge)
        r->right = init(r->right);      //递归的的来建立右子树
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
    printf("r:\n");
    preOrder(r);
}