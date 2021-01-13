/*
 * @Author: wutian 
 * @Date: 2020-08-03 17:38:18 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-08-03 20:15:57
 */
#include <stdio.h>
#include <stdlib.h>
#define max 1000        //����ֵ������1000

typedef struct node{        //���������
    int judge;          //�ж��Ƿ�ѡ����
    int data;           //������
    struct node* left,*right;    //ָ����
}node;
int minFunction(node* arr,int n){      //�ҵ������е���Сֵ���±�
    int min = max,i,x;
    for(i=0;i<n;++i){       //����һ��
        if(arr[i].judge!=0)     //δ��ѡ��
            if(min>arr[i].data){
                min = arr[i].data;
                x = i;
            }
    }
    return x;
}
void WPL(node *root,int* sum,int depth)      //����wpl
{
    if(!root)   
        return;
    if(root->right==0&&root->left==0)       //Ҷ�ڵ�
        *sum += depth*(root->data);
    WPL(root->left,sum,depth+1);
    WPL(root->right,sum,depth+1);
}

// �Թ�������ʽ��ӡ��������
void PrintHuffmanTree(node* hufmTree)
{
    if (hufmTree)
    {
        printf("%d", hufmTree->data);
        if (hufmTree->left != 0 || hufmTree->right != 0)        //����Ҷ�ڵ�
        {
            printf("(");
            PrintHuffmanTree(hufmTree->left);
            printf(",");
            PrintHuffmanTree(hufmTree->right);
            printf(")");
        }
    }
}

// �ݹ���й���������
void HuffmanCode(node* hufmTree, int depth)      // depth�ǹ������������
{
    static int code[10];        //������������ÿһ���ı���
    if (hufmTree)
    {
        if (hufmTree->left==0 && hufmTree->right==0)
        {
            printf("ȨֵΪ%d��Ҷ�ӽ��Ĺ���������Ϊ ",hufmTree->data);
            int i;
            for (i=0; i<depth; ++i)
                printf("%d", code[i]);
            printf("\n");
        } else
        {
            code[depth] = 0;            
            HuffmanCode(hufmTree->left, depth+1);
            code[depth] = 1;            
            HuffmanCode(hufmTree->right, depth+1);
        }
    }
}
int main(){
    node arr[50];        //���費������ʮ����㣬��ʾ����
    for(int i=0;i<50;++i){
        arr[i].judge = 0;       //����0��ʾʹ�ù���
        arr[i].data = 0;
        arr[i].left = 0;
        arr[i].right = 0;       //NULL�� 0������
    }
    int n,min,cmin;       //n��ʾ��Ŀ��min��ʾ��Сֵ��cmin��ʾ����Сֵ
    printf("Enter your n:\n");
    scanf("%d",&n);
    int rear = n;
    for(int i=0;i<n;++i){       //�������н��
        printf("Enter arr[%d]->data:\t",i);
        scanf("%d",&(arr[i].data));
        arr[i].judge = 1;       //����1��ʾδʹ�ù�
    }
    for(int i=1;i<n;++i){       //n-1�ξͿ��Թ�����һ������������
        min = minFunction(arr,rear);        //�ҵ���Сֵ�±�
        arr[min].judge = 0;
        cmin = minFunction(arr,rear);       //�ҵ�����Сֵ���±�
        arr[cmin].judge = 0;
        arr[rear].data = arr[min].data+arr[cmin].data;
        arr[rear].judge = 1;
        arr[rear].left = &arr[min];
        arr[rear].right = &arr[cmin];
        rear++;
    }
    --rear;         //rear���ڱ�ʾ���� arr[rear]
    int* sum = (int*)malloc(sizeof(int));       //�����Ȩ·������
    *sum = 0;
    WPL(&arr[rear],sum,0);
    printf("result:\nWPL:%d\n",*sum);
    HuffmanCode(&arr[rear],0);
    PrintHuffmanTree(&arr[rear]);
}
