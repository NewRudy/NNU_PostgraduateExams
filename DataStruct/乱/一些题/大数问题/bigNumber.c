//两个大数相乘问题
#include<stdio.h>

int main()
{
    long n,m;
    int arr[1000];
    printf("Enter your n,m:");
    scanf("%ld%ld",&n,&m);
    int digit = 0,num = 0,i = 0,temp;
    while (m)
    {
        arr[i++] = m%10;
        m /= 10;
        ++digit;
    }
    for(i=0;i<digit;++i)
    {
        temp = n*arr[i] + num;      //只用了一个数组
        arr[i] = temp%10;
        num = temp/10;
    }
    while(num)
    {
        arr[i++] = num%10;
        num /= 10;
        ++digit;
    }
    --digit;
    while(digit)
        printf("%d",arr[digit--]);
}