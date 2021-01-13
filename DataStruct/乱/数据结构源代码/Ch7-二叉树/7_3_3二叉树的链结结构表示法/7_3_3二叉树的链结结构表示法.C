/* ======================================== */
/*    程式实例: 7_3_3.c                     */
/*    二叉树的链结结构表示法                */
/* ======================================== */
#include <stdlib.h>

struct tree                       /* 树的结构宣告       */
{
   int data;                      /* 节点数据           */
   struct tree *left;             /* 指向左子树的指标   */
   struct tree *right;            /* 指向右子树的指标   */
};
typedef struct tree treenode;     /* 树的结构新型态     */
typedef treenode *btree;          /* 宣告树节点指标型态 */

/* ---------------------------------------- */
/*  插入二叉树的节点                        */
/* ---------------------------------------- */
btree insertnode(btree root,int value)
{

   btree newnode;                 /* 树根指标           */
   btree current;                 /* 目前树节点指标     */
   btree back;                    /* 父节点指标         */

   /* 建立新节点记忆体 */
   newnode = ( btree ) malloc(sizeof(treenode));
   newnode->data = value;         /* 建立节点内容       */
   newnode->left = NULL;          /* 设定指标初值       */
   newnode->right = NULL;         /* 设定指标初值       */
   if ( root == NULL )            /* 是否是根节点       */
   {
      return newnode;             /* 传回新节点位置     */
   }
   else
   {
      current = root;             /* 保留目前树指标     */
      while ( current != NULL )
      {
         back = current;          /* 保留父节点指标     */
         if ( current->data > value )    /* 比较节点值  */
            current = current->left;     /* 左子树      */
         else
            current = current->right;    /* 右子树      */
      }
      if ( back->data > value )   /* 接起父子的链结     */
         back->left = newnode;    /* 左子树             */
      else
         back->right = newnode;   /* 右子树             */
   }
   return root;                   /* 传回树根指标       */
}

/* ---------------------------------------- */
/*  建立二叉树                              */
/* ---------------------------------------- */
btree createbtree(int *data,int len)
{
   btree root = NULL;             /* 树根指标           */
   int i;

   for ( i = 0; i < len; i++ )    /* 用回路建立树状结构 */
      root = insertnode(root,data[i]);
   return root;
}

/* ---------------------------------------- */
/*  二叉树列印                              */
/* ---------------------------------------- */
void printbtree(btree root)
{
   btree ptr;

   ptr = root->left;
   printf("列印左子树:\n");
   while ( ptr != NULL )          /* 列印回路           */
   {
      printf("[%2d]\n",ptr->data);  /* 列印节点内容     */
      ptr = ptr->left;            /* 左子节点           */
   }
   ptr = root->right;
   printf("列印右子树:\n");
   while ( ptr != NULL )          /* 列印回路           */
   {
      printf("[%2d]\n",ptr->data);  /* 列印节点内容     */
      ptr = ptr->right;           /* 右子节点           */
   }
}

/* ---------------------------------------- */
/*  主程式: 建立链结的二叉树且列印出来.     */
/* ---------------------------------------- */
void main()
{
   btree root = NULL;             /* 树根指标           */

   /* 二叉树节点数据 */
   int data[10] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   root = createbtree(data,9);    /* 建立二叉树         */
   printf("树的节点内容 \n");
   printbtree(root);              /* 列出二叉树内容     */
}
