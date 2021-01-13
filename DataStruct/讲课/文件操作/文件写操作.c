#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct _iobuf FILE;
#define strmax 10

void reverse(char* str,int k){      //字符数组逆转函数
    if(!str||k<=1)
        return;
    char temp;
    for(int i=0,j=k-1;i<j;){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        ++i;
        --j;
    }
}
int main(){
    srand(time(0));     //生成随机种子
    FILE* fp = fopen("text.txt","a");       //文件打开操作 a  append
    int temp;       //你可以都用temp表示临时变量，然后i，j写循环
    for(int i=0;i<10;++i){      //生成10个随机整数，存储到文件中
        temp = rand()%100;
        char str[10];
        int k = 0;
        printf("%d\t",temp);
        while(temp){        //一个一个将数字转为字符
            str[k++] = temp%10 + '0';       //'1' = 1 + '1'
            temp /= 10;     //减少个位数
        }
        str[k] = '\0';
        reverse(str,k);
        fprintf(fp,"%s\t",str);
    }
    fputc('\n',fp);
}