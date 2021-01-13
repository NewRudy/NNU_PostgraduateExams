#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void combine(char *str,char *result,int m,int r,int R)       //从str的m个字符中找r个字符的子集
{
    if(r==0)        //结束条件
    {
        result[R] = '\0';
        printf("%s\n",result);
        return;
    }
    for(int i=m;i>=r;--i)       //每次的第一个字符都不一样，但是不能小于r
    {
        result[r-1] = str[i-1];     //从后往前找子集
        combine(str,result,i-1,r-1,R);
    }
}
int main()
{
    char str[20],result[20];
    printf("Enter your str:\n");
    scanf("%s",str);
    for(int i=1;i<=strlen(str);++i)
        combine(str,result,strlen(str),i,i);

    return 0;
}