/*
 * @Author: wutian 
 * @Date: 2020-07-19 11:43:49 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-07-19 20:12:38
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{        //���ṹ
    char data;
    struct node* left,* right;
}node;
node* init(node* r){     //��ʼ��������
    if(!r)
        return 0;
    r = (node*)malloc(sizeof(node));
    printf("Enter data:\n");
    scanf(" %c",&r->data);
    int judge;
    printf("�Ƿ���������(0Ϊ��)��\n");
    scanf("%d",&judge);
    if(judge)
        r->left = init(r->left);        //�ݹ��������������
    else
        r->left = 0;
    printf("�Ƿ������ҽڵ�(0Ϊ��)��\n");
    scanf("%d",&judge);
    if(judge)
        r->right = init(r->right);      //�ݹ�ĵ�������������
    else
        r->right = 0;
    return r;
}
node* init2(char* arr,int n,node* r,int i){        //�ڶ��ֳ�ʼ��
    if(!arr||!r||n<1||i>n)      //��������
        return 0;
    r = (node*)malloc(sizeof(node));
    r->data = arr[i-1];
    r->left = init2(arr,n,r->left,2*i);
    r->right = init2(arr,n,r->right,2*i+1);
    return r;
}
void preOrder(node* r){     //����������
    if(!r)
        return;
    printf("%c -- ",r->data);       //�ɻ�����������
    preOrder(r->left);
    preOrder(r->right);
}
int main(){
    node* r;        //��ʼ��������
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