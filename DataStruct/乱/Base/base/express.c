/*双亲表示法*/
#define MaxSize 100
typedef int TElemType;
typedef struct PTNode
{
    TElemType data;
    int parent;
}PTNode;
typedef struct 
{
    PTNode nodes[MaxSize];
    int r,n;
}PTree;

/*孩子表示法*/
typedef struct CTNode
{
    TElemType child;
    struct CTNode* next;
};
typedef struct 
{
    TElemType data;
    struct CTNode* firstChild;
}CTBox;
typedef struct 
{
    CTBox nodes[MaxSize];
    int r,n;
}CTree;



