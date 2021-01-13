#include <stdio.h>
#include <stdlib.h>
//结构体node
// struct node
// {
//     int n;
//     char s;
//     struct node* a; //指向同一个的指针
// };
//typedef 的意思

typedef struct Node         //树的结构体
{
    char data;
    struct Node* left;
    struct Node* right;
}Node;

//root是指针，对指针有修改，**  
Node* function(Node* root){      //构建树
    //建立根节点的值
    root = (Node*)malloc(sizeof(Node));
    printf("Enter:\n");
    scanf(" %s",&(root->data));           //输入一个值进入root的data
    //建立了左子树
    int judge;
    printf("是否建立左子树（1为是，0为否）：\n");
    scanf(" %d",&judge);
    if(judge)
        root->left = function(root->left);
    else 
        root->left = 0;
    //建立了右子树
    printf("是否建立右子树（1为是，0为否）：\n");
    scanf(" %d",&judge);
    if(judge)
        root->right = function(root->right);
    else 
        root->right = 0;
    
    return root;
}

void print(Node* root){     //输出树
    if(!root)           //结束条件
        return;
    
    print(root->left);
    
    print(root->right);
    printf("%c -> ",root->data);
}

//查找树里面是否存在某一个值
int search(Node* root,char c){      //1.root不存在呢 2.flag感觉写麻烦了
    if(!root)
        return 0;
    if(root->data == c)
        return 1;
    search(root->left,c);       //return 1;
    search(root->right,c);      //ruturn 1;

    return 0;
}
//数组前序遍历和中序遍历可以唯一建立一棵二叉树（可能会出证明题）


int main(){
    Node* root;
    root = function(root);
    print(root);
}