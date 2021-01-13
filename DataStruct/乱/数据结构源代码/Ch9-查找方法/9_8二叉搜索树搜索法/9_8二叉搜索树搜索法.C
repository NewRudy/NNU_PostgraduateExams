/* ======================================== */
/*    程式实例: 9_8.c                       */
/*    二叉搜索树搜索法                      */
/* ======================================== */
#include <stdlib.h>

struct tree                       /* 树的结构宣告        */
{
   int data;                      /* 节点数据            */
   struct tree *left;             /* 指向左子树的指标    */
   struct tree *right;            /* 指向右子树的指标    */
};
typedef struct tree treenode;     /* 树的结构新型态      */
typedef treenode *btree;          /* 宣告树节点指标型态  */

/* ---------------------------------------- */
/*  插入二叉树的节点                        */
/* ---------------------------------------- */
btree insertnode(btree root,int value)
{

   btree newnode;                 /* 树根指标            */
   btree current;                 /* 目前树节点指标      */
   btree back;                    /* 父节点指标          */

   /* 建立新节点记忆体 */
   newnode = ( btree ) malloc(sizeof(treenode));
   newnode->data = value;         /* 建立节点内容        */
   newnode->left = NULL;          /* 设定指标初值        */
   newnode->right = NULL;         /* 设定指标初值        */
   if ( root == NULL )            /* 是否是根节点        */
   {
      return newnode;             /* 传回新节点位置      */
   }
   else
   {
      current = root;             /* 保留目前树指标      */
      while ( current != NULL )
      {
         back = current;          /* 保留父节点指标      */
         if ( current->data > value ) /* 比较节点值      */
            current = current->left;  /* 左子树          */
         else
            current = current->right; /* 右子树          */
      }
      if ( back->data > value )   /* 接起父子的链结      */
         back->left = newnode;    /* 左子树              */
      else
         back->right = newnode;   /* 右子树              */
   }
   return root;                   /* 传回树根指标        */
}

/* ---------------------------------------- */
/*  建立二叉树                              */
/* ---------------------------------------- */
btree createbtree(int *data,int len)
{
   btree root = NULL;             /* 树根指标            */
   int i;

   for ( i = 0; i < len; i++ )    /* 用回路建立树状结构  */
      root = insertnode(root,data[i]);
   return root;
}

/* ---------------------------------------- */
/*  使用二叉搜索树执行搜索                  */
/* ---------------------------------------- */
btree btreesearch(btree ptr,int value)
{
   while ( ptr != NULL )          /* 主回路              */
   {
      if ( ptr->data == value )   /* 找到了              */
         return ptr;              /* 传回节点指标        */
      else
         if ( ptr->data > value ) /* 比较数据            */
            ptr = ptr->left;      /* 左子树              */
         else
            ptr = ptr->right;     /* 右子树              */
   }
   return NULL;                   /* 没有找到            */
}

/* ---------------------------------------- */
/*  主程式: 使用二叉搜索树执行搜索          */
/* ---------------------------------------- */
void main()
{
   btree root = NULL;             /* 树根指标            */
   btree ptr = NULL;              /* 树指标              */
   int value;                     /* 节点值              */
   /* 二叉树节点数据 */
   int data[9] = { 55, 61, 41, 87, 24, 35, 79, 11, 99 };

   root = createbtree(data,9);    /* 建立树状结构        */
   while ( 1 )                    /* 主回路开始          */
   {
      printf("请输入寻找数据(0 - 99) ==> ");
      scanf("%d",&value);         /* 读取数据            */
      if ( value != -1 )          
      {
         ptr = btreesearch(root,value); /* 使用二叉搜索树执行搜索 */
         if ( ptr != NULL )
            printf("二叉搜索树搜索: 节点数据是 [%d]\n",ptr->data);
         else
            printf("二叉搜索树搜索: 没有找到\n");
      }
      else
         exit(1);                 /* 结束程式            */

   }
}
