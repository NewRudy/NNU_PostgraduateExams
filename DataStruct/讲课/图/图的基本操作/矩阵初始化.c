#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _iobuf FILE;
#define maxsize 100

typedef struct  //定义图结构
{
    int n,e;        //n是点，e是边
    char arc[maxsize];
    int edge[maxsize][maxsize];
}gragh;
char* fun(char *str)     //去除字符串中的空格
{
    int i=0,j=0;
    char* res = (char*)malloc(sizeof(char)*strlen(str));        //动态分配空间
    for(;str[i]!='\0';++i)
    {
        if(str[i]==' '||str[i]=='\n') 
            continue;
        res[j++] = str[i];
    } 
    return res;
}
void output(gragh *g)       //输出图
{
    printf("This is your map:\npoints:\t%d\tedges:\t%d",g->n,g->e);
    for(int i=0;i<g->n;++i)
    {
        printf("\n%c:\t",g->arc[i]);
        for(int j=0;j<g->n;++j)
        {
            if(g->edge[i][j]==1)
            {
                printf("%c--%c\t",g->arc[i],g->arc[j]);
            }
        }
    }
}
int main()
{
    gragh g;        //int a;int* a;(四个字节大小的空间，然后把空间名字改为a，然后空间存储的是地址，存储的地
    int i,j;
    char str[100],ch;      //用来向txt中读取一行数据
    FILE *fp = fopen("../graph_test.txt","r");
    if(fp==0)       //0 和 null 的区别是啥  如果表示对错，
    {
        printf("Open file error.\n");
        return 0;
    }
    fscanf(fp,"%d   %d ",&g.n,&g.e);     //读取点和边
    i = 0;
    while(!feof(fp))    //没有到达文件末尾的情况
    {
        fgets(str,100,fp);      //读取一行数据
        char *c = fun(str);
        int k = 0;
        g.arc[i] = c[k++];        //输入点
        for(;c[k]!='\0';++k)
        {
            j = c[k]-'0';
            g.edge[i][j] = 1;       //输入边
        }
        ++i;
    }
    output(&g);         //输出边并验证

    return 0;
}
