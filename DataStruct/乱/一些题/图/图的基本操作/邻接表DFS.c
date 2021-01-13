#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
typedef struct _iobuf FILE;

typedef struct node         //结点
{
    int adjvex;
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
        if(str[j]==' '||str[j]=='\n')     continue;
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
            printf("%c--%c\t",g->adjlist[i].vex,g->adjlist[temp->adjvex].vex);
            temp = temp->next;
        }
    }
}
void DFS(graph *g,int v,int *visit)     //DFS
{
    if(visit[v]==1)     return;     //终止条件
    visit[v] = 1;
    printf("%c--",g->adjlist[v].vex);
    node *p = g->adjlist[v].next;
    while (p)           //读取v周围的点
    {
        if(visit[p->adjvex]==0)
            DFS(g,p->adjvex,visit);
        p = p->next;
    }
}

int main()
{
    /*新建一个图，在相应的文件夹更改就行*/
    FILE *fp = fopen("E:\\DataStruct\\graph_test.txt","r");
    if(fp==0)
    {
        printf("fail to open file.\n");
        return 0;
    }
    graph g;
    char s[100];
    int i=0,j;
    node *temp;
    fscanf(fp,"%d   %d ",&g.n,&g.e);        //读取边和点
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
            temp->adjvex = str[k]-'0';
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

    /*DFS，因为是头插法，和邻接矩阵的DFS有区别*/
    int *visit = (int*)malloc(sizeof(int)*g.n);     //访问数组
    for(i=0;i<g.n;++i)
        visit[i] = 0;       //初始化访问数组
    printf("The DFS route is:\n");
    for(i=0;i<g.n;++i)      //非连通图的情况
        if(visit[i]==0)
            DFS(&g,i,visit);
    printf("\n------------------------------------\n");

    return 0;
}

