/* ======================================== */
/*    程式实例: 4_2_2.c                     */
/*    稀疏阵列的环状链结串列表示法          */
/* ======================================== */
#include <stdlib.h>

struct clist                      /* 环状串列结构宣告     */
{
   int row;                       /* 阵列的列             */
   int col;                       /* 阵列的行             */
   int data;                      /* 节点资料             */
   struct clist *right;           /* 指向同一列节点指标   */
   struct clist *down;            /* 指向同一行节点指标   */
};
typedef struct clist cnode;       /* 环状串列新型态       */
typedef cnode *clink;             /* 环状串列指标新型态   */

/* ---------------------------------------- */
/*  建立稀疏阵列的开头节点阵列              */
/* ---------------------------------------- */
clink create_matrix(int row,int col)
{
   clink head;                    /* 稀疏阵列指标         */
   int len;                       /* 阵列的长度           */
   int i;

   /* 计算阵列长度,取行与列之最大值 */
   if ( row > col )
      len = row;
   else
      len = col;

   /* 配置开头节点阵列阵列记忆体 */
   head = ( clink ) malloc(sizeof(cnode) * len);
   if ( !head )                   /* 检查记忆体指标       */
      return NULL;
   head[0].row = row;             /* 阵列的列             */
   head[0].col = col;             /* 阵列的行             */

   for ( i = 0; i < len; i++ )    /* 用回路设定指标初值   */
   {
      head[i].right = &head[i];   /* 设定指标指向自己     */
      head[i].down = &head[i];    /* 设定指标指向自己     */
   }

   return head;                   /* 传回稀疏阵列指标     */
}

/* ---------------------------------------- */
/*  稀疏阵列的阵列元素插入                  */
/* ---------------------------------------- */
clink insert_matrix(clink head,int row,int col,int value)
{
   clink new_node;                /* 新节点的指标         */
   clink pos;                     /* 插入的位置           */

   /* 建立新节点配置节点记忆体 */
   new_node = ( clink ) malloc(sizeof(cnode));
   if ( !new_node )               /* 检查记忆体指标       */
      return NULL;
   /* 稀疏阵列的实际大小 */
   new_node->row = row;           /* 阵列的列             */
   new_node->col = col;           /* 阵列的行             */
   new_node->data = value;        /* 建立节点内容         */

   /* 插入由指标down接成行串列 */
   pos = &head[col];              /* 设定行串列指标       */
   /* 用回路来找插入列row */
   while ( pos->down != &head[col] && row > pos->down->row )
      pos = pos->down;            /* 指向下一个节点       */
   new_node->down = pos->down;    /* 新节点指向下一节点   */
   pos->down = new_node;          /* 前一节点指向新节点   */

   /* 插入由指标right接成列串列 */
   pos = &head[row];              /* 设定列串列指标       */
   /* 用回路来找插入行col */
   while ( pos->right != &head[row] && col > pos->right->col )
      pos = pos->right;           /* 指向下一个节点       */
   new_node->right = pos->right;  /* 新节点指向下一节点   */
   pos->right = new_node;         /* 前一节点指向新节点   */

   return head;                   /* 传回稀疏阵列指标     */
}

/* ---------------------------------------- */
/*  稀疏阵列的列印                          */
/* ---------------------------------------- */
void print_matrix(clink head)
{
   clink ptr;
   clink now;
   int i;

   printf("  列   行     值 \n");
   printf("=================\n");

   /* 从down指标串成的串列来列印 */
   for ( i = 0; i < head[0].col; i++ )
   {
      now = head[i].down;
      ptr = &head[i];
      while  ( now != ptr )       /* 走访指标down回路     */
      {
         printf("[%3d][%3d]=[%4d]\n",now->row,now->col,now->data);
         /* 列印节点资料 */
         now = now->down;         /* 指向下一个节点       */
      }
   }
}

/* ---------------------------------------- */
/*  主程式:                                 */
/*  使用环状链结串列来建立稀疏阵列, 完成後  */
/*  将阵列内容印出.                         */
/* ---------------------------------------- */
void main()
{
   clink head;                    /* 稀疏阵列指标         */
   int sparse[5][6] = {           /* 稀疏阵列的内容       */
                         0, 0, 1, 0, 0, 0,
                         0, 3, 0, 9, 0, 0,
                         0, 4, 0, 0, 0, 2,
                         7, 0, 0, 0, 3, 0,
                         0, 0, 0, 6, 0, 0 };
   int i,j;

   head = create_matrix(5,6);     /* 建立稀疏阵列         */
   for ( i = 0; i < 5; i++ )      /* 二维阵列的走访       */
      for ( j = 0; j < 6; j++ )
         if ( sparse[i][j] != 0 ) /* 有没有使用           */
            /*  稀疏阵列的阵列元素插入 */
            head = insert_matrix(head,i,j,sparse[i][j]);
   print_matrix(head);            /* 列出阵列内容         */
}
