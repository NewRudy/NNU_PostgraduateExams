#include<stdio.h>
#include<stdlib.h>
//假设该多边形为凸多边形，将该图形分为n-2个三角形
//新建数据结构
typedef struct 
{
    double x;
    double y;
}point;
void input(point *p,int n)      //按多边形的顺时针顺序输入n个点
{
    for(int i=0;i<n;++i)
    {
        printf("Enter the x of %d:\n",i+1);
        scanf("%lf",&p[i].x);
        printf("Enter the y of %d:\n",i+1);
        scanf("%lf",&p[i].y);
    }
}
double area(point first,point mid,point rear)       //输入三个点计算一个三角形的面积
{
    mid.x -= first.x;
    mid.y -= first.y;
    rear.x -= first.x;
    rear.y -= first.y;
    double result = (mid.x*rear.y-mid.y*rear.x)/2;
    if(result<0)
        result = -result;
    return result;
}
int main()
{
    int n;
    printf("Enter your n:\n");
    scanf("%d",&n);
    point *p = (point*)malloc(sizeof(point)*n);
    input(p,n);
    double sum=0;
    for(int i=2;i<n;++i)
        sum += area(p[i-2],p[i-1],p[i]);    //逐个三角形计算面积
    printf("The result is %.2lf.\n",sum);

    return 0;
}
