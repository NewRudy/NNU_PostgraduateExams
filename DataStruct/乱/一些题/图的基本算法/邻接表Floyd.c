#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
typedef struct _iobuf FILE;

typedef struct node         //结点
{
    int adjvex;
    int power;              //网结构得加上权值
    struct node *next;
}node;
typedef struct   //头结点
{
    char vex;
    node* next;
}vexNode;
typedef struct      //图
{
    int n,e;
    vexNode adjlist[maxsize];
}graph;

char * fun(char *str)           //去除字符串中的空格
{
    int i=0;
    char *ch = (char*)malloc(sizeof(char)*strlen(str));
    for(int j=0;str[j]!='\0';++j)
    {
        if(str[j]==' '||str[j]=='('||str[j]==')'||str[j]=='\n')     continue;
        ch[i++] = str[j];
    }
    ch[i] ='\0';
    return ch;
}
void output(graph *g)       //输出图
{
    int i,j;
    printf("This is your map:\npoints:%d\tarcs:%d",g->n,g->e);
    for(i=0;i<g->n;++i)
    {
        printf("\n%c:\t",g->adjlist[i].vex);
        node *temp = g->adjlist[i].next;
        while (temp)
        {
            printf("%c--%c(power=%d)\t",g->adjlist[i].vex,g->adjlist[temp->adjvex].vex,temp->power);
            temp = temp->next;
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
void Floyd(graph *g,int path[][maxsize])
{
    int i,j,k,dist[maxsize][maxsize],max=__INT_MAX__;
    for(i=0;i<g->n;++i)
        for(j=0;j<g->n;++j)
        {
            dist[i][j] = max;
            path[i][j] = -1;
        }
    for(i=0;i<g->n;++i)         //初始化
    {
        node *temp = g->adjlist[i].next;
        while (temp)
        {
            dist[i][temp->adjvex] = temp->power;
            temp = temp->next;
        }
    }
    for(k=0;k<g->n;++k)
        for(i=0;i<g->n;++i)
            for(j=0;j<g->n;++j)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j] = dist[i][k]+dist[k][j];
                    path[i][j] = k;
                }
}
int main()
{
    FILE *fp = fopen("E:\\DataStruct\\power_graph.txt","r");
    if(fp==0)
    {
        printf("fail to open file.\n");
        return 0;
    }
    graph g;
    char s[100];
    int i=0,j;
    node *temp;
    fscanf(fp,"%d   %d ",&g.n,&g.e);
    for(j=0;j<g.n;++j)      //初始化
    {
        g.adjlist[j].next = 0;
        g.adjlist[j].vex = '#';
    }
    while(!feof(fp))       //一行一行的开始赋值进去
    {
        fgets(s,100,fp);
        char *str = fun(s);
        int k=0;        //k用来读取字符串
        g.adjlist[i].vex =  str[k++];
        for(;str[k]!='\0';++k)
        {
            temp = (node*)malloc(sizeof(node));     //新建一个结点
            temp->adjvex = str[k++]-'0';
            temp->power = str[k]-'0';
            temp->next = 0;
            if(g.adjlist[i].next==0)
            {
                g.adjlist[i].next = temp;
                continue;
            }
            temp->next = g.adjlist[i].next;         //头插法
            g.adjlist[i].next = temp;
        }
        ++i;
    }
    output(&g);
    printf("\n------------------------------------\n");

    /* Floyd算法 */
    int path[maxsize][maxsize];     //存储路径，不想动态分配了，累了
    Floyd(&g,path);
    printf("Floyd:\nThe result is :\n");
    outputMatrix(path,g.n);
    printf("\n------------------------------------\n");

    return 0;
}

