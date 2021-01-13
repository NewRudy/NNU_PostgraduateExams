#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int function(char* str1,char* str2){        //主串str1，子串str2，暴力匹配
    if(!str1||!str2)
        return -1;
    int i=0,j=0,k=0;
    while(str1[i]!='\0'&&str2[j]!='\0'){        //两个字符串都没有到末尾}
        if(str1[i]==str2[j]){
            ++i;
            ++j;
        }
        else{
            k++;
            i=k;
            j=0;
        }
    }
    if(str2[j]=='\0')
        return i-strlen(str2);        //返回子串在主串中的位置
    else
        return -1;
}
void delete(char* str1,int i,int length){		//删除子串
	if(!str1)
        return;
    int j;
    for(j=i;str1[j]!='\0';++j)	//一个一个替代
        str1[j] = str1[j+length];
    str1[j] = '\0';		//末尾变成\0
}
int main(){
    char str1[100],str2[20];
    printf("Enter str1,str2:\n");
    scanf("%s",str1);
    scanf("%s",str2);
    int length = strlen(str2);
    int i = function(str1,str2);
    while(i!=-1){		//找到所有子串并删除；
        delete(str1,i,length);
        i = function(str1,str2);
    }
    printf("result:%s",str1);
}