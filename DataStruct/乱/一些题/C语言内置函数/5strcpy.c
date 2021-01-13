#include<stdio.h>

char* strcpy(char *strDes,char *strSrc)
{
    int i;
    for(i=0;strSrc[i]!='\0';++i)
        strDes[i] = strSrc[i];
    strDes[i] = '\0';
    return strDes;
}

int main()
{
    char strDes[20];
    char strSrc[20];
    printf("Enter your str:\n");
    scanf("%s",strSrc);
    char *result = strcpy(strDes,strSrc);
    printf("The result is %s\n",strDes);

    return 0;
}