#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,i,m;      //num表示开始的数，i表示进制
    char stack[100];
    int top=-1;      //初始化栈
    printf("Enter num and i:\n");
    scanf("%d%d",&num,&i);
    while(num){
        m = num%i;
        if(m>=10)
            switch(m){
                case 10:
                    stack[++top] = 'A';
                    break;
                case 11:
                    stack[++top] = 'B';
                    break;
                case 12:
                    stack[++top] = 'C';
                    break;
                case 13:
                    stack[++top] = 'D';
                    break;
                case 14:
                    stack[++top] = 'E';
                    break;
                case 15:
                    stack[++top] = 'F';
                    break;
                default:
                    printf("m is not right.\n");
            }
        else
            stack[++top] = m + '0';
        num /= i;
    }
    printf("result:\n");
    while(top!=-1)
        printf("%c",stack[top--]);
}