#include<stdio.h>

//atoi函数
int atoi(char *s)
{
    int result,i;
    for(i=0;s[i]!='\0';++i)
    {
        if(i==0)
            result = s[i]-'0';
        else
        {
            result = result*10+s[i]-'0';
        }
    }
    return result;
}

int main()
{
    char s[20];
    printf("Enter your S:\n");
    scanf("%s",s);
    printf("The result is %d.\n",atoi(s));

    return 0;
}