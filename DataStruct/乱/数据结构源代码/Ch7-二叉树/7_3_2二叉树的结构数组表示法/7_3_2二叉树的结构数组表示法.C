/* ======================================== */
/*    程式实例: 7_3_2.c                     */
/*    二叉树的结构数组表示法                */
/* ======================================== */
#include <stdlib.h>

struct tree                         /* 树的结构宣告       */
{
   int data;                        /* 节点数据           */
   int left;                        /* 指向左子树的位置   */
   int right;                       /* 指向右子树的位置   */
};
typedef struct tree treenode;       /* 树的结构新型态     */
treenode btree[15];                 /* 宣告树的结构数组   */

/* ---------------------------------------- */
/*  建立二叉树                              */
/* ---------------------------------------- */
void createbtree(int *data,int len)
{
   int level;                       /* 树的阶层           */
   int pos;                         /* -1是左树,1是右树   */
   int i;

   btree[0].data = data[0];         /* 建立树根节点       */
   for ( i = 1; i < len; i++ )      /* 用回路建立其它节点 */
   {
      btree[i].data = data[i];      /* 建立节点内容       */
      level = 0;                    /* 从树根开始         */
      pos = 0;                      /* 设定pos值          */
      while ( pos == 0 )            /* 用回路找节点位置   */
      {
         /* 比较是左或右子树 */
         if ( data[i] > btree[level].data )
            /* 右树是否有下一阶层 */
            if ( btree[level].right != -1 )
               level = btree[level].right;
            else
               pos = -1;            /* 是右树             */
         else
            /* 左树是否有下一阶层 */
            if ( btree[level].left != -1 )
               level = btree[level].left;
            else
               pos = 1;             /* 是左树             */
      }
      if ( pos == 1 )               /* 建立节点左右位置   */
         btree[level].left = i;     /* 链结左子树         */
      else
         btree[level].right = i;    /* 链结右子树         */
   }
}

/* ---------------------------------------- */
/*  主程式: 建立结构数组的二叉树状结构.     */
/*  数字-1表示没有下一阶层.                 */
/* ---------------------------------------- */
void main()
{
   /* 二叉树节点数据 */
   int data[10] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
   int i;

   for ( i = 0; i < 15; i++ )       /* 清除树状结构数组   */
   {
      btree[i].data = 0;            /* 设定初始内容       */
      btree[i].left = -1;           /* 设定初始内容       */
      btree[i].right = -1;          /* 设定初始内容       */
   }
   createbtree(data,9);            /* 建立二叉树         */
   printf("    左  数据  右\n");
   printf("----------------- \n");
   for ( i = 0; i < 15; i++ )       /* 列出二叉树内容     */
      if ( btree[i].data != 0 )     /* 是否是树的节点     */
         printf("%2d:[%2d] [%2d] [%2d]\n",i,btree[i].left,
                 btree[i].data,btree[i].right);
}
