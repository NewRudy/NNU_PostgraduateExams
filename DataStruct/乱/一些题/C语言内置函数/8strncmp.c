#include<stdio.h>

int strcmp(const char*s,const char * t,int count)
{
    for(int i=0;i<count&&s[i]&&t[i];++i)
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
    int n;
    printf("Enter your str and n:\n");
    scanf("%s%s%d",s,t,&n);
    printf("The result is %d.\n",strcmp(s,t,n));

    return 0;
}