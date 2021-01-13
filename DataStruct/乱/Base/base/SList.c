#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef _Bool STATUS;
//����˳���ṹ��
typedef struct SList
{
    ElemType *head;
    int length;
}SList;

//�������Ա��������
STATUS InitList(SList *L);    //��ʼ������������һ���յ����Ա�
STATUS ListEmpty(SList L);      //�жϱ��Ƿ�Ϊ��
void ClearList(SList *L);     //�������
STATUS DestryList(SList L);     //���ٱ�
ElemType GetElem(SList L,int i);      //��ȡ���е�i��λ�õ�ֵ�����ظ�e
STATUS LocateElem(SList *L,ElemType e);      //���ұ����Ƿ���e
STATUS ListInsert(SList *L,int i,ElemType e);     //�ڱ��е�i��λ�ò���e
STATUS ListDelete(SList *L,int i,ElemType *e);     //ɾ�����е�i��λ��Ԫ�أ���e����

/*��ʼ��һ���յ����Ա� */
STATUS InitList(SList *L)
{
    L->head = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    if (!L->head)
    {
        printf("Initializing isn't successful.");
        return FALSE;
    }
    L->length = 0;
    return TRUE;
}
/*�жϱ��Ƿ�Ϊ�� */
STATUS  ListEmpty(SList L)
{
    if(L.length==0){
        printf("The list is null");
        return TRUE;
    }
    else{
        printf("The list isn't null");
        return FALSE;
    } 
}
/*������� */
void ClearList(SList *L)
{
    if(L->head) L->length = 0;
    printf("The list has been cleared.");
}
/*���ٱ� */
STATUS DestryList(SList L)
{
    if(L.head) free(L.head);
    printf("The list has been destroyed");
    return TRUE;
}
/* ��ȡ���е�i��ֵ����e����*/
ElemType GetElem(SList L,int i)
{
    if(L.head&&i>0&&i<L.length) {
        printf("The return figure is %d",L.head[i-1]);
        return L.head[i-1];
    }
}
/* ���ұ����Ƿ���e*/
STATUS LocateElem(SList *L,ElemType e)
{
    int judge = 0;
    for(int i=0;i<L->length;i++)
    {
        if(L->head[i]==e) 
        {
            judge = 1;
            break;
        }
    }
    if(judge) printf("%d is in list.",e);
    else printf("%d isn't in list.",e);
    return judge;
}
/*�ڱ��е�i��λ�ò���e */
STATUS ListInsert(SList *L,int i,ElemType e)
{
    if(i<1||i>MAXSIZE||L->length==MAXSIZE) return FALSE;
    for(int j=L->length;j>=i-1;j--) 
        L->head[j+1]=L->head[j];
    L->head[i-1] = e;
    L->length++;
    printf("Inserting is successful.");
    return TRUE;
}
/* ɾ�����е�i��λ��Ԫ�أ���e����*/
STATUS ListDelete(SList *L,int i,ElemType *e)
{
    *e = L->head[i-1];
    for(int j=i-1;j<L->length;j++) L->head[j] = L->head[j+1];
    L->length--;
    printf("deleting is successful.");
    return TRUE;
}
void ListDisplay(SList *L)
{
    printf("�������Ա�Ϊ��");
    for(int i=0;i<L->length;i++)
    {
        printf("%d  ",L->head[i]);
    }
    printf("\n");
}

//������������
int main(void)
{
    SList *L;
    int l,judge=-1,i,e;

    if(InitList(L))
    {
        printf("Enter your length:\n");
        scanf("%d",&l);
        for(int i=1;i<=l;i++)
        {
            printf("The figure of %d: ",i);
            scanf("%d",&e);
            L->head[i-1] = e;
            L->length++;
        }
        printf("Initializing is successful.");
        ListDisplay(L);
    }
    else
    {
        printf("Initializing isn't successful.");
    }

    while (judge)
    {
        printf("function:\n0.quit\n1.void ListDisplay(SList *L)\n2.STATUS ListEmpty(SList L)\n\
3.ElemType GetElem(SList L,int i)\n4.STATUS LocateElem(SList *L,ElemType e)\n\
5.STATUS ListInsert(SList *L,int i,ElemType e)\n6.STATUS ListDelete(SList *L,int i,ElemType *e);\n\
        Please print the number of function:\n");
        scanf("%d",&judge);
        switch (judge)
        {
        case 1:
            ListDisplay(L);
            break;
        case 2:
            ListEmpty(*L);
            break;
        case 3:
            printf("What sequence of the list you want to require?");
            scanf("%d",&i);
            GetElem(*L,i);
            break;
        case 4:
            printf("The figure you want to inquiry:");
            scanf("%d",&e);
            LocateElem(L,e);
            break;
        case 5:
            printf("now ListInsert(SList *L,int i,ElemType e),inputing your i&&e:");
            scanf("%d%d",&i,&e);
            ListInsert(L,i,e);
            break;
        case 6:
            printf("now ListDelete(SList *L,int i,ElemType *e),inputing your i:");
            scanf("%d",&i);
            ListDelete(L,i,&e);
            break;
        default:
            printf("No function executing.");
            break;
        }
    }
    
    return 0;
}