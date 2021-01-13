#include <stdio.h>

int main()
{
    int a[10000];
    int temp,digit,n,i,j;

    scanf("%d",&n);
    a[0] = 1;   //从1开始乘
    digit = 1;  //位数从第一位开始
    for (i=2;i<=n;++i)
    {
        int num = 0;
        for(j=0;j<digit;++j)
        {
            temp = a[j]*i + num;    //将每一个数的每一位数都分别乘以i
            a[j] = temp%10;     //将每一个数的每一位数利用数组进行存储
            num = temp/10;
        }
        if(num)     //判断退出循环后，num的值是否为0
        {
            a[digit] = num%10;
            num /= 10;
            ++digit;
        }
    }
    for(i=digit-1;i>=0;--i)     //倒序输出每一位
        printf("%d",a[i]);
    printf("\n位数 = %d\n",digit);

    return 0;
}