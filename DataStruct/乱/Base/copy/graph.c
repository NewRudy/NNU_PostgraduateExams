#include <stdio.h>
#include<stdlib.h>
#define DEBUG
#define MAXVEX 100 //最大顶点数
int count=0;
#define NULL 0
#define EOF (-1)
typedef struct _iobuf FILE;

typedef struct ArcNode//边表结点
{
    int adjvex;//邻接点域,存储该顶点对应的下标
    int weight;//用于存储权值,对于非网图可以不需要
    struct ArcNode *nextarc; //链域,指向下一个邻接点
} ArcNode;
typedef struct VNode//顶点表结点
{
    int data;//顶点域,存储顶点信息
    ArcNode *firstarc;//边表头指针
} VNode;
typedef struct Graph
{
    VNode adjList[MAXVEX];
    int numNodes, numEdges; // 图中当前顶点数和边数
} Graph;
 
//图的建立与初始化
Graph *CreateALGraph(Graph *G)
{
    G=(Graph *)malloc(sizeof(Graph));
    printf("进入：\n");
    int i, j, k;
    ArcNode *pe;
    FILE *fp;
    fp=fopen("graph_data.txt","r");
    fscanf(fp,"%d %d",&(G->numNodes),&(G->numEdges));
    //printf("进入：\n");
    printf("顶点数与边数:%d %d\n",G->numNodes,G->numEdges);
    for (i = 0 ; i < G->numNodes; i++)
    {
        G->adjList[i].firstarc = NULL;//将边表置为空表
    }
    for (k = 0; k <  G->numEdges; k++)//建立边表
    {
        fscanf(fp,"%d %d",&i,&j);
        printf("已初始化输入边(%d,%d)\n",i,j);
        pe = (ArcNode*)malloc(sizeof(ArcNode));
        pe->adjvex = j;//邻接序号为j
//将pe的指针指向当前顶点上指向的结点
        pe->nextarc =G->adjList[i].firstarc;
        G->adjList[i].firstarc = pe;//将当前顶点的指针指向pe
 
        /*如果是无向图则再添加如下代码
        pe = (ArcNode*)malloc(sizeof(ArcNode));
        pe->adjvex = i;
        pe->nextarc =Gp->adjList[j].firstarc;
        Gp->adjList[j].firstarc = pe;
        */
 
    }
    return G;
}
//深度优先遍历
void DFS(Graph *G,int v,int visited[])
{
    visited[v]=1;
    printf("%d ",v);
    ArcNode *p=G->adjList[v].firstarc;
    while(p)
    {
        if(visited[p->adjvex]==0)
        {
            DFS(G,p->adjvex,visited);
        }
        p=p->nextarc;
    }
}
 
int main()
{
    Graph *G;
    G=CreateALGraph(G);
    int visited[MAXVEX]= {0};
    printf("\n深度遍历\n");
    DFS(G,1,visited);
    return 0;
}
