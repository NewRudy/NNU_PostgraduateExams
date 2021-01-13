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
void Dijkstra(graph *g,int v,int *dist,int *path)
{
    int vset[maxsize];              //确定该点是否已经选择
    int i,j,k,min=__INT_MAX__;
    for(i=0;i<g->n;++i)             //初始化
    {
        vset[i] = 0;
        path[i] = -1;
        dist[i] = min;
    }
    node *p = g->adjlist[v].next;
    while (p)
    {
        path[i] = v;
        dist[i] = p->power;
        p = p->next;
    }
    vset[v] = 1;
    path[v] = -1;
    dist[v] = 0;
    for(i=0;i<g->n;++i)
    {
        min = __INT_MAX__;
        for(j=0;j<g->n;++j)
            if(vset[j]==0&&min>dist[j])
            {
                min = dist[j];
                k = j;
            }
        vset[k] = 1;
        node *p = g->adjlist[k].next;
        while (p&&vset[p->adjvex]==0&&dist[k]+p->power<dist[p->adjvex])
        {
            dist[p->adjvex] = dist[k]+p->power;
            path[p->adjvex] = k;
            p = p->next;
        }
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

    /* Dijkstra算法  */
    int *path = (int*)malloc(sizeof(int)*g.n);          //保存路径
    int *dist = (int*)malloc(sizeof(int)*g.n);          //保存距离
    int v;
    printf("Enter your v:\n");
    scanf("%d",&v);
    printf("Dijkstra:\nThe result of %d is :\n\tpoint\tdist\tpath\n",v);
    Dijkstra(&g,v,dist,path);
    for(i=0;i<g.n;++i)
        printf("\t%d\t%d\t%d\n",i,dist[i],path[i]);
    printf("\n------------------------------------\n");

    return 0;
}

