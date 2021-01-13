
#include <stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//仔细想一想回溯是怎么做的
//全局变量
char str[8][4] = {
        "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
char **result;int i = 0;
//回溯求所有结果
void function(char *temp,int len,int now,char *digits)
{
    //赋值
    if(len==now)
    {
        result[i] = (char*)malloc(sizeof(char)*len);
        for(int j=0;j<len;++j)
            result[i][j] = temp[j];
        result[i][len] = '\0';
        ++i;
    }
    //解空间还没有填满
    else
    {
        int subLen = 3;
        int h = digits[now];
        int val = digits[now]-'2';
        if(val==5||val==7)      subLen = 4;
        for(int j=0;j<subLen;++j)
        {
            temp[now] = str[val][j];
            function(temp,len,now+1,digits);
        }
    }
}
char ** letterCombinations(char * digits, int* returnSize){
    int len=0;      //输入字符串长度
    *returnSize = 0;
    while(digits[len]!=0||digits[len]!='\0')
        ++len;
    if(len==0)      return 0;
    result = (char**)malloc(sizeof(char*)*1000);
    char *temp = (char*)malloc(sizeof(char)*len);
    function(temp,len,0,digits);
    *returnSize = i;
}
int main()
{
    char* digits = "23898";
    int * returnSzie = (int*)malloc(sizeof(int));
    letterCombinations(digits,returnSzie);
    for(int j=0;j<i;++j)
        printf("%s\n",result[j]);
    return 0;
}

