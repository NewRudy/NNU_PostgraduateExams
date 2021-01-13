#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y)    (x)<(y)?(x):(y)
#define MAX(x,y)    (x)>(y)?(x):(y)

void main()
{
    int i=1,j=2;
    int a = MIN(i,j);
    int b = MAX(i,j);
}