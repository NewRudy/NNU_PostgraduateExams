#include<stdio.h>

void function(int n,char* s,int* i)
{
    if(n==0) return;
    s[*i] = n%10 + '0';
    n /= 10;
    *i += 1;
    function(n,s,i); 
}
int main()
{
    int n;
    int *i = (int *)malloc(sizeof(int));
    *i = 0;
    printf("Enter your n:\n");
    scanf("%d",&n);
    char s[50];
    function(n,s,i);
    printf("The result is :\n");
    for(int j=*i-1;j>=0;--j)
        printf("%c",s[j]);

    return 0;
}