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
        if(str[i]==' '||str[i]=='\n') continue;
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
            if(g->edge[i][j]==1)
            {
                printf("%c--%c\t",g->vex[i],g->vex[j]);
            }
        }
    }
}
void DFS(gragh *g,int v,int *visit)     //DFS深度遍历
{
    if(visit[v]==1)     return;     //递归结束条件
    visit[v] = 1;
    printf("%c--",g->vex[v]);       //打印结点，可以换成其它操作
    for(int i=0;i<g->n;++i)
    {
        if(g->edge[v][i]==1&&visit[i]==0)
            DFS(g,i,visit);
    }
}

int main()
{
    /*新建一个图，在相应的文件夹更改就行*/
    gragh g;
    int i,j;
    char str[100],ch;      //用来向txt中读取一行数据
    FILE *fp = fopen("E:\\DataStruct\\graph_test.txt","r");
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
            j = c[k]-'0';
            g.edge[i][j] = 1;       //输入边
        }
        ++i;
    }
    output(&g);         //输出边并验证
    printf("\n------------------------------------\n");

    /*DFS遍历*/
    int *visit = (int*)malloc(sizeof(int)*g.n);     //访问数组
    for(i=0;i<g.n;++i)
        visit[i] = 0;       //访问数组全部赋值为0，表示未访问过
    printf("The DFS route is:\n");
    for(i=0;i<g.n;++i)      //非连通图就需要循环
    {
        if(visit[i]==0)
            DFS(&g,i,visit);
    }
    printf("\n------------------------------------\n");

 

    return 0;
}
