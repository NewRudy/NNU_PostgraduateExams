#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void allrange(char *str,int k,int m)
{
    if(k==m)
    {
        static int i = 1;
        printf("arr %d:\t%s\n",i++,str);
        return;
    }
    for(int j=k;j<m;++j)
    {
        swap(str+j,str+k);
        allrange(str,k+1,m);        //对k到m进行全排列
        swap(str+j,str+k);
    }
}
int main()
{
    int m;
    printf("Enter your m:\n");
    scanf("%d",&m);
    char *str = (char*)malloc(sizeof(char)*m);
    printf("Enter your str:\n");
    scanf("%s",str);
    printf("Your str is %s.\n",str);
    allrange(str,0,m);
    
    return 0;
}