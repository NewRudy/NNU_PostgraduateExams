#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int* a, int n) {        //选择排序
  for (int i=0;i<n;++i) {   //逐个进行交换
    int ith = i;
    for (int j=i+1;j<n;++j)      //找到未排序的最小元素下标
      if (a[j]<a[ith])
        ith = j;
    int t = a[i];       //交换
    a[i] = a[ith];
    a[ith] = t;
  }
}
void bubble_sort(int *a, int n){    //冒泡排序
  int flag = 1;   //flag等于1表示序列尚未排完
  while(flag){    //尚未排完的情况
    flag = 0;
    for (int i=0;i<n;++i){
      if (a[i]>a[i+1]){
        flag = 1;   //存在前一个数比后一个大的情况
        int t = a[i];
        a[i] = a[i+1];
        a[i+1] = t;
      }
    }
  }
}
void bubble_sort2(int* a,int n){		//冒泡排序
	int flag,temp;
    for(int i=n-1;i>=1;--i){		//从大到小进行确定
        flag = 1;
        for(int j=1;j<=i;++j){		//找到最大的数，放在后面
            if(a[j-1]>a[j]){
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                flag = 0;
            }
        }
        if(flag)		//flag没有改变，代表一次没有交换，已完成排序
            return;
    }
}
void insertion_sort(int* a, int n){     //插入排序
  for (int i=1;i<n;++i){
    int key = a[i];   //插入元素
    int j = i-1;
    while(j>=0&&a[j]>key){    //从后往前找到插入的位置
      a[j+1] = a[j];
      --j;
    }
    a[j+1] = key;
  }
}
void quick_sort(int* arr,int left,int right){   //快速排序
  if(left>=right)   //结束条件
    return;
  int i=left,j=right,temp=arr[left];
  while(i<j){
    while(i<j&&arr[j]>=temp)		//从后往前找到第一个交换的位置
      --j;
    arr[i] = arr[j];
    while(i<j&&arr[i]<=temp)
      ++i;
    arr[j] = arr[i];
  }
  arr[i] = temp;
  quick_sort(arr,left,i-1);
  quick_sort(arr,i+1,right);
}
void output(int* arr,int n){        //输出队列
    printf("arr:\n");
    for(int i=0;i<n;++i)
        printf("%d\t",arr[i]);
    printf("\n");
}
int max(int* arr,int n){		//返回最大值
	if(n==1)
      return arr[0];
  int temp = max(arr,n-1);
  return temp>arr[n-1]?temp:arr[n-1];
}
int sum(int* arr,int n){    //返回总数
  if(n==1)
    return arr[0];
  return sum(arr,n-1)+arr[n-1];
}
float average(int* a,int n){		//求平均值
    if(n==1)
        return a[0];
    return (a[n-1]+average(a,n-1)*(n-1))/n;
}
int main(){
    int arr[10];
    srand(time(0));     //随机种子
    for(int i=0;i<10;++i)      //随机生成队列
      arr[i] = rand()%100;
    output(arr,10);
    quick_sort(arr,0,9);
    output(arr,10);
}