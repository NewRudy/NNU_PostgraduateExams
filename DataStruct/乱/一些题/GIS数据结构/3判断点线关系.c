#include<stdio.h>

typedef struct      //定义点的数据结构 
{
    double x;
    double y;
}point;

int main()
{
    point p,l[2];
    printf("Enter your p:\n");
    scanf("%lf%lf",&p.x,&p.y);
    printf("Enter your l:\n");
    scanf("%lf%lf%lf%lf",&l[0].x,&l[0].y,&l[1].x,&l[1].y);
    l[0].x -= p.x;
    l[0].y -= p.y;
    l[1].x -= p.x;
    l[1].y -= p.y;
    if((l[0].x*l[1].y-l[0].y*l[1].x)==0)
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}
