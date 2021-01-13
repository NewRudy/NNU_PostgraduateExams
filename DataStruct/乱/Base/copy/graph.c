#include <stdio.h>
#include<stdlib.h>
#define DEBUG
#define MAXVEX 100 //��󶥵���
int count=0;
#define NULL 0
#define EOF (-1)
typedef struct _iobuf FILE;

typedef struct ArcNode//�߱���
{
    int adjvex;//�ڽӵ���,�洢�ö����Ӧ���±�
    int weight;//���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ
    struct ArcNode *nextarc; //����,ָ����һ���ڽӵ�
} ArcNode;
typedef struct VNode//�������
{
    int data;//������,�洢������Ϣ
    ArcNode *firstarc;//�߱�ͷָ��
} VNode;
typedef struct Graph
{
    VNode adjList[MAXVEX];
    int numNodes, numEdges; // ͼ�е�ǰ�������ͱ���
} Graph;
 
//ͼ�Ľ������ʼ��
Graph *CreateALGraph(Graph *G)
{
    G=(Graph *)malloc(sizeof(Graph));
    printf("���룺\n");
    int i, j, k;
    ArcNode *pe;
    FILE *fp;
    fp=fopen("graph_data.txt","r");
    fscanf(fp,"%d %d",&(G->numNodes),&(G->numEdges));
    //printf("���룺\n");
    printf("�����������:%d %d\n",G->numNodes,G->numEdges);
    for (i = 0 ; i < G->numNodes; i++)
    {
        G->adjList[i].firstarc = NULL;//���߱���Ϊ�ձ�
    }
    for (k = 0; k <  G->numEdges; k++)//�����߱�
    {
        fscanf(fp,"%d %d",&i,&j);
        printf("�ѳ�ʼ�������(%d,%d)\n",i,j);
        pe = (ArcNode*)malloc(sizeof(ArcNode));
        pe->adjvex = j;//�ڽ����Ϊj
//��pe��ָ��ָ��ǰ������ָ��Ľ��
        pe->nextarc =G->adjList[i].firstarc;
        G->adjList[i].firstarc = pe;//����ǰ�����ָ��ָ��pe
 
        /*���������ͼ����������´���
        pe = (ArcNode*)malloc(sizeof(ArcNode));
        pe->adjvex = i;
        pe->nextarc =Gp->adjList[j].firstarc;
        Gp->adjList[j].firstarc = pe;
        */
 
    }
    return G;
}
//������ȱ���
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
    printf("\n��ȱ���\n");
    DFS(G,1,visited);
    return 0;
}
