/*
 * @Author: wutian 
 * @Date: 2020-08-03 17:38:18 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-08-03 20:15:57
 */
#include <stdio.h>
#include <stdlib.h>
#define max 1000        //所有值不超过1000

typedef struct node{        //二叉树结点
    int judge;          //判断是否被选择了
    int data;           //数据域
    struct node* left,*right;    //指针域
}node;
int minFunction(node* arr,int n){      //找到数组中的最小值的下标
    int min = max,i,x;
    for(i=0;i<n;++i){       //遍历一遍
        if(arr[i].judge!=0)     //未被选择
            if(min>arr[i].data){
                min = arr[i].data;
                x = i;
            }
    }
    return x;
}
void WPL(node *root,int* sum,int depth)      //计算wpl
{
    if(!root)   
        return;
    if(root->right==0&&root->left==0)       //叶节点
        *sum += depth*(root->data);
    WPL(root->left,sum,depth+1);
    WPL(root->right,sum,depth+1);
}

// 以广义表的形式打印哈夫曼树
void PrintHuffmanTree(node* hufmTree)
{
    if (hufmTree)
    {
        printf("%d", hufmTree->data);
        if (hufmTree->left != 0 || hufmTree->right != 0)        //不是叶节点
        {
            printf("(");
            PrintHuffmanTree(hufmTree->left);
            printf(",");
            PrintHuffmanTree(hufmTree->right);
            printf(")");
        }
    }
}

// 递归进行哈夫曼编码
void HuffmanCode(node* hufmTree, int depth)      // depth是哈夫曼树的深度
{
    static int code[10];        //数组用来保存每一步的编码
    if (hufmTree)
    {
        if (hufmTree->left==0 && hufmTree->right==0)
        {
            printf("权值为%d的叶子结点的哈夫曼编码为 ",hufmTree->data);
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
    node arr[50];        //假设不超过二十个结点，表示集合
    for(int i=0;i<50;++i){
        arr[i].judge = 0;       //等于0表示使用过了
        arr[i].data = 0;
        arr[i].left = 0;
        arr[i].right = 0;       //NULL与 0的区别
    }
    int n,min,cmin;       //n表示数目，min表示最小值，cmin表示次最小值
    printf("Enter your n:\n");
    scanf("%d",&n);
    int rear = n;
    for(int i=0;i<n;++i){       //输入所有结点
        printf("Enter arr[%d]->data:\t",i);
        scanf("%d",&(arr[i].data));
        arr[i].judge = 1;       //等于1表示未使用过
    }
    for(int i=1;i<n;++i){       //n-1次就可以构建出一个哈夫曼树了
        min = minFunction(arr,rear);        //找到最小值下标
        arr[min].judge = 0;
        cmin = minFunction(arr,rear);       //找到次最小值的下标
        arr[cmin].judge = 0;
        arr[rear].data = arr[min].data+arr[cmin].data;
        arr[rear].judge = 1;
        arr[rear].left = &arr[min];
        arr[rear].right = &arr[cmin];
        rear++;
    }
    --rear;         //rear现在表示根了 arr[rear]
    int* sum = (int*)malloc(sizeof(int));       //就算带权路径长度
    *sum = 0;
    WPL(&arr[rear],sum,0);
    printf("result:\nWPL:%d\n",*sum);
    HuffmanCode(&arr[rear],0);
    PrintHuffmanTree(&arr[rear]);
}
