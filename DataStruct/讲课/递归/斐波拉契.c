#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// 1 1 2 3 5 ������ n
//�ݹ�д��
int function1(int n)        //���n����fib���Ƕ���
{
    if(n==1||n==2)          //��������
        return 1;
    return function1(n-1)+function1(n-2);     //������ϵ
}
//ѭ��д��
int function2(int n){
    int m1,m2,temp;
    m1 = m2 =1;
    for(int i=3;i<=n;++i){
        temp = m1 + m2;
        m1 = m2;
        m2 = temp;
    }
    return m2;
}
//�ݹ��Ż�
int function3(int n,int* arr){
    if(n==1||n==2)          //��������
        return 1;
    if(arr[n]==-1)          //������ϵ
        return function3(n-1,arr)+function3(n-2,arr);
    else
        return arr[n];
}
int main()
{
    int n;
    printf("Enter your n:\n");
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);         //��̬�����ַ��int arr[n]�Ǵ����д��
    memset(arr,-1,(n+1)*sizeof(int));               //memset,���ٸ���������ֵ��ֵ��ͷ�ļ�memory.h
    // for(int i=0;i<=n;++i)
    //     arr[i] = -1;
    printf("�ݹ�����%d\nѭ�������%d\n�ݹ��Ż���%d\n",function1(n),function2(n),function3(n,arr));
}