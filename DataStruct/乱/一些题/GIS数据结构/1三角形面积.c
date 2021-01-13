#include<stdio.h>

void print(double *p,int n)
{
    for(int i=0;i<n;++i)
    {
        printf("Enter %d:\n",i);
        scanf("%lf",&p[i]);
    }
}
//两个向量的叉乘结果为三角形面积
int main()
{
    double p1[2],p2[2],p3[2];
    print(p1,2);
    print(p2,2);
    print(p3,2);
    p2[0] -= p1[0];       //计算P1P2向量
    p2[1] -= p1[1];
    p3[0] -= p1[0];       //计算P1P3向量
    p3[1] -= p1[1];
    double result = (p2[0]*p3[1] - p2[1]*p3[0])/2;
    if(result<0)
        result = -result;
    printf("The result is %.2lf.\n",result);

    return 0;
}