#include <stdio.h>
//元素elem进栈
int push(int* a,int top,int elem){
    a[++top]=elem;
    return top;
}
//数据元素出栈
int pop(int * a,int top){
    if (top==-1) {
        printf("空栈");
        return -1;
    }
    printf("弹栈元素：%d\n",a[top]);
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
    printf("Enter judge,0 quict,1 进栈,2 出栈:\n");
    scanf("%d",&judge);
    while(judge){
        if(judge==1){
            printf("进栈，Enter your target:\n");
            scanf("%d",&target);
            top = push(a,top,target);
            output(a,top);
        }
        else if(judge==2){
            top = pop(a,top);
            output(a,top);
        }
        printf("Enter judge,0 quict,1 进栈,2 出栈:\n");
        scanf("%d",&judge);
    }
    return 0;
}