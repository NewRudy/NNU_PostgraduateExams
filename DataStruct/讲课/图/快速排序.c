/*
 * @Author: wutian 
 * @Date: 2020-07-15 16:34:15 
 * @Last Modified by: wutian
 * @Last Modified time: 2020-07-15 20:04:41
 * 快速排序
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swag(int* a,int* b){       //交换两个数
    int temp = *a;      //temp表示临时变量
    *a = *b;
    *b = temp;
}
void quickSort(int* arr,int left,int right){        //快速排序
    if(!arr||left>=right)
        return;
    int i = left,j = right,value = arr[left];
    while(i<j){         //保证value前的数都小于等于value，后面的数都大于等于value
        while(i<j&&arr[j]>=value)
            --j;
        swag(&arr[i],&arr[j]);
        while(i<j&&arr[i]<=value)
            ++i;
        swag(&arr[i],&arr[j]);
    }
    quickSort(arr,left,i-1);        //分治法
    quickSort(arr,i+1,right);
}
void output(int* arr,int n){        //输出数组
    printf("output:\n");
    for(int i=0;i<n;++i)
        printf("%d  ",arr[i]);
    printf("\n-------------------");
}
int main(){
    int n;      //数组长度
    printf("Enter n:\n");
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);     //数组
    srand(time(0));     //产生随机种子
    for(int i=0;i<n;++i)
        arr[i] = rand()%100;        //产生随机数
    output(arr,n);
    quickSort(arr,0,n-1);
    output(arr,n);
}