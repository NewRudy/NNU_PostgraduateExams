#include <stdio.h>

int main()
{
    int a[10000];
    int temp,digit,n,i,j;

    scanf("%d",&n);
    a[0] = 1;   //��1��ʼ��
    digit = 1;  //λ���ӵ�һλ��ʼ
    for (i=2;i<=n;++i)
    {
        int num = 0;
        for(j=0;j<digit;++j)
        {
            temp = a[j]*i + num;    //��ÿһ������ÿһλ�����ֱ����i
            a[j] = temp%10;     //��ÿһ������ÿһλ������������д洢
            num = temp/10;
        }
        if(num)     //�ж��˳�ѭ����num��ֵ�Ƿ�Ϊ0
        {
            a[digit] = num%10;
            num /= 10;
            ++digit;
        }
    }
    for(i=digit-1;i>=0;--i)     //�������ÿһλ
        printf("%d",a[i]);
    printf("\nλ�� = %d\n",digit);

    return 0;
}