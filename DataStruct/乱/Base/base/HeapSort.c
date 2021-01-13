#include<stdio.h>
#include<stdlib.h>

void output(int *arr,int n)       //输出数组
{
    printf("\nThe arr is :\n");
    for(int i=0;i<n;++i)
        printf("\t%d",arr[i]);
}
void sift(int *r,int low,int high)          //构建大顶堆，有点像快速排序
{
    int i=low,j=2*i;                        //现在j恰好是i的左孩子
    int temp = r[i];
    while (j<=high)
    {
        if(j<high&&r[j]<r[j+1])     ++j;    //j现在是最大的孩子
        if(temp<r[j])                       //如果根节点小于最大的孩子则交换
        {
            r[i] = r[j];
            i = j;
            j = 2*i;
        }
        else    break;          //最理想的情况
    }
    r[i] = temp;
}
void heapsort(int *r,int n)     //堆排序
{
    int i,temp;
    for(i=n/2;i>=0;--i)         //先左边一半构建堆，再一个一个加入
        sift(r,i,n);
    for(i=n;i>=1;--i)           //一个一个把根节点返回并赋值给暂未排序数组的最后位置
    {
        temp = r[0];
        r[0] = r[i];
        r[i] = temp;
        sift(r,0,i-1);          //少了根节点之后堆重新排序
    }
}
int main()
{
    int n;                         //构建一个n长度的随机数组
    printf("Enter your n:\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;++i)
        arr[i] = rand()%101;       //返回一个1到100的随机数
    output(arr,n);
    heapsort(arr,n-1);
    printf("\n\nheapsort:\n");
    output(arr,n);

    return 0;
}