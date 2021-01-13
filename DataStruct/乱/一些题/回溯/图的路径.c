//遍历所有的结点，我先初始化一个图
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _iobuf FILE;

//定义结构体
typedef struct Node
{
    int arc;
    struct Node *next;
}Node;
typedef struct
{
    char data;
    Node* firstArc;
}firstNode;
typedef struct 
{
    firstNode adjList[100];
    int n;
}AGraph;

//初始化图
void init(AGraph *G)
{
    printf("Enter your n:\n");
    scanf("%d",&G->n);
    int i=0,j=0;
    while (i<G->n)
    {
        printf("Enter %d:",i);
        scanf(" %c",&G->adjList[i].data);
        G->adjList[i].firstArc = NULL;
        printf("Enter adj points?");
        scanf("%d",&j);
        while (j)
        {
            Node *temp = (Node*)malloc(sizeof(Node));
            printf("Enter arc:\n");
            scanf("%d",&temp->arc);
            temp->next = G->adjList[i].firstArc;
            G->adjList[i].firstArc = temp;
            printf("Continue?\n");
            scanf("%d",&j);
        }
        ++i;
    }
}
//回溯+DFS,从i走到j
void findPath(AGraph *G,int i,int j,char path[],int depth,int *visited)
{
    visited[i] = 1;
    path[depth++] = G->adjList[i].data;
    if(i==j)
    {   
        for(int k=0;k<depth;++k)
        printf("%c--",path[k]);
        return;
    }
    printf("\n");
    Node *p = G->adjList[i].firstArc;
    while (p!=NULL)
    {
        if(visited[p->arc]==0)
            findPath(G,p->arc,j,path,depth,visited);
        p = p->next;
    }
}
int main()
{
    AGraph *G = (AGraph*)malloc(sizeof(AGraph));
    init(G);
    char* path = (char*)malloc(sizeof(char)*50);
    int visited[50] = {0};
    findPath(G,2,5,path,0,visited);

    return 0;
}


