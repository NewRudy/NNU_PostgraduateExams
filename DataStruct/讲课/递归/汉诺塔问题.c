#include<stdio.h>

//�ݹ�д��
void function1(int n,char A,char B,char C,int* count)
{
    if(n==0)    //��������
        return;
    else
    {
        //֮��Ĺ�ϵ��������n��Բ�̣�f(n)��f(n-1)�Ĺ�ϵ���ǲ���f(n-1)��Բ�̶��Ƶ�b
        // n-1 A B 
        // n A C 
        // n-1 B C
        function1(n-1,A,C,B,count);
        printf("�����Ϊ%d�����Ӵ�%c�Ƶ�%c\n",n,A,C);
        ++(*count);
        function1(n-1,B,A,C,count);
    }
}

int main()
{
    int n;
    printf("Enter your n:\n");
    scanf("%d",&n);
    int* count = (int*)malloc(sizeof(int));
    *count = 0;
    function1(n,'A','B','C',count);
    printf("num:%d",*count);
    return 0;
}
//֮��Ĺ�ϵ��������n��Բ�̣�f(n)��f(n-1)�Ĺ�ϵ���ǲ���f(n-1)��Բ�̶��Ƶ�b
// n-1 A B 
// n A C 
// n-1 B C
//n A B C
//n-1 A C B
//
//n-1 B A C