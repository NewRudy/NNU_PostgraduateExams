/* ======================================== */
/*    程式实例: 7_7.c                       */
/*    二叉树的节点删除                      */
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
/*  二叉树搜索                              */
/* ---------------------------------------- */
btree btreefind(btree ptr,int value,int *pos)
{
   btree previous;                /* 父节点指标         */

   previous = ptr;                /* 设定指标初值       */
   *pos = 0;                      /* 设定位置初值       */
   while ( ptr != NULL )          /* 主回路             */
   {
      if ( ptr->data == value )   /* 找到了             */
         return previous;         /* 传回父节点指标     */
      else
         previous = ptr;          /* 保留父节点指标     */
         if ( ptr->data > value ) /* 比较数据           */
         {
            ptr = ptr->left;      /* 左子树             */
            *pos = -1;            /* pos是-1            */
         }
         else
         {
            ptr = ptr->right;     /* 右子树             */
            *pos = 1;             /* pos是1             */
         }
   }
   return NULL;                   /* 没有找到           */
}

/* ---------------------------------------- */
/*  二叉树节点删除                          */
/* ---------------------------------------- */
btree deletenode(btree root,int value)
{
   btree previous;                /* 父节点指标         */
   btree ptr;                     /* 删除的节点指标     */
   btree next;                    /* 子节点指标         */
   int pos;                       /* 删除位置           */

   /* 寻找节点值的父节点指标 */
   previous = btreefind(root,value,&pos);
   if ( previous == NULL )        /* 没有找到           */
      return root;
   switch( pos )                  /* 删除位置           */
   {
      case -1: ptr = previous->left;  /* 左子节点       */
               break;
      case  1: ptr = previous->right; /* 右子节点       */
               break;
      case  0: ptr = previous;        /* 根节点         */
               break;
   }
   /* 第一种情况: 没有左子树 */
   if ( ptr->left == NULL )
   {
      if ( previous != ptr )      /* 是否是根节点       */
         /* 不是, 父节点的右子节点指向目前节点的右子节点 */
         previous->right = ptr->right;
      else
         root = root->right;      /* 根节点指向右子节点 */
      free(ptr);                  /* 释回节点记忆体     */
      return root;                /* 传回根节点         */
   }
   /* 第二种情况: 没有右子树 */
   if ( ptr->right == NULL )
   {
      if ( previous != ptr )      /* 是否是根节点       */
         /* 不是, 父节点的左子节点指向目前节点的左节点  */
         previous->left = ptr->left;
      else
         root = root->left;       /* 根节点指向左子节点 */
      free(ptr);                  /* 释回节点记忆体     */
      return root;                /* 传回根节点         */
   }
   /* 第三种情况: 有左子树和右子树 */
   previous = ptr;                /* 父节点指向目前节点 */
   next = ptr->left;              /* 设定子节点         */
   while ( next->right != NULL )  /* 找到最右的叶节点   */
   {
      previous = next;            /* 保留父节点指标     */
      next = next->right;         /* 往右子树走         */
   }
   ptr->data = next->data;        /* 设定成叶节点数据   */
   if ( previous->left == next )  /* 建立链结           */
      previous->left = next->left;    /* 是左子节点     */
   else
      previous->right = next->right;  /* 是最右的叶节点 */
   free(next);                    /* 释回节点记忆体     */
   return root;                   /* 传回根节点         */
}

/* ---------------------------------------- */
/*  二叉树中序列印                          */
/* ---------------------------------------- */
void printbtree(btree ptr)
{
   if ( ptr != NULL )             /* 终止条件           */
   {
      printbtree(ptr->left);     /* 左子树             */
      printf("[%2d]",ptr->data);  /* 列印节点内容       */
      printbtree(ptr->right);    /* 右子树             */
   }
}

/* ---------------------------------------- */
/*  主程式: 建立二叉树后删除一节点.         */
/* ---------------------------------------- */
void main()
{
   btree root = NULL;             /* 树根指标           */
   int value;                     /* 节点值             */

   /* 二叉树节点数据 */
   int data[16] = { 0, 5, 4, 6, 2, 0, 0, 8, 1,
                    3, 0, 0, 0, 0, 7, 9 };
   root = createbtree(data,1);    /* 建立树状结构       */
   printbtree(root);              /* 中序列印二叉树     */
   printf("\n请输入寻找节点数据 ==> ");
   scanf("%d",&value);            /* 读取节点数据       */
   root = deletenode(root,value); /* 删除节点值是value*/
   printf("删除后树的节点内容 \n");
   printbtree(root);              /* 中序列印二叉树     */
   printf("\n");                  /* 换行               */
}

