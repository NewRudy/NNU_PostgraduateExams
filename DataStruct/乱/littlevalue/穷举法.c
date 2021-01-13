#include<stdio.h>

void main()
{
    char i,j,k;
    static int count = 1;
    for(i='x';i<='z';++i)
        for(j='x';j<='z';++j)
            for(k='x';k<='z';++k)
                if(i!='x'&&k!='x'&&k!='z'&&i!=j&&j!=k&&i!=k)
                    printf("No.%d\na<==>%c\tb<==>%c\tc<==>%c\n",count++,i,j,k);
    printf("The sum is %d.\n",count-1);
}