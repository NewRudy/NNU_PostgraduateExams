/*
 * @Author: wutian 
 * @Date: 2020-07-06 11:27:08 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-07-06 12:10:00
 * 实现一个动态扩容数组
 */
#include <stdio.h>
#include <stdlib.h>
#define N 100       //初始数组大小

typedef struct array{
    int n;      //数组大小
    int* content;       //数组内容
}array;

//动态扩容数组，传入参数：原数组，扩容大小
array* dynamicExpansion(array* arr,int num){
    if(!arr||num<=0)
        return arr;
    int* temp;      //temp用于将原来的东西复制到新空间
    temp = (int*)malloc(sizeof(int)*(arr->n+num));
    for(int i=0;i<arr->n;++i)
        temp[i] = arr->content[i];
    arr->content = temp;
    arr->n += num;
    return arr;
}
//输出数组
void print(array *arr){
    printf("n:%d\ncontent:",arr->n);
    for(int i=0;i<arr->n;++i)
        printf("%d\t",arr->content[i]);
    printf("\n------------------------\n");
}
int main(){
    array* arr;
    arr->n = N;
    arr->content = (int*)malloc(sizeof(int)*(arr->n));
    for(int i=0;i<arr->n;++i)
        arr->content[i] = i;
    print(arr);
    dynamicExpansion(arr,10);
    print(arr);
}