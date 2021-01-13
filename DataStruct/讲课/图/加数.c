#include <stdio.h>

void sum(int i,int n,int* s){     //计算前n的自然数的和
    if(i>n)
        return;
    *s += i;
    sum(i++,n,s);
}
