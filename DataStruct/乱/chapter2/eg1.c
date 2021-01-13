#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
/*传入数组，将之重新排序 */
ElemType* sort(ElemType* A,int m,int n)
{
    ElemType* B = (ElemType*)malloc((n+m)*sizeof(int));
    ElemType* r = B;        //r指向B表中的最后一个元素
    ElemType* p = A;        //p指向第一个递增序列的第一个元素
    ElemType* q = A+m;      //q指向第二个递增序列的第一个元素
    while (p!=(A+m)&&q!=(A+m+n))
    {
        if (*p<*q)  *r++ = *p++;    //将值赋给B序列并使的两个指针加一
        else    *r++ = *q++;
    }
    if(p==(A+m)) 
        while (q!=(A+m+n))
            *r++ = *q++;
    else
        while (p!=(A+m))
            *r++ = *p++;
    if(r==(B+m+n)) return B;        //完全排好序之后返回 
}

int main()
{
    int A[7] = {1,2,3,4,2,3,4};
    int* b = sort(A,4,3);
    for(int i=0;i<7;i++) printf("%5d",*(b+i));

    return 0;
}