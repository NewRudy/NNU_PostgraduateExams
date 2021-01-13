#include <stdio.h>

char* strcat(char *strDes,char *strSrc,int count)
{
    int len1;
    for(len1=0;strDes[len1]!='\0';++len1);
    char *result = (char*)malloc(sizeof(char)*(len1+count));
    for(len1=0;strDes[len1]!='\0';++len1)
        result[len1] = strDes[len1];
    int len2;
    for(len2=0;len2<count;++len2)
        result[len1+len2] = strSrc[len2];
    result[len1+len2] = '\0';
    return result;
}

int main()
{
    char strDes[20];
    char strSrc[20];
    int n;
    printf("Enter your str and n:\n");
    scanf("%s%s%d",strDes,strSrc,&n);
    char *result = strcat(strDes,strSrc,n);
    printf("The result is %s\n",result);

    return 0;
}