#include<stdio.h>
#define max(a,b)    a>=b?a:b
#define min(a,b)    a<=b?a:b
typedef struct      //定义线段的结构体
{
    double x1,y1,x2,y2;
}line;
double func(line l1,double x1,double y1)    //判断点是否在线的右边还是左边
{
    x1 -= l1.x1;
    y1 -= l1.y1;
    l1.x2 -= l1.x1;
    l1.y2 -= l1.y1;
    return (x1*l1.y2-y1*l1.x2);
}
void judge(line l1,line l2)
{
    if(max(l1.x1,l1.x2)<min(l2.x1,l2.x2)||max(l2.x1,l2.x2)<min(l1.x1,l1.x2)     //快速排斥实验
        ||max(l1.y1,l1.y2)<min(l2.y1,l2.y2)||max(l2.y1,l2.y2)<min(l1.y1,l1.y2))
        {
            printf("No\n");
            return;
        }
    if(func(l1,l2.x1,l2.y1)*func(l1,l2.x2,l2.y2)>0||func(l2,l1.x1,l1.y1)*func(l2,l1.x2,l2.y2)>0)
        {
            printf("No\n");
            return;
        }
    printf("Yes\n");
    return;
}
int main()
{
    line l1,l2;
    printf("Enter your l1:\n");
    scanf("%lf%lf%lf%lf",&l1.x1,&l1.y1,&l1.x2,&l1.y2);
    printf("Enter your l2:\n");
    scanf("%lf%lf%lf%lf",&l2.x1,&l2.y1,&l2.x2,&l2.y2);
    judge(l1,l2);

    return 0;
}
