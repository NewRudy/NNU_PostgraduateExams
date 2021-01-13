#include <stdio.h>
//约瑟夫环问题
int main()
{
    int n,m;
    printf("Enter n,m:");
    scanf("%d%d",&n,&m);
    int arr[100] = {0};     //arr是用来判断每个元素出队了没
    int i = 0,j =0,cur = 0;     //cur是标记这个元素是否已经出列
    while (i<n-1)       //n-1个人出列
    {
        j = 0;
        while (j<m-1)       //数数，数到m-1
        {
            if(arr[cur] == 0)
                ++j;
            cur = (cur+1)%n;
        }
        while(arr[cur]!=0)      //第m个cur==0的数
            cur = (cur+1)%n;
        arr[cur] = 1;       //出列
        ++i;
    }
    for (i = 0; i < n; i++)         //找到唯一没有出列的人
    {
        if(arr[i]==0)
            break;
    }
    printf("result is %d",++i);
    return 0;
}