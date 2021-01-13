#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;          //节点值
    struct node* left;      //左子树
    struct node* right;     //右子树
}Node;

Node* function(Node* root){   //构建树
    root = (Node*)malloc(sizeof(Node));     //给该节点分配一个空间
    printf("输入该节点的值：\n");
    scanf(" %c",&(root->data));      //如果root为Node类型，用 . ,如果root为Node*类型，用 ->
    int judge = 1;
    printf("是否继续创建左子树(1为yes，0为no)：\n");
    scanf("%d",&judge);
    if(judge)
        root->left = function(root->left);
    else
        root->left = 0;         //0和NULL的区别：NULL和0的值都是一样的，NULL用于指针和对象，0用于数值
    printf("是否继续创建右子树(1为yes，0为no)：\n");
    scanf("%d",&judge);
    if(judge)
        root->right = function(root->right);
    else
        root->right = 0;
    return root;
}

void print1(Node* root){        //前序遍历输出树
    if(!root)           //节点未定义
        return;
    printf("%c -> ",root->data);
    print1(root->left);
    print1(root->right);
}
int search(Node* root,char c){        //在树中寻找是否存在 c 字符
    if(!root)       //节点未定义
        return 0;
    if(root->data==c)   //如果寻找到该值
        return 1;
    search(root->left,c);
    search(root->right,c);
    return 0;           //未找到该值
}
void destory(Node* root){       //销毁树
    free(root);
    root = 0;
}
int main(){
    Node* root;
    printf("开始构建树：\n");
    root = function(root);
    printf("该树的前序遍历为：\n");
    print1(root);
}
