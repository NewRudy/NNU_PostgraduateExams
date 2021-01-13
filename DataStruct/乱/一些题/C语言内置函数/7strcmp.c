#include<stdio.h>

int strcmp(const char*s,const char * t)
{
    for(int i=0;s[i]&&t[i];++i)
    {
        if(s[i]==t[i])
            return i+1;
    }
    return 0;
}

int main()
{
    char s[20];
    char t[20];
    printf("Enter your str:\n");
    scanf("%s%s",s,t);
    printf("The result is %d.\n",strcmp(s,t));

    return 0;
}