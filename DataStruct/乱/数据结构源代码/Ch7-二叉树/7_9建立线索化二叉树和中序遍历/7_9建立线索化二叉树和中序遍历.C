/* ======================================== */
/*    程式实例: 7_9.c                       */
/*    建立线索化二叉树和中序遍历              */
/* ======================================== */
#include <stdlib.h>

struct t_tree                     /* 树的结构宣告       */
{
   int data;                      /* 节点数据           */
   int leftthread;                /* 是否是左线索化       */
   int rightthread;               /* 是否是右线索化       */
   struct t_tree *left;           /* 指向左子树的指标   */
   struct t_tree *right;          /* 指向右子树的指标   */
};
typedef struct t_tree treenode;   /* 树的结构新型态     */
typedef treenode *t_btree;        /* 宣告树节点指标型态 */

/* ---------------------------------------- */
/*  插入线索化二叉树的节点                    */
/* ---------------------------------------- */
t_btree insertnode(t_btree root,int value)
{

   t_btree newnode;               /* 新节点指标         */
   t_btree current;               /* 目前树节点指标     */
   t_btree parent;                /* 父节点指标         */
   t_btree previous;              /* 后继节点指标       */
   int pos;                       /* 保留走向           */

   /* 建立新节点记忆体 */
   newnode = ( t_btree ) malloc(sizeof(treenode));
   newnode->data = value;         /* 建立节点内容       */
   newnode->left = NULL;          /* 设定指标初值       */
   newnode->right = NULL;         /* 设定指标初值       */
   newnode->leftthread = 1;       /* 是线索化             */
   newnode->rightthread = 1;      /* 是线索化             */
   current = root->right;         /* 目前树根指标       */
   if ( current == NULL )         /* 是否是树根         */
   {
      root->right = newnode;      /* 链结开头节点       */
      newnode->left = root;       /* 指标指向指标root   */
      newnode->right = root;      /* 指标指向指标root   */
      return root;                /* 传回树根           */
   }
   parent = root;                 /* 父节点是开头节点   */
   pos = 0;                       /* 设定走向           */
   while ( current != NULL )      /* 寻找位置的回路     */
   {
      if ( current->data > value )  /* 比较节点值       */
      {
         if ( pos != -1 )         /* 走向不同           */
         {
            pos = -1;             /* 记录新走向         */
            previous = parent;    /* 记录后继节点指标   */
         }
         parent = current;        /* 保留父节点指标     */
         if ( current->leftthread == 0 ) /* 是否是线索化  */
            current = current->left;     /* 左子树      */
         else
            current = NULL;       /* 是线索化             */
      }
      else
      {
         if ( pos != 1 )          /* 走向不同           */
         {
            pos = 1;              /* 记录新走向         */
            previous = parent;    /* 记录后继节点指标   */
         }
         parent = current;        /* 保留父节点指标     */
         if ( current->rightthread == 0 ) /* 是否是线索化 */
            current = current->right;     /* 右子树     */
         else
            current = NULL;       /* 是线索化             */
      }
   }
   if ( parent->data > value )    /* 接起父子的链结     */
   {
      parent->leftthread = 0;     /* 不是线索化           */
      parent->left = newnode;     /* 是左子树           */
      newnode->left = previous;   /* 指标指向previous   */
      newnode->right = parent;    /* 指标指向parent     */
   }
   else
   {
      parent->rightthread = 0;    /* 不是线索化           */
      parent->right = newnode;    /* 是右子树           */
      newnode->left = parent;     /* 指标指向parent     */
      newnode->right = previous;  /* 指标指向previous   */
   }
   return root;                   /* 传回树根指标       */
}

/* ---------------------------------------- */
/*  建立线索化二叉树                          */
/* ---------------------------------------- */
t_btree createtbtree(int *data,int len)
{
   t_btree root = NULL;           /* 树根指标           */
   int i;

   /* 建立线索化二叉树的开头节点记忆体 */
   root = ( t_btree ) malloc(sizeof(treenode));
   root->left = root;             /* 设定指标初值       */
   root->right = NULL;            /* 设定指标初值       */
   root->leftthread = 1;          /* 是线索化             */
   root->rightthread = 0;         /* 不是线索化           */

   for ( i = 0; i < len; i++ )    /* 用回路建立树状结构 */
      root = insertnode(root,data[i]);
   return root;
}

/* ---------------------------------------- */
/*  线索化二叉树中序遍历列印                  */
/* ---------------------------------------- */
void printtbtree(t_btree root)
{
   t_btree ptr;

   ptr = root;                    /* 指向开头节点       */
   do                             /* 中序遍历回路       */
   {
      if ( ptr->rightthread == 1 )  /* 右子节点是否是线索化 */
         ptr = ptr->right;        /* 往右子树走         */
      else
      {
         ptr = ptr->right;        /* 先到右子节点       */
         while ( ptr->leftthread != 1 ) /*当左子节点不是线索化*/
            ptr = ptr->left;      /* 往左子树走         */
      }
      if ( ptr != root )          /* 如果不是开头节点   */
         printf("[%d]\n",ptr->data);    /* 印出节点内容 */
   } while ( ptr != root );       /* 直到找到开头节点   */
}

/* ---------------------------------------- */
/*  主程式: 建立线索化二叉树且列印出来.       */
/* ---------------------------------------- */
void main()
{
   t_btree root = NULL;           /* 树根指标           */

   /* 线索化二叉树节点数据 */
   int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   root = createtbtree(data,9);   /* 建立线索化二叉树     */
   printf("线索化二叉树的节点内容 \n");
   printtbtree(root);             /* 列出二叉树内容     */
}
