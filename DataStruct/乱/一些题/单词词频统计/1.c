#include<stdio.h>
#include<string.h>

int main()
{
    char en[100][81];
    int i,j,num=0,n,state;
    printf("Enter your lines:");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;++i)
        gets(en[i]);
    for(i=0;i<n;++i)
    {
        state = 0;
        for(j=0;en[i][j] !='\0';++j)
            if(en[i][j] == ' ')
                state = 0;
            else if(state==0)
            {
                state = 1;
                ++num;
            }
    }
    printf("The result is %d.\n",num);

    return 0;
}