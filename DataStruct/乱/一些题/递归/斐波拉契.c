#include<stdio.h>

int function(int n)
{
    if(n==1||n==2)      return 1;
    return function(n-1)+function(n-2);
}
int main()
{
    int n;
    printf("Enter your n:");
    scanf("%d",&n);
    printf("The result is %d",function(n));

    return 0;
}