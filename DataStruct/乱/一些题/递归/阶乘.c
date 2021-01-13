#include <stdio.h>

int function(int n)
{
    if(n==1)    return 1;
    return n*function(n-1);
}
int main()
{
    int n;
    printf("Enter your n:");
    scanf("%d",&n);
    printf("The result is %d.\n",function(n));
    
    return 0;
}