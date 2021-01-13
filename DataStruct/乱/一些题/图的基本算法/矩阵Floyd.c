#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _iobuf FILE;
#define maxsize 100

typedef struct  //定义图结构
{
    int n,e;
    char arc[maxsize];
    int edge[maxsize][maxsize];
}gragh;
char* fun(char *str)     //去除字符串中的空格
{
    int i=0,j=0;
    char *res = (char*)malloc(sizeof(char)*strlen(str));
    for(;str[i]!='\0';++i)
    {
        if(str[i]==' '||str[i]=='('||str[i]==')'||str[i]=='\n') continue;
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
            if(g->edge[i][j]!=0)
            {
                printf("%c--%c(power=%d)\t",g->arc[i],g->arc[j],g->edge[i][j]);
            }
        }
    }
}
void outputMatrix(int path[][maxsize],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;++i)
        printf("\tP%d",i);
    for(i=0;i<n;++i)              //输出path
    {
        printf("\nP%d",i);
        for(int j=0;j<n;++j)
            printf("\t%d",path[i][j]);
    }
}
void Floyd(gragh *g,int path[][maxsize])
{
    int i,j,k,a[maxsize][maxsize],max=__INT_MAX__;
    for(i=0;i<g->n;++i)
        for(j=0;j<g->n;++j)
        {
            a[i][j] = g->edge[i][j];
            if(g->edge[i][j]==0)    a[i][j] = max;
            path[i][j] = -1;
        }
    for(k=0;k<g->n;++k)
        for(i=0;i<g->n;++i)
            for(j=0;j<g->n;++j)
                if(a[i][j]>a[i][k]+a[k][j])
                {
                    a[i][j] = a[i][k]+a[k][j];
                    path[i][j] = k;
                }
}
int main()
{
    gragh g;
    int i,j;
    char str[100],ch;      //用来向txt中读取一行数据
    FILE *fp = fopen("E:\\DataStruct\\littlevalue\\power_graph.txt","r");
    if(fp==0)
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
            j = c[k++]-'0';
            g.edge[i][j] = c[k]-'0';       //输入边权值
        }
        ++i;
    }
    output(&g);         //输出边并验证
    printf("\n------------------------------------\n");

    /* Floyd算法 */
    int path[maxsize][maxsize];     //存储路径，不想动态分配了，累了
    Floyd(&g,path);
    printf("Floyd:\nThe result is :\n");
    outputMatrix(path,g.n);
    printf("\n------------------------------------\n");

    return 0;
}
