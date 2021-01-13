/*
 * @Author: wutian 
 * @Date: 2020-07-06 23:26:07 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-07-06 23:58:09
 * 合并两个有序数组
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void print(int* arr,int length){
    printf("\narr:\n");
    for(int i=0;i<length;++i)
        printf("%d\t",arr[i]);
}
//对一个数组进行快速排序
void swag(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int left,int right,int* arr){
    if(left>=right||arr==0)
        return;
    int i,j,value;
    value = arr[left];
    i = left;
    j = right;
    while(i<j){
        while(i<j&&arr[i]<=value)
            ++i;
        while(i<j&&arr[j]>=value)
            --j;
        if(i<j)
            swag(&arr[i],&arr[j]);
    }
    arr[i] = value;
    quickSort(left,i-1,arr);
    quickSort(i+1,right,arr);
}
//合并两个有序数组
int* merge(int* arr1,int* arr2){
    int* result = (int*)malloc(sizeof(int)*MAX*2);
    int p = 0;
    int i,j;
    for(i=0,j=0;i<MAX&&j<MAX;){
        if(arr1[i]<arr2[j])
            result[p++] = arr1[i++];
        else
            result[p++] = arr2[j++];
    }
    if(i==MAX)
        while(j<MAX)
            result[p++] = arr2[j++];
    else
        while(i<MAX)
            result[p++] = arr1[i++];
    return result;
}
int main(){
    int* arr1,* arr2;
    arr1 = (int*)malloc(sizeof(int)*MAX);
    arr2 = (int*)malloc(sizeof(int)*MAX);
    srand(time(0));
    for(int i=0;i<MAX;++i){
        arr1[i] = rand()%100;
        arr2[i] = rand()%100;
    }
    quickSort(0,99,arr1);
    quickSort(0,99,arr2);
    int* result = merge(arr1,arr2);
    print(result,MAX*2);
}