#include <stdio.h>
//Ԫ��elem��ջ
int push(int* a,int top,int elem){
    a[++top]=elem;
    return top;
}
//����Ԫ�س�ջ
int pop(int * a,int top){
    if (top==-1) {
        printf("��ջ");
        return -1;
    }
    printf("��ջԪ�أ�%d\n",a[top]);
    top--;
    return top;
}
void output(int *a,int top){
    for(int i=0;i<=top;++i)
        printf("%d\t",a[i]);
    printf("\n");
}
int main() {
    int a[100];
    int top=-1;
    int judge,target;
    printf("Enter judge,0 quict,1 ��ջ,2 ��ջ:\n");
    scanf("%d",&judge);
    while(judge){
        if(judge==1){
            printf("��ջ��Enter your target:\n");
            scanf("%d",&target);
            top = push(a,top,target);
            output(a,top);
        }
        else if(judge==2){
            top = pop(a,top);
            output(a,top);
        }
        printf("Enter judge,0 quict,1 ��ջ,2 ��ջ:\n");
        scanf("%d",&judge);
    }
    return 0;
}