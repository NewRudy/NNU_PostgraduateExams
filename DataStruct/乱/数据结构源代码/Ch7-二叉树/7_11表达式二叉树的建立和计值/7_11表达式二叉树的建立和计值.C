/* ======================================== */
/*    程式实例: 7_11.c                      */
/*    表达式二叉树的建立和计值              */
/* ======================================== */
#include <stdlib.h>

struct tree                       /* 树的结构宣告       */
{
   char data;                     /* 节点数据           */
   struct tree *left;             /* 指向左子树的指标   */
   struct tree *right;            /* 指向右子树的指标   */
};
typedef struct tree treenode;     /* 树的结构新型态     */
typedef treenode *btree;          /* 宣告树节点指标型态 */

/* ---------------------------------------- */
/*  建立表达式二叉树                        */
/* ---------------------------------------- */
btree createbtree(int *data,int pos)
{
   btree newnode;                 /* 新节点指标         */

   if ( data[pos] == 0 || pos > 7 )   /* 终止条件       */
      return NULL;
   else
   {
      /* 建立新节点记忆体 */
      newnode = ( btree ) malloc(sizeof(treenode));
      newnode->data = data[pos];  /* 建立节点内容       */
      /* 建立左子树的递归呼叫 */
      newnode->left = createbtree(data,2*pos);
      /* 建立右子树的递归呼叫 */
      newnode->right = createbtree(data,2*pos+1);
      return newnode;
   }
}

/* ---------------------------------------- */
/*  表达式二叉树中序列印                    */
/* ---------------------------------------- */
void inorder(btree ptr)
{
   if ( ptr != NULL )             /* 终止条件           */
   {
      inorder(ptr->left);         /* 左子树             */
      printf("%c",ptr->data);     /* 列印节点内容       */
      inorder(ptr->right);        /* 右子树             */
   }
}

/* ---------------------------------------- */
/*  表达式二叉树前序列印                    */
/* ---------------------------------------- */
void preorder(btree ptr)
{
   if ( ptr != NULL )             /* 终止条件           */
   {
      printf("%c",ptr->data);     /* 列印节点内容       */
      preorder(ptr->left);        /* 左子树             */
      preorder(ptr->right);       /* 右子树             */
   }
}

/* ---------------------------------------- */
/*  表达式二叉树后序列印                    */
/* ---------------------------------------- */
void postorder(btree ptr)
{
   if ( ptr != NULL )             /* 终止条件           */
   {
      postorder(ptr->left);       /* 左子树             */
      postorder(ptr->right);      /* 右子树             */
      printf("%c",ptr->data);     /* 列印节点内容       */
   }
}

/* ---------------------------------------- */
/*  表达式二叉树后序计值                    */
/* ---------------------------------------- */
int cal(btree ptr)
{
   int operand1 = 0;              /* 前运算元变数       */
   int operand2 = 0;              /* 后运算元变数       */

   /* 终止条件 */
   if ( ptr->left == NULL && ptr->right == NULL )
      return ptr->data-48;
   {
      operand1 = cal(ptr->left);  /* 左子树             */
      operand2 = cal(ptr->right); /* 右子树             */
      return getvalue(ptr->data,operand1,operand2);
   }
}

/* ---------------------------------------- */
/*  计算二叉表达式的值                      */
/* ---------------------------------------- */
int getvalue(int op,int operand1,int operand2)
{
   switch ( (char) op )
   {
      case '*': return ( operand2 * operand1 );
      case '/': return ( operand2 / operand1 );
      case '+': return ( operand2 + operand1 );
      case '-': return ( operand2 - operand1 );
   }
}

/* ---------------------------------------- */
/*  主程式: 建立表达式二叉树后计算结果.     */
/* ---------------------------------------- */
void main()
{
   btree root = NULL;             /* 表达式二叉树指标   */
   int result;                    /* 结果变数           */

   /* 表达式二叉树节点数据 */
   int data[8] = { ' ', '+', '*', '*', '5',
                   '6', '4', '3' };
   root = createbtree(data,1);    /* 建立表达式二叉树   */
   printf("中序表达式: ");
   inorder(root);                 /* 中序列印二叉树     */
   printf("\n前序表达式: ");
   preorder(root);                /* 前序列印二叉树     */
   printf("\n后序表达式: ");
   postorder(root);               /* 后序列印二叉树     */
   result = cal(root);            /* 计算结果           */
   printf("\n表达式结果是:%d\n",result); /* 印出结果    */
}
