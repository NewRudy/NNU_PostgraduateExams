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
typedef struct              //边集数组
{   
    int pre,next,weight;
}road;

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
void assign(road *a,road *b)
{
    (*a).pre = (*b).pre;
    (*a).next = (*b).next;
    (*a).weight = (*b).weight;
}
void quickSort(road *r,int low,int high)
{
    if(low>=high)   return;         //终止条件
    int i=low,j=high;
    road temp;
    assign(&temp,&r[i]);
    while (i<j)
    {
        while(i<j&&r[j].weight>temp.weight)     --j;
        assign(&r[i],&r[j]);
        while(i<j&&r[i].weight<=temp.weight)    ++i;
        assign(&r[j],&r[i]);
    }
    assign(&r[i],&temp);
    quickSort(r,low,i-1);
    quickSort(r,i+1,high);
}
int getroot(int a, int *vex)
{
    while (a!=vex[a])
        a = vex[a];
    return a;
}
char *Kruskal(graph *g,road *r,int *sum)
{
    char *result = (char*)malloc(sizeof(char)*maxsize);      //存储路径
    int vex[maxsize],i,j,a,b,now=0;
    for(i=0;i<g->e;++i)         //初始化vex，用来判断是否有环
        vex[i] = i;
    for(i=0;i<g->e;++i)         //从最短的路径开始选择
    {
        a = getroot(r[i].pre,vex);
        b = getroot(r[i].next,vex);
        if(a!=b)        //没有构成环
        {
            *sum += r[i].weight;
            result[now++] = g->adjlist[r[i].pre].vex;
            for(j=0;j<2;++j)    result[now++] = '-';
            result[now++] = g->adjlist[r[i].next].vex;
            for(j=0;j<2;++j)    result[now++] = ' ';
            vex[a] = b;
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

    /* Kruskal */
    road r[11];           //边集数组，每次动态申请完之后再动态申请其它的元素都会失败
    int now=0;
    int *sum = (int*)malloc(sizeof(int));        //权值和
    *sum = 0;
    for(i=0;i<g.n;++i)      //初始化边集数组
    {
        node *temp = g.adjlist[i].next;
        while (temp&&temp->adjvex>i)
        {
            r[now].pre = i;
            r[now].next = temp->adjvex;
            r[now].weight = temp->power;
            ++now;
            temp = temp->next; 
        }
    }
    quickSort(r,0,now-1);       //边集数组排序
    char *result = Kruskal(&g,r,sum);
    printf("Kruskal:\n");
    printf("The sum is:%d\nThe route is:\n%s\n",*sum,result);
    printf("\n------------------------------------\n");

    return 0;
}

