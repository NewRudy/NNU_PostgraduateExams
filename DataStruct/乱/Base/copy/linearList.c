#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#define EOF (-1)
typedef struct _iobuf FILE;

//������
typedef  struct LNode
{
    int data;
    struct  LNode *next;
} LNode;
 
void Print(LNode *L)///�������
{
    LNode *p;
    p=L;
    while((p->next)!=NULL)
    {
        printf("%d ",p->next->data);
        p = p->next;
    }
}
 
///����������ʼ��
LNode *CreatL()
{
    LNode *L = (LNode *)malloc(sizeof(LNode));   //����ͷ���ռ�
    L->next = NULL;                  //��ʼ��һ��������
    LNode *r;
    r = L;                          //rʼ��ָ���ն˽�㣬��ʼʱָ��ͷ���
    int x;                         //xΪ�����������е�����
    FILE *fp;
    fp=fopen("liList_data.txt","r");
    while((fscanf(fp,"%d",&x))!=EOF)
    {
 
        LNode *p;
        p = (LNode *)malloc(sizeof(LNode));   //�����µĽ��
        p->data = x;                     //���������ֵ
        r->next =p;
        r = p;                 //�������뵽��ͷL-->|1|-->|2|-->NULL
    }
    fclose(fp);
    r->next=NULL;
    return L;
}
void delet(LNode *L,int i)
{
    LNode *p=L;
    int count=0;
    //�ҵ���i������ǰһ��λ��p
    while(p->next)
    {
        count++;
        if(count==i)
        {
            break;
        }
        p=p->next;
    }
    LNode *q=p->next;
    p->next=p->next->next;
    free(q);
}
 
int main()
{
    LNode *L;
    printf("��������");
 
    L=CreatL();//�����������ʼ��
    Print(L);//��ӡ����
 
    delet(L,3);
    printf("\nɾ��������Ԫ�غ�����");
    Print(L);//��ӡ����
    return 0;
}

 