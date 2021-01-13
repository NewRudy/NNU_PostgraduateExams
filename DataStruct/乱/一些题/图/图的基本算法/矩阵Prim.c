#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _iobuf FILE;
#define maxsize 100

typedef struct  //定义图结构
{
    int n,e;
    char vex[maxsize];
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
        printf("\n%c:\t",g->vex[i]);
        for(int j=0;j<g->n;++j)
        {
            if(g->edge[i][j]!=0)
            {
                printf("%c--%c(power=%d)\t",g->vex[i],g->vex[j],g->edge[i][j]);
            }
        }
    }
}
char* prim(gragh *g,int v,int *sum)       //prim算法，返回最小生成树的边的字符串和总权值
{
    char *result = (char*)malloc(sizeof(char)*maxsize);int now = 0;        //假设100的空间够
    int i,j,k,vset[maxsize],lowcost[maxsize],min=__INT_MAX__;     //vset确定点是否已被纳入树，lowcost确定当前树到其它点的最小值
    for(i=0;i<g->n;++i)     //初始化
    {
        vset[i] = 0;
        lowcost[i] = min;
        if(g->edge[v][i]!=0)
            lowcost[i] = g->edge[v][i];
    }
    vset[v] = 1;
    for(i=0;i<g->n-1;++i)
    {
        min = __INT_MAX__;
        for(j=0;j<g->n;++j)
            if(vset[j]==0&&lowcost[j]<min)      //找到当前最断路径
            {
                min = lowcost[j];
                k = j;
            }
        vset[k] = 1;        //该点被纳入树
        result[now++] = g->vex[v];
        for(j=0;j<3;++j)    result[now++] = '-';
        result[now++] = g->vex[k];
        for(j=0;j<3;++j)    result[now++] = ' ';
        *sum += min;
        v = k;
        for(j=0;j<g->n;++j)     //更新lowcost数组
            if(vset[j]==0&&g->edge[v][j]!=0&&g->edge[v][j]<lowcost[j])
                lowcost[j] = g->edge[v][j];
    }
    result[now] = '\0';
    return result;
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
        g.vex[i] = c[k++];        //输入点
        for(;c[k]!='\0';++k)
        {
            j = c[k++]-'0';
            g.edge[i][j] = c[k]-'0';       //输入边权值
        }
        ++i;
    }
    output(&g);         //输出边并验证
    printf("\n------------------------------------\n");

    /*Prim 算法*/
    printf("Prim:\n");
    int v;
    int *sum = (int*)malloc(sizeof(int));
    *sum = 0;
    printf("Enter the start point:\n");
    scanf("%d",&v);
    char *result = prim(&g,v,sum);
    printf("The sum is : %d\nThe route is :\n%s\n",*sum,result);
    printf("\n------------------------------------\n");

    return 0;
}
