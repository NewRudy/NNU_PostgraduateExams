/* ======================================== */
/*    程式实例: 12_6.cpp                    */
/*    二元树类别实作                        */
/* ======================================== */
#include <iostream>
using namespace std;

struct node                       /* 树的结构宣告       */
{
   int data;                      /* 节点资料           */
   node *left;                    /* 指向左子树的指标   */
   node *right;                   /* 指向右子树的指标   */
};

class binaryTree                  /* 二元树的类别宣告   */
{
private:
   node *head;                    /* 根节点的指标       */
   void inorder(node *ptr);       /* 成员函数:中序走访  */
public:
   binaryTree() { head = NULL; }  /* 建构函数宣告       */
   void insertNode(int d);        /* 插入节点函数宣告   */
   void printTree();              /* 显示二元树的节点   */
   int search(int d);             /* 二元树的走访搜寻   */
};

/* ---------------------------------------- */
/*  成员函数: 二元树中序走访                */
/* ---------------------------------------- */
void binaryTree::inorder(node *ptr)
{
    if ( ptr != NULL )             /* 终止条件           */
    {
       inorder(ptr->left);         /* 左子树             */
       /* 列印节点内容       */
       cout << "[" << ptr->data << "]"; 
       inorder(ptr->right);        /* 右子树             */
    }
};

/* ---------------------------------------- */
/*  插入二元树的节点                        */
/* ---------------------------------------- */
void binaryTree::insertNode(int d)
{
   /* 建立新节点记忆体 */
   node *temp = new node;           /* 建立新节点         */
   node *current;                   /* 目前树节点指标     */
   int inserted = 0;                /* 是否插入新节点     */

   temp->data = d;                  /* 建立节点内容       */
   temp->left = NULL;               /* 设定指标初值       */
   temp->right = NULL;              /* 设定指标初值       */
   if ( head == NULL )              /* 是否是根节点       */
      head = temp;                  /* 根节点指标为新节点 */
   else
   {
      current = head;               /* 保留目前树指标     */
      while( !inserted )
      {
         /* 比较节点值   */
	 if ( current->data > temp->data )
	 {
	    if ( current->left == NULL ) /* 是否是最左的子节点 */
	    {
	       current->left = temp; /* 接起父子的链结     */
	       inserted = 1;         /* 已经插入 */
	    }
	    else
	       current = current->left;    /* 左子树      */
	 }
	 else
	 {
	    if ( current->right == NULL ) /* 是否是最右的子节点 */
	    {
	       current->right = temp; /* 接起父子的链结     */
	       inserted = 1;          /* 已经插入  */
	    }
	    else
	       current = current->right;   /* 右子树      */
	 }
      }
   }
}

/* ---------------------------------------- */
/*  成员函数: 二元搜寻树的搜寻              */
/* ---------------------------------------- */
int binaryTree::search(int d)
{
   node *temp = head;
   while ( temp != NULL )        /* 主回路             */
   { 
      if ( temp->data == d )     /* 找到了             */
	 return 1;
      if ( temp->data < d )      /* 比较资料           */
	 temp = temp->right;     /* 右子树             */
      else
	 temp = temp->left;      /* 左子树             */
   }
   return 0;                     /* 没有找到           */
}   

/* ---------------------------------------- */
/*  成员函数: 中序走访列印二元树            */
/* ---------------------------------------- */
void binaryTree::printTree()
{
   inorder(head);                 /* 呼叫中序走访函数  */ 
} 

/* ---------------------------------------- */
/*  主程式: 建立二元树且用中序走访列印出来. */
/* ---------------------------------------- */
void main()
{
   binaryTree btree;              /* 建立二元树物件     */
   int i;

   /* 二元树节点资料 */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   for ( i = 0; i < 9; i++ )      /* 用回路建立树状结构 */
       btree.insertNode(data[i]); /* 插入二元树的节点   */
   cout << "树的节点内容 \n";
   btree.printTree();             /* 中序走访二元树     */
   cout << "\n请输入搜索的数字: ";/* 输出数字           */
   cin >> i;                      /* 输入数字           */
   if ( btree.search(i) )         /* 搜寻输入的数字     */
      cout << "找到节点! \n";
   else
      cout << "没有找到节点! \n";
}
