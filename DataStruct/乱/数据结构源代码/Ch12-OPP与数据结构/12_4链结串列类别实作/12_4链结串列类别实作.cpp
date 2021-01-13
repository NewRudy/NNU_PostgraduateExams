/* ======================================== */
/*    ��ʽʵ��: 12_4.cpp                    */
/*    ���ᴮ�����ʵ��                      */
/* ======================================== */
#include <iostream>
using namespace std;

struct llink                      /* ���нṹ����      */
{  
    int data;                     /* ��������          */
    llink *next;                  /* ָ����һ������    */ 
};

class linklist                    /* Linklist�������  */
{
private:
    llink *first;                 /* ���еĿ�ʼָ��    */
public:
    linklist() { first = NULL; }  /* ��������          */
    void insertNode(int d);       /* ��Ա����������    */
    void deleteNode(int d); 
    void printLlist();
    int search(int d);
};

/* ---------------------------------------- */
/*  ��Ա����: �ڴ��п�ͷ����ڵ�            */
/* ---------------------------------------- */
void linklist::insertNode(int d)
{
    /* �����ڵ������ */
    llink *newnode = new llink;

    newnode->data = d;            /* �����ڵ�����      */
    newnode->next = first;        /* ����ڵ�          */
    first = newnode;              /* ָ���½ڵ�        */
}

/* ---------------------------------------- */
/*  ��Ա����: ɾ��ָ�����ϵĽڵ�            */
/* ---------------------------------------- */
void linklist::deleteNode(int d)
{
    llink *current = first;       /* ����Ŀǰ�Ĵ���ָ�� */
    llink *last= current;         /* ����ǰһ������ָ�� */

    if ( current == NULL )        /* ��鴮���Ƿ��ǿյ� */
       return;
    else{
       while ( current != NULL )  /* �߷ô��нڵ�Ļ�· */
       {
           /* �Ƿ��ҵ��������ǵ�һ���ڵ� */
	   if (current->data == d && current == first )
           {
	      first = current->next; /* ���贮��ָ��    */
              delete current;        /* �ͷŴ��нڵ�    */
              return; 
           }     /* �Ƿ��ҵ������Ҳ��ǵ�һ���ڵ� */
	   else if (current->data == d && current != first )
           {
                /* ǰһ��ָ��������һ��ָ�� */
		last->next = current->next;
                delete current;      /* �ͷŴ��нڵ�    */
                return;
	   }
           else
		last = current;    /* ����ǰһ������ָ�� */
	   current = current->next;/* ��һ���ڵ�         */
       }
    }
}

/* ---------------------------------------- */
/*  ��Ա����: �߷���Ѱָ��������            */
/* ---------------------------------------- */
int linklist::search(int d){
    llink *current = first;       /* ����Ŀǰ�Ĵ���ָ�� */

    while ( current != NULL )     /* ��Ѱ����·         */
    {
	if ( current->data == d ) /* �Ƿ��ҵ�����       */
           return 1;              /* �ҵ�               */
	current = current->next;  /* ��һ���ڵ�         */
    }
    return 0;                     /* û���ҵ�           */
}

/* ---------------------------------------- */
/*  ��Ա����: ��ӡ��������                  */
/* ---------------------------------------- */
void linklist::printLlist()
{
    llink *current = first;       /* ����Ŀǰ�Ĵ���ָ�� */

    while ( current != NULL )     /* ��ӡ����·         */
    {
        /* ��ӡ�ڵ����� */
	cout << "[" << current->data << "]";
	current = current->next;  /* ��һ���ڵ�         */
    }
    cout << "\n";
}

/* ---------------------------------------- */
/*  ����ʽ: ������������Ͳ��Գ�Ա����      */
/* ---------------------------------------- */
void main()
{
    linklist Li;                    /* �������           */
    int i,temp;
    int llist[6] = { 1, 2, 3, 4, 5, 6 }; /* ��������      */

    for ( i = 0; i < 6; i++ )       /* �������нڵ�Ļ�· */
        Li.insertNode(llist[i]);    /* ����ڵ�           */

    cout << "ԭ��������: ";
    Li.printLlist();                /* ��ӡԭ������       */

    cout << "������ڵ�����: ";     /* ����ִ�           */
    cin >> temp;                    /* ����ڵ�����       */
    /* ��Ѱָ���Ľڵ����� */
    if ( Li.search(temp) ) 
       cout << "��������ڵ�[" << temp << "]!\n";
    Li.deleteNode(temp);            /* ɾ���ڵ�           */
    cout << "ɾ���������: ";
    Li.printLlist();                /* ��ӡɾ���ᴮ��     */
}
