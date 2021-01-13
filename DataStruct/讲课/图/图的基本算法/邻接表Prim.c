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
char * Prim(graph *g,int v,int *sum)        //Prim算法
{
    char *result = (char*)malloc(sizeof(char)*maxsize);int now=0;       //存储路径
    int vset[maxsize],lowcost[maxsize];     //两个辅助数组
    int i,j,k,min=__INT_MAX__;
    node *temp = g->adjlist[v].next;
    for(i=0;i<g->n;++i)     
    {
        vset[i] = 0;    //初始化点
        lowcost[i] = min;
    }
    while(temp)
    {
        lowcost[temp->adjvex] = temp->power;        //初始化边
        temp = temp->next;
    }
    vset[v] = 1;
    for(i=1;i<g->n;++i)         //注意这里i为1
    {
        min = __INT_MAX__;
        for(j=0;j<g->n;++j)         //选出代价最小的一个点
            if(vset[j]==0&&lowcost[j]<min)
            {
                min = lowcost[j];
                k = j;
            }
        vset[k] = 1;
        *sum += min;
        result[now++] = g->adjlist[v].vex;
        for(j=0;j<2;++j) result[now++] = '-';
        result[now++] = g->adjlist[k].vex;
        for(j=0;j<2;++j) result[now++] = ' ';
        v=k;
        temp = g->adjlist[v].next;
        while (temp)        //更新lowcost数组
        {
            if(vset[temp->adjvex]==0&&lowcost[temp->adjvex]>temp->power)
                lowcost[temp->adjvex] = temp->power;
            temp = temp->next;
        }
    }
    result[now] = '\0';
    return result;
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

    /*Prim*/
    int v;      //起始点
    int *sum = (int*)malloc(sizeof(int));
    *sum = 0;
    printf("Prim:\nEnter your start point:\n");
    scanf("%d",&v);
    char *result = Prim(&g,v,sum);
    printf("The sum is:\t%d\nThe route is :\n%s\n",*sum,result);
    printf("\n------------------------------------\n");

    return 0;
}

