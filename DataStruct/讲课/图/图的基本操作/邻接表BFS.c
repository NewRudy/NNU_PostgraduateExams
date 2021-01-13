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
void BFS(graph *g,int v,int *visit)     //BFS
{
    int queue[10];
    int length=10,front=0,rear=0,i,temp;       //借助队列来实现
    node *p;
    queue[rear++] = v;
    visit[v] = 1;       //每次入队的时候visit中赋值为1
    while (front!=rear)     //队列非空
    {
        temp = queue[front];
        front = (++front)%length;
        printf("%c--",g->adjlist[temp].vex);
        p = g->adjlist[temp].next;
        while (p)
        {
            if(visit[p->adjvex]==0)
            {
                queue[rear] = p->adjvex;        //入队
                rear = (++rear)%length;
                visit[p->adjvex] = 1;
            }
            p = p->next;
        }   
    }
}
int main()
{
    /*新建一个图，在相应的文件夹更改就行*/
    FILE *fp = fopen("../graph_test.txt","r");
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
        g.adjlist[j].next = 0;
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

    /*BFS*/
    int *visit = (int*)malloc(sizeof(int)*g.n);     //访问数组
    for(i=0;i<g.n;++i)      //访问数组初始化
        visit[i] = 0;   
    printf("The BFS route is :\n");
    for(i=0;i<g.n;++i)      //非连通图的情况
        if(visit[i]==0)
            BFS(&g,i,visit);
    printf("\n------------------------------------\n");
    return 0;
}

