/* ======================================== */
/*    程式实例: 7_6.c                       */
/*    二叉树的搜索方式                      */
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
/*  二叉搜索树的搜索                        */
/* ---------------------------------------- */
btree btreefind(btree ptr,int value)
{
   while ( ptr != NULL )          /* 主回路             */
   {
      if ( ptr->data == value )   /* 找到了             */
         return ptr;              /* 传回节点指标       */
      else
         if ( ptr->data > value ) /* 比较数据           */
            ptr = ptr->left;      /* 左子树             */
         else
            ptr = ptr->right;     /* 右子树             */
   }
   return NULL;                   /* 没有找到           */
}

/* ---------------------------------------- */
/*  二叉树遍历搜索                          */
/* ---------------------------------------- */
btree btreesearch(btree ptr,int value)
{
   btree ptr1,ptr2;

   if ( ptr != NULL )             /* 终止条件           */
   {
      if ( ptr->data == value )   /* 找到了             */
         return ptr;              /* 传回节点指标       */
      else
      /* 往左子树找 */
      ptr1 = btreesearch(ptr->left,value);
      /* 往右子树找 */
      ptr2 = btreesearch(ptr->right,value);
      if ( ptr1 != NULL )
         return ptr1;             /* 在左子树           */
      else
         if ( ptr2 != NULL )
            return ptr2;          /* 在右子树           */
         else
            return NULL;          /* 没有找到           */
   }
   else
      return NULL;                /* 是叶节点           */
}

/* ---------------------------------------- */
/*  主程式: 二叉树搜索方式.                 */
/* ---------------------------------------- */
void main()
{
   btree root = NULL;             /* 树根指标           */
   btree ptr = NULL;              /* 树根指标           */
   int value;                     /* 节点值             */

   /* 二叉树节点数据 */
   int data[16] = { 0, 5, 4, 6, 2, 0, 0, 8, 1,
                    3, 0, 0, 0, 0, 7, 9 };
   root = createbtree(data,1);    /* 建立树状结构       */
   printf("请输入寻找节点数据(1 - 9) ==> ");
   scanf("%d",&value);            /* 读取节点数据       */
   ptr = btreefind(root,value);   /* 二叉树搜索         */
   if ( ptr != NULL )
      printf("二叉搜索树: 节点数据是 [%d]\n",ptr->data);
   else
      printf("二叉搜索树: 没有找到\n");
   ptr = btreesearch(root,value); /* 遍历搜索         */
   if ( ptr != NULL )
      printf("遍历搜索: 节点数据是 [%d]\n",ptr->data);
   else
      printf("遍历搜索: 没有找到\n");
}
