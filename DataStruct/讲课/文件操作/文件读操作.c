#include <stdio.h>
#include <stdlib.h>
typedef struct _iobuf FILE;

int main(){
    char str[100];      //假设文件中字符串不超过100
    FILE* fp = fopen("text.txt","r");  //r w a
    while(!feof(fp)){
        fgets(str,100,fp);      //中途碰见\n就停止,读取文件中的一行语句
        printf("%s",str);
    }
}