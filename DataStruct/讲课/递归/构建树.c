#include <stdio.h>
#include <stdlib.h>
//�ṹ��node
// struct node
// {
//     int n;
//     char s;
//     struct node* a; //ָ��ͬһ����ָ��
// };
//typedef ����˼

typedef struct Node         //���Ľṹ��
{
    char data;
    struct Node* left;
    struct Node* right;
}Node;

//root��ָ�룬��ָ�����޸ģ�**  
Node* function(Node* root){      //������
    //�������ڵ��ֵ
    root = (Node*)malloc(sizeof(Node));
    printf("Enter:\n");
    scanf(" %s",&(root->data));           //����һ��ֵ����root��data
    //������������
    int judge;
    printf("�Ƿ�����������1Ϊ�ǣ�0Ϊ�񣩣�\n");
    scanf(" %d",&judge);
    if(judge)
        root->left = function(root->left);
    else 
        root->left = 0;
    //������������
    printf("�Ƿ�����������1Ϊ�ǣ�0Ϊ�񣩣�\n");
    scanf(" %d",&judge);
    if(judge)
        root->right = function(root->right);
    else 
        root->right = 0;
    
    return root;
}

void print(Node* root){     //�����
    if(!root)           //��������
        return;
    
    print(root->left);
    
    print(root->right);
    printf("%c -> ",root->data);
}

//�����������Ƿ����ĳһ��ֵ
int search(Node* root,char c){      //1.root�������� 2.flag�о�д�鷳��
    if(!root)
        return 0;
    if(root->data == c)
        return 1;
    search(root->left,c);       //return 1;
    search(root->right,c);      //ruturn 1;

    return 0;
}
//����ǰ������������������Ψһ����һ�ö����������ܻ��֤���⣩


int main(){
    Node* root;
    root = function(root);
    print(root);
}