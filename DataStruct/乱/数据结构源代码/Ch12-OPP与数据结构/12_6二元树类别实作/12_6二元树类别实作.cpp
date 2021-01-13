/* ======================================== */
/*    ��ʽʵ��: 12_6.cpp                    */
/*    ��Ԫ�����ʵ��                        */
/* ======================================== */
#include <iostream>
using namespace std;

struct node                       /* ���Ľṹ����       */
{
   int data;                      /* �ڵ�����           */
   node *left;                    /* ָ����������ָ��   */
   node *right;                   /* ָ����������ָ��   */
};

class binaryTree                  /* ��Ԫ�����������   */
{
private:
   node *head;                    /* ���ڵ��ָ��       */
   void inorder(node *ptr);       /* ��Ա����:�����߷�  */
public:
   binaryTree() { head = NULL; }  /* ������������       */
   void insertNode(int d);        /* ����ڵ㺯������   */
   void printTree();              /* ��ʾ��Ԫ���Ľڵ�   */
   int search(int d);             /* ��Ԫ�����߷���Ѱ   */
};

/* ---------------------------------------- */
/*  ��Ա����: ��Ԫ�������߷�                */
/* ---------------------------------------- */
void binaryTree::inorder(node *ptr)
{
    if ( ptr != NULL )             /* ��ֹ����           */
    {
       inorder(ptr->left);         /* ������             */
       /* ��ӡ�ڵ�����       */
       cout << "[" << ptr->data << "]"; 
       inorder(ptr->right);        /* ������             */
    }
};

/* ---------------------------------------- */
/*  �����Ԫ���Ľڵ�                        */
/* ---------------------------------------- */
void binaryTree::insertNode(int d)
{
   /* �����½ڵ������ */
   node *temp = new node;           /* �����½ڵ�         */
   node *current;                   /* Ŀǰ���ڵ�ָ��     */
   int inserted = 0;                /* �Ƿ�����½ڵ�     */

   temp->data = d;                  /* �����ڵ�����       */
   temp->left = NULL;               /* �趨ָ���ֵ       */
   temp->right = NULL;              /* �趨ָ���ֵ       */
   if ( head == NULL )              /* �Ƿ��Ǹ��ڵ�       */
      head = temp;                  /* ���ڵ�ָ��Ϊ�½ڵ� */
   else
   {
      current = head;               /* ����Ŀǰ��ָ��     */
      while( !inserted )
      {
         /* �ȽϽڵ�ֵ   */
	 if ( current->data > temp->data )
	 {
	    if ( current->left == NULL ) /* �Ƿ���������ӽڵ� */
	    {
	       current->left = temp; /* �����ӵ�����     */
	       inserted = 1;         /* �Ѿ����� */
	    }
	    else
	       current = current->left;    /* ������      */
	 }
	 else
	 {
	    if ( current->right == NULL ) /* �Ƿ������ҵ��ӽڵ� */
	    {
	       current->right = temp; /* �����ӵ�����     */
	       inserted = 1;          /* �Ѿ�����  */
	    }
	    else
	       current = current->right;   /* ������      */
	 }
      }
   }
}

/* ---------------------------------------- */
/*  ��Ա����: ��Ԫ��Ѱ������Ѱ              */
/* ---------------------------------------- */
int binaryTree::search(int d)
{
   node *temp = head;
   while ( temp != NULL )        /* ����·             */
   { 
      if ( temp->data == d )     /* �ҵ���             */
	 return 1;
      if ( temp->data < d )      /* �Ƚ�����           */
	 temp = temp->right;     /* ������             */
      else
	 temp = temp->left;      /* ������             */
   }
   return 0;                     /* û���ҵ�           */
}   

/* ---------------------------------------- */
/*  ��Ա����: �����߷���ӡ��Ԫ��            */
/* ---------------------------------------- */
void binaryTree::printTree()
{
   inorder(head);                 /* ���������߷ú���  */ 
} 

/* ---------------------------------------- */
/*  ����ʽ: ������Ԫ�����������߷���ӡ����. */
/* ---------------------------------------- */
void main()
{
   binaryTree btree;              /* ������Ԫ�����     */
   int i;

   /* ��Ԫ���ڵ����� */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   for ( i = 0; i < 9; i++ )      /* �û�·������״�ṹ */
       btree.insertNode(data[i]); /* �����Ԫ���Ľڵ�   */
   cout << "���Ľڵ����� \n";
   btree.printTree();             /* �����߷ö�Ԫ��     */
   cout << "\n����������������: ";/* �������           */
   cin >> i;                      /* ��������           */
   if ( btree.search(i) )         /* ��Ѱ���������     */
      cout << "�ҵ��ڵ�! \n";
   else
      cout << "û���ҵ��ڵ�! \n";
}
