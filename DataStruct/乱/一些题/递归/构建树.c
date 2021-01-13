#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;          //�ڵ�ֵ
    struct node* left;      //������
    struct node* right;     //������
}Node;

Node* function(Node* root){   //������
    root = (Node*)malloc(sizeof(Node));     //���ýڵ����һ���ռ�
    printf("����ýڵ��ֵ��\n");
    scanf(" %c",&(root->data));      //���rootΪNode���ͣ��� . ,���rootΪNode*���ͣ��� ->
    int judge = 1;
    printf("�Ƿ��������������(1Ϊyes��0Ϊno)��\n");
    scanf("%d",&judge);
    if(judge)
        root->left = function(root->left);
    else
        root->left = 0;         //0��NULL������NULL��0��ֵ����һ���ģ�NULL����ָ��Ͷ���0������ֵ
    printf("�Ƿ��������������(1Ϊyes��0Ϊno)��\n");
    scanf("%d",&judge);
    if(judge)
        root->right = function(root->right);
    else
        root->right = 0;
    return root;
}

void print1(Node* root){        //ǰ����������
    if(!root)           //�ڵ�δ����
        return;
    printf("%c -> ",root->data);
    print1(root->left);
    print1(root->right);
}
int search(Node* root,char c){        //������Ѱ���Ƿ���� c �ַ�
    if(!root)       //�ڵ�δ����
        return 0;
    if(root->data==c)   //���Ѱ�ҵ���ֵ
        return 1;
    search(root->left,c);
    search(root->right,c);
    return 0;           //δ�ҵ���ֵ
}
void destory(Node* root){       //������
    free(root);
    root = 0;
}
int main(){
    Node* root;
    printf("��ʼ��������\n");
    root = function(root);
    printf("������ǰ�����Ϊ��\n");
    print1(root);
}
