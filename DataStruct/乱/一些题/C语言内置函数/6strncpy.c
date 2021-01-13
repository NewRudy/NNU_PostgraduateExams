#include<stdio.h>

char* strcpy(char *strDes,char *strSrc,int count)
{
    int i;
    for(i=0;i<count;++i)
        strDes[i] = strSrc[i];
    strDes[i] = '\0';
    return strDes;
}

int main()
{
    char strDes[20];
    char strSrc[20];
    int n;
    printf("Enter your str and n:\n");
    scanf("%s%d",strSrc,&n);
    char *result = strcpy(strDes,strSrc,n);
    printf("The result is %s\n",result);

    return 0;
}