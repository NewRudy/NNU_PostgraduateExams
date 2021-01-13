#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct{
    int a;
    int arr[10];
}st;
void swap(int* a, int* b) {     //交换a，b的值
    int tmp = *a; 
    *a = *b;
    *b = tmp;
}
void output(int *arr,int k){        //输出数组的函数
    for(int i=0;i<k;++i)
        printf("%d\t",arr[i]);
    printf("\n");
}
void search(int* arr,int n,int key,int* i){
    for(int j=0;j<n;++j)
        if(arr[j]==key)
            *i = j;
}
void sum(int* a){
    *a += 1;
}
void fum(int a){
    a += 1;
}
int main(){
    int a = 10;     //变量
    int arr[10];    //数组
    st st1;     //结构体变量
    for(int i=0;i<10;++i)       //数组初始化
        arr[i] = i;
    printf("%d\n",*arr);
    printf("%d\n",*(arr+1));  //*(arr+1) == arr[1]
    printf("%d\n",*(arr+2));      //arr[2] == *(arr+2)
    int i=1;
    search(arr,10,5,&i);
    printf("i:%d\n",i);
    int sum1 = 1;
    sum(&sum1);
    printf("sum1:%d\n",sum1);
    fum(sum1);
    printf("sum1:%d\n",sum1);
}