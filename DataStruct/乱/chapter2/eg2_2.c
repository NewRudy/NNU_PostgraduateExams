#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
//顺序表结构体
typedef struct SList
{
    ElemType data[100];
    int length;
}SList;

//删除元素
int delete(SList* S,int p,ElemType* e)
{
    *e = S->data[p];
    for(int i=p;i<S->length-1;i++)
        S->data[i] = S->data[i+1];
    S->length--;
    if(*e) return 1;
    else return 0;
}
