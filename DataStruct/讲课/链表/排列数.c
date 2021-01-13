#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct node{		//节点存储结构
    int data;
    struct node* next;
}node;
int insert(node* p,int i){	//在链表p中按从小到大的顺序插入不相等的整数
    if(!p)
        return false;
    if(!p->next){
        node* temp = (node*)malloc(sizeof(node));	//初始化i
        temp->data = i;
        temp->next = 0;
        p->next = temp;
        return 1;
    }
    node* temp1=p,*temp2=p->next;
    while(temp2&&i>temp2->data){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp2&&i==temp2->data)		//相等的就不插入了
        return false;
    node* temp = (node*)malloc(sizeof(node));	//初始化i
    temp->data = i;
    temp->next = 0;
    if(!temp2)	//应该插入最后个节点
    	temp1->next = temp;
    else{		//中间插入的情况
        temp->next = temp2;
        temp1->next = temp;
    }
    return true;
}
void output(node* p){		//输出链表
	if(!p)
        return;
    p = p->next;
    while(p){
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
	node* p = (node*)malloc(sizeof(node));
    p->next = 0;
    int i;
    printf("Enter i:\n");
    scanf("%d",&i);
    while(i){		//从键盘中读数，为0的情况下退出
        insert(p,i);
        printf("Enter i:\n");
        scanf("%d",&i);
    }
    printf("list:\n");
    output(p);
}