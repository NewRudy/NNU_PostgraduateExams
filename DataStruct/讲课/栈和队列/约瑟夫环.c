#include <stdio.h>
#define N 100
int josef(int n,int m)		//Լɪ�򻷵�ʵ�֣�n���ˣ���m
{
    int a[100];
    for(int i=0;i<n;i++)	//��ʼ��
        a[i]=i+1;
    int i,j,k=0;
    for(i=0;i<n-1;i++)		//ѭ��n�Σ�ÿ�γ���һ��
    {
        j=1;
        while(j<m)		//��������m-1��
        {
            while(a[k]==0)		//�ҵ�������0����
            	k=(k+1)%n;
            j++;		//��һ�δ�������һ����
            k=(k+1)%n;
        }
        while(a[k]==0)      //�ҵ���m����
        	k=(k+1)%n;
        printf("%d ",a[k]);
        a[k]=0;     //���0������
    }
    for(int i=0;i<n;++i)
        if(a[i]!=0)
            return a[i];
}
int main()
{
    
    int i,j,m,n;
    printf("input n and m��\n");
    scanf("%d%d",&n,&m);
    printf("\n output��\n");
    
    printf("result:\t%d",josef(n,m));
    return 0;
}