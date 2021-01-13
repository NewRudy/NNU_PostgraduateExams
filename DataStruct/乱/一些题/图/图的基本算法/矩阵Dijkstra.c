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
void Dijkstra(gragh *g,int v,int *dist,int *path)       //Dijkstra算法
{
    int vset[maxsize];              //确定点是否选择
    int i,j,k,min=__INT_MAX__;
    for(i=0;i<g->n;++i)             //初始化
    {
        vset[i] = 0;
        dist[i] = min;
        path[i] = -1;
        if(g->edge[v][i]!=0)
        {
            dist[i] = g->edge[v][i];
            path[i] = v;
        }
    }
    path[v] = -1;
    vset[v] = 1;
    dist[v] = 0;
    for(i=0;i<g->n;++i)
    {
        min = __INT_MAX__;
        for(j=0;j<g->n;++j)
            if(vset[j]==0&&dist[j]<min)         //得到一个点
            {
                min = dist[i];
                k = j;
            }
        vset[k] = 1;
        for(j=0;j<g->n;++j)
            if(vset[j]==0&&g->edge[k][j]!=0&&dist[k]+g->edge[k][j]<dist[j])       //更新数组
            {
                path[j] = k;
                dist[j] = dist[k]+g->edge[k][j];
            }
    }
}
int main()
{
    gragh g;
    int i,j;
    char str[100],ch;      //用来向txt中读取一行数据
    FILE *fp = fopen("E:\\DataStruct\\power_graph.txt","r");
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

    /* Dijkstra算法 */
    int *path = (int*)malloc(sizeof(int)*g.n);          //存储路径
    int *dist = (int*)malloc(sizeof(int)*g.n);          //存储距离
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
