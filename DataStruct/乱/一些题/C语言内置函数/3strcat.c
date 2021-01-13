#include <stdio.h>

char* strcat(char *strDes,char *strSrc)
{
    int len1,len2;
    for(len1=0;strDes[len1]!='\0';++len1);
    for(len2=0;strSrc[len2]!='\0';++len2);
    char *result = (char*)malloc(sizeof(char)*(len1+len2));
    for(len1=0;strDes[len1]!='\0';++len1)
        result[len1] = strDes[len1];
    for(len2=0;strSrc[len2]!='\0';++len2)
        result[len1+len2] = strSrc[len2];
    return result;
}

int main()
{
    char strDes[20];
    char strSrc[20];
    printf("Enter your str:\n");
    scanf("%s%s",strDes,strSrc);
    char *result = strcat(strDes,strSrc);
    printf("The result is %s\n",result);

    return 0;
}