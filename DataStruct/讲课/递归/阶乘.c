#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//�ݹ�д��
int function1(int n){			//�������n����n!
    if(n<=2)
    	return n;
    return n*function1(n-1);
}
//ѭ��д��
int function2(int n){
    int sum = 1;
    for(int i=2;i<=n;++i)
        sum *= i;
    return sum;
}
//�ݹ��Ż�
int function3(int n,int* arr){			//�������n����n!
    if(n<=2)
    	return n;
    if(arr[n]==-1)			//����arr�����ʼ��Ϊ-1
    	arr[n] = n*function3(n-1,arr);
	else
    	return arr[n];
}
int main(){
    int n;
    printf("Enter n:\n");
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);         //��̬�����ַ��int arr[n]�Ǵ����д��
    memset(arr,-1,(n+1)*sizeof(int));               //memset,���ٸ���������ֵ��ֵ��ͷ�ļ�memory.h
    // for(int i=0;i<=n;++i)
    //     arr[i] = -1;
    printf("�ݹ�����%d\nѭ�������%d\n�ݹ��Ż���%d\n",function1(n),function2(n),function3(n,arr));
}