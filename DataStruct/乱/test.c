#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left,* right;
}node;
int sum(node* root){
	if(!root)
        return 0;
    return sum(root->left)+sum(root->right)+1;
}
int main(){
	int n;
    scanf("%d",&n);
    node arr[100];
    for(int i=0;i<n;++i){
        arr[i].data = 1;  //
        arr[i].left = 0;
        arr[i].right = 0;
    }
    int rear = n,i=0;
    while(rear-1!=i){
        arr[rear].left = &arr[i++];
        arr[rear].right = &arr[i++];
        rear++;
    }
    printf("%d",sum(&arr[rear-1]));
}