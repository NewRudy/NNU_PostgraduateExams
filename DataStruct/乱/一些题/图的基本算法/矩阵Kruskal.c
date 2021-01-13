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
typedef struct 
{
    int pre,next,power;
}road;

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
void assign(road *a,road *b)
{
    (*a).next = (*b).next;
    (*a).power = (*b).power;
    (*a).pre = (*b).pre;
}
void quicksort(road *r,int low,int high)         //快速排序边集数组
{
    if(low>=high)   return;        //终止条件
    int i=low,j=high;
    road temp;
    assign(&temp,&r[i]);
    while(i<j)
    {
        while(i<j&&r[j].power>temp.power)   --j;
        assign(&r[i],&r[j]);
        while(i<j&&r[i].power<=temp.power)  ++i;
        assign(&r[j],&r[i]); 
    }
    assign(&r[i],&temp);
    quicksort(r,low,i-1);
    quicksort(r,i+1,high);
}
int getroot(int a,int *v)
{
    while (a!=v[a])
        a = v[a];
    return a;
}
char * kruskal(gragh *g,road *r,int *sum)     //kruskal算法，返回路径和权值和
{
    char *result = (char*)malloc(sizeof(char)*maxsize);int now = 0;     //存储路径，假设100的空间够
    int i,j,a,b;
    int vex[6];      //判断环用的
    for(i=0;i<g->n;++i)
        vex[i] = i;
    for(i=0;i<g->e;++i)
    {
        a = getroot(r[i].pre,vex);
        b = getroot(r[i].next,vex);
        if(a!=b)
        {
            result[now++] = g->vex[r[i].pre];
            for(j=0;j<3;++j)    result[now++] = '-';
            result[now++] = g->vex[r[i].next];
            for(j=0;j<3;++j)    result[now++] = ' ';
            vex[a] = b;
            *sum += r[i].power;
        }
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

    /*Kruskal 算法*/
    printf("Kruskal:\n");
    int *sum = (int*)malloc(sizeof(int));
    *sum = 0;
    road r[11];int now=0;        //新建边集数组
    for(i=0;i<g.n;++i)          //初始化边集数组
        for(j=i+1;j<g.n;++j)
            if(g.edge[i][j]!=0)
            {
                r[now].pre = i;
                r[now].next = j;
                r[now].power = g.edge[i][j];
                ++now;
            }
    quicksort(r,0,now-1);           //快速排序边集数组
    char *result = kruskal(&g,r,sum);
    printf("The sum is : %d\nThe route is :\n%s\n",*sum,result);
    printf("\n------------------------------------\n");

    return 0;
}
