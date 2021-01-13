#include<stdio.h>
#include<string.h>
typedef struct _iobuf FILE;

typedef struct      //定义一个数据结构包含单词和数量
{
    char str[20];
    int count;
}word;
int cheak(char ch)      //判断一个字符是不是字母
{
    if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
        return 1;
    else
        return 0;
}
int main()
{
    FILE *fp = fopen("E:\\Ctan\\chapter 10\\test.txt","r");
    if(fp==0)
    {
        printf("Error!\n");
        return 0;        
    }
    word str[100]; int temp = 0;
    char s[20],ch;
    int i,j;
    while((ch=fgetc(fp))!=-1)
    {
        if(!cheak(ch))     continue;
        i = 0;
        while(cheak(ch))    //读入一个单词
        {
            s[i++] = ch;
            ch = fgetc(fp);
        }
        s[i] = '\0';
        for(j=0;j<temp;++j)     //看有重复的吗
        {
            if(!strcmp(s,str[j].str))
            {
                str[j].count++;
                break;
            }
        }
        if(j==temp)     //新单词
        {
            strcpy(str[temp].str,s);
            str[temp].count = 1;
            ++temp;
        }
    }
    printf("The resutl has %d nums :\n",temp);
    for(i=0;i<temp;++i)
        printf("word:%-10s\tnum:%d\n",str[i].str,str[i].count);
    fclose(fp);
    
    return 0;
}