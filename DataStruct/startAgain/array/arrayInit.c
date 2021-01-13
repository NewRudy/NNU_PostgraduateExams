/*
 * @Author: wutian 
 * @Date: 2020-07-06 11:56:07 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-07-06 23:12:50
 * 实现一个大小固定的数组，支持动态增删改查操作
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //数组空间大小

typedef struct array
{
    int p; //装了多少个数
    int *content;
} array;

array* add(array *arr, int num)
{
    if (arr==0||arr->p == MAX - 1)
        return arr;
    arr->content[arr->p] = num;
    ++arr->p;
    return arr;
}
array* delete (array *arr, int num)
{
    if (arr==0||arr->p == 0)
        return arr;
    for (int i = 0; i < arr->p; ++i)
    {
        if (arr->content[i] == num)
        {
            while (i < arr->p)
                arr->content[i] = arr->content[++i];
            --arr->p;
        }
    }
    return arr;
}
array* change(array* arr,int num,int newNum){
    if(arr==0||arr->p==0)
        return arr;
    for(int i=0;i<arr->p;++i){
        if(arr->content[i]==num){
            arr->content[i] = newNum;
            break;
        }
    }
    return arr;
}
int check(array* arr,int num){
    if(arr==0||arr->p==0)
        return 0;
    for(int i=0;i<arr->p;++i)
        if(arr->content[i]==num)
            return 1;
    return 0;
}
void print(array* arr){
    if(arr==0||arr->p==0)
        return;
    printf("\narr:\n");
    for(int i=0;i<arr->p;++i)
        printf("%d\t",arr->content[i]);

}
int main(){
    array* arr;
    arr->p = 0;
    arr->content = (int*)malloc(sizeof(int)*MAX);
    printf("add:\n");
    for(int i=0;i<5;++i)
        add(arr,i);
    print(arr);
    printf("\ndelete:\n");
    delete(arr,3);
    print(arr);
    printf("\nchange:\n");
    change(arr,2,7);
    print(arr);
    printf("\ncheck:\n");
    printf("%d",check(arr,7));
}
