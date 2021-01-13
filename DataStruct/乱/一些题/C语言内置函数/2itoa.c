#include<stdio.h>

void itoa(int n,char *s)
{
    int len=0,i=0;
    char temp;
    while(n)
    {
        s[len++] = n%10+'0';
        n /= 10;
    }
    s[len--] = '\0';
    while(i<len)
    {
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
        ++i;
        --len;
    }
}

int main()
{
    int n;
    char s[20];
    printf("Enter your n:\n");
    scanf("%d",&n);
    itoa(n,s);
    printf("The result is %s.\n",s);

    return 0;
}