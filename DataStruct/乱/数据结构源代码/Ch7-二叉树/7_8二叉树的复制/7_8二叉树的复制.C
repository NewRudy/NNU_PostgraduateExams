/* ======================================== */
/*    程式实例: 7_8.c                        */
/*    二叉树的复制                          */
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
/*  建立二叉树                              */
/* ---------------------------------------- */
btree createbtree(int *data,int pos)
{
   btree newnode;                 /* 新节点指标         */

   if ( data[pos] == 0 || pos > 15 )  /* 终止条件       */
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
/*  二叉树复制                              */
/* ---------------------------------------- */
btree copybtree(btree root)
{
   btree newnode;                 /* 新节点指标         */

   if ( root == NULL )            /* 终止条件           */
      return NULL;
   else
   {
      /* 建立新节点记忆体 */
      newnode = ( btree ) malloc(sizeof(treenode));
      newnode->data = root->data; /* 建立节点内容       */
      /* 拷贝左子树 */
      newnode->left = copybtree(root->left);
      /* 拷贝右子树 */
      newnode->right = copybtree(root->right);
      return newnode;
   }
}

/* ---------------------------------------- */
/*  二叉树中序列印                          */
/* ---------------------------------------- */
void printbtree(btree ptr)
{
   if ( ptr != NULL )             /* 终止条件           */
   {
      printbtree(ptr->left);      /* 左子树             */
      printf("[%2d]",ptr->data);  /* 列印节点内容       */
      printbtree(ptr->right);     /* 右子树             */
   }
}

/* ---------------------------------------- */
/*  主程式: 建立二叉树后备份它.             */
/* ---------------------------------------- */
void main()
{
   btree root = NULL;             /* 原二叉树指标       */
   btree backup = NULL;           /* 复制二叉树指标     */

   /* 二叉树节点数据 */
   int data[16] = { 0, 5, 4, 6, 2, 0, 0, 8, 1,
                    3, 0, 0, 0, 0, 7, 9 };
   root = createbtree(data,1);    /* 建立树状结构       */
   backup = copybtree(root);      /* 复制二叉树         */
   printf("原二叉树的节点内容 \n");
   printbtree(root);              /* 中序列印二叉树     */
   printf("\n备份二叉树的节点内容 \n");
   printbtree(backup);            /* 中序列印二叉树     */
   printf("\n");                  /* 换行               */
}
