#include<stdio.h>
#include<stdlib.h>

void swap(char *a,char *b)      //交换函数
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void allrange(char *str,int k,int m)        //排列输出
{
    if(k==m)        //结束条件
    {
        static int s = 1;
        printf("the %d arr:\t%s\n",s++,str);
        return;
    }
    for(int i=k;i<m;++i)    //
    {
        swap(str+k,str+i);
        allrange(str,k+1,m);
        swap(str+k,str+i);
    }
}
void combine(char *str,int m,char *result,int r,int R)
{
    if(r==0)
    {
        result[R] = '\0';
        allrange(result,0,R);
        return;
    }
    for(int i=m;i>=r;--i)
    {
        result[r-1] = str[i-1];
        combine(str,i-1,result,r-1,R);
    }
}
int main()
{
    int m,n;
    printf("Enter your m,n:\n");
    scanf("%d%d",&m,&n);
    char *str = (char*)malloc(sizeof(char)*m);
    printf("Enter your str:\n");
    scanf("%s",str);
    getchar();
    char *result = (char*)malloc(sizeof(char)*n);
    printf("Begin:\n");
    combine(str,m,result,n,n);

    return 0;
}