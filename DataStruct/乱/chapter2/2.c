#include<stdio.h>
#include<stdlib.h>

void sort(int R[],int n,int p)
{
    int Tran[p];
    for(int i=0;i<p;i++)
        Tran[i] = R[i];
    for(int i=0;i<n-p;i++)
        R[i] = R[i+p];
    for(int i=0;i<p;i++)
        R[i+n-p] = Tran[i];
}
int main()
{
    int R[9] = {1,2,3,4,5,6,7,8,9};
    sort(R,9,3);
    for(int i=0;i<9;i++)
        printf("%5d",R[i]);

    return 0;
}

/*第二种解法：将第一部分逆序，第二部分逆序，再将第三部分逆序 */