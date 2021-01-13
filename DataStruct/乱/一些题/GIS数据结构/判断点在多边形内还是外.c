#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y)    (x)<(y)?(x):(y)
#define MAX(x,y)    (x)>(y)?(x):(y)

typedef struct 
{
    double x,y;
}point;
double function(point p,point left,point right)     //三个点的叉乘结果，判断点p与left和right的线段的关系
{
    p.x -= left.x;
    p.y -= left.y;
    right.x -= left.x;
    right.y -= left.y;
    return p.x*right.y-p.y*right.x;     //返回叉乘结果
}
void main()
{
    int n,i,j;      //n为多边形的点数
    printf("Enter your n:\n");
    scanf("%d",&n);
    point *polygon = (point*)malloc(sizeof(point)*n);       //存储多边形的点
    printf("Enter your points:\n");
    for(i=0;i<n;++i)        //按顺序输入点
    {
        printf("NO.%d\n",i);
        scanf("%lf%lf",&polygon[i].x,&polygon[i].y);
    }
    point p;        //判断得点
    printf("Enter your p:\n");
    scanf("%lf%lf",&p.x,&p.y);
    for(i=0;i<n;++i)        //判断点是否在边上
    {
        j = i+1;
        if(i==n-1)  j = 0;      //最后一条线段的情况
        if(function(p,polygon[i],polygon[j])==0)        //叉乘为0，点在线段上
        {
            printf("p is not in the polygon.\n");
            return;
        }
    }
    int sum = 0;        //sum为交点个数
    for(i=0;i<n;++i)
    {
        j = i+1;
        if(i==n-1) j = 0;
        int a = MIN(polygon[i].x,polygon[j].x);
        int b = MAX(polygon[i].x,polygon[j].x);
        if(a>p.x||b<p.x)      //投影实验
            continue;
        if(polygon[i].x<polygon[j].x)
            if(function(p,polygon[i],polygon[j])<0)         //叉乘为正，角度为正，现在就有交点
                ++sum;
        else if(polygon[i].x>polygon[j].x)
            if(function(p,polygon[j],polygon[i])<0)
                ++sum;
    }
    if(sum%2!=0)
        printf("p is in the polygon.\n");
    else
        printf("p is not in the polygon.\n");
}