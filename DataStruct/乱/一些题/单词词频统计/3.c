#include<stdio.h>
#include<string.h>
typedef struct _iobuf FILE;

typedef struct      //统计单词词频
{
    char str[20];
    int count;
}word;
int cheak(char ch)      //检查字符是不是字母
{
    if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
        return 1;
    else
        return 0;
}
void staticWord(word *str,char *s)
{
    int temp = 0,i,j;
    char subS[20];
    for(i=0;s[i]!='\0';++i)
    {
        if(!cheak(s[i])) continue;      //如果不是字符就继续读
        j = 0;
        while(cheak(s[i]))      //读取一个单词
        {
            subS[j++] = s[i];
            ++i;
        }
        subS[j] = '\0';     //结尾置为0
        for(j=0;j<temp;++j)     //判断是否是重复的单词
            if(!strcmp(subS,str[j].str))
            {
                str[j].count++;
                break;
            }
        if(j==temp)     //新单词
        {
            strcpy(str[j].str,subS);
            str[j].count = 1;
            ++temp;
        }
    }
    printf("The result has %d words.\n",temp);
    for(i=0;i<temp;++i)     //输出结构
        printf("word:%-10s\tnum:%d\n",str[i].str,str[i].count);
}
int main()
{
    word str[100];
    FILE *fp = fopen("test.txt","r");
    char s[100];
    if(fp!=0)
        fgets(s,100,fp);
    staticWord(str,s);

    return 0;
}