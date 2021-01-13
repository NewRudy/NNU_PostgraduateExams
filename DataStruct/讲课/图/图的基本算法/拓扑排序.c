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
int ToPoSort(gragh* g){        //拓扑排序，如果没有环则返回true
    if(!g)
        return 0;
    int count = 0,temp;      //count用于计数
    int* stack = (int*)malloc(sizeof(int)*g->n),top=0;      //栈
    memset(stack,0,sizeof(stack));
    int* v_in = (int*)malloc(sizeof(int)*g->n);     //保存每个点的入度
    for(int i=0;i<g->n;++i){
        int in = 0;     //入度
        for(int j=0;j<g->n;++j)
            if(g->edge[j][i]!=0)
                ++in;
        v_in[i] = in;       //保存该点的入度
        if(!in) {
            stack[top++] = i;       //该点入度为0就入栈
            --v_in[i];      //将该点变为-1，不再使用
        }
    }
    while(top!=0){      //栈不空的情况
        temp = stack[--top];        //出栈
        printf("%c--",g->arc[temp]);
        ++count;
        for(int j=0;j<g->n;++j){
            if(g->edge[temp][j]!=0)     //有边，边顶点的一个入度
                --v_in[j];
            if(v_in[j]==0){      //现在度为0了，更新栈
                stack[top++] = j;
                --v_in[j];
            }
        }
    }
    if(count < g->n)  /*如果count小于顶点数，说明存在环*/
        return 0;
    else
        return 1;
}
int main()
{
    gragh g;
    int i,j;
    char str[100],ch;      //用来向txt中读取一行数据
    FILE *fp = fopen("E:\\DataStruct\\directed_graph.txt","r");
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
            j = c[k]-'0';
            g.edge[i][j] = 1;       //输入边
        }
        ++i;
    }
    output(&g);         //输出边并验证
    printf("\n------------------------\nToPosort:\n");
    ToPoSort(&g);
    return 0;
}
