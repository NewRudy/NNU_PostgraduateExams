/* ======================================== */
/*    程式实例: 12_4.cpp                    */
/*    链结串列类别实作                      */
/* ======================================== */
#include <iostream>
using namespace std;

struct llink                      /* 串列结构宣告      */
{  
    int data;                     /* 串列资料          */
    llink *next;                  /* 指向下一个资料    */ 
};

class linklist                    /* Linklist类别宣告  */
{
private:
    llink *first;                 /* 串列的开始指标    */
public:
    linklist() { first = NULL; }  /* 建构函数          */
    void insertNode(int d);       /* 成员函数的宣告    */
    void deleteNode(int d); 
    void printLlist();
    int search(int d);
};

/* ---------------------------------------- */
/*  成员函数: 在串列开头插入节点            */
/* ---------------------------------------- */
void linklist::insertNode(int d)
{
    /* 建立节点记忆体 */
    llink *newnode = new llink;

    newnode->data = d;            /* 建立节点内容      */
    newnode->next = first;        /* 连结节点          */
    first = newnode;              /* 指向新节点        */
}

/* ---------------------------------------- */
/*  成员函数: 删除指定资料的节点            */
/* ---------------------------------------- */
void linklist::deleteNode(int d)
{
    llink *current = first;       /* 建立目前的串列指标 */
    llink *last= current;         /* 建立前一个串列指标 */

    if ( current == NULL )        /* 检查串列是否是空的 */
       return;
    else{
       while ( current != NULL )  /* 走访串列节点的回路 */
       {
           /* 是否找到资料且是第一个节点 */
	   if (current->data == d && current == first )
           {
	      first = current->next; /* 重设串列指标    */
              delete current;        /* 释放串列节点    */
              return; 
           }     /* 是否找到资料且不是第一个节点 */
	   else if (current->data == d && current != first )
           {
                /* 前一个指标连接下一个指标 */
		last->next = current->next;
                delete current;      /* 释放串列节点    */
                return;
	   }
           else
		last = current;    /* 保留前一个串列指标 */
	   current = current->next;/* 下一个节点         */
       }
    }
}

/* ---------------------------------------- */
/*  成员函数: 走访搜寻指定的资料            */
/* ---------------------------------------- */
int linklist::search(int d){
    llink *current = first;       /* 建立目前的串列指标 */

    while ( current != NULL )     /* 搜寻主回路         */
    {
	if ( current->data == d ) /* 是否找到资料       */
           return 1;              /* 找到               */
	current = current->next;  /* 下一个节点         */
    }
    return 0;                     /* 没有找到           */
}

/* ---------------------------------------- */
/*  成员函数: 列印串列资料                  */
/* ---------------------------------------- */
void linklist::printLlist()
{
    llink *current = first;       /* 建立目前的串列指标 */

    while ( current != NULL )     /* 列印主回路         */
    {
        /* 列印节点资料 */
	cout << "[" << current->data << "]";
	current = current->next;  /* 下一个节点         */
    }
    cout << "\n";
}

/* ---------------------------------------- */
/*  主程式: 建立串列物件和测试成员函数      */
/* ---------------------------------------- */
void main()
{
    linklist Li;                    /* 建立物件           */
    int i,temp;
    int llist[6] = { 1, 2, 3, 4, 5, 6 }; /* 阵列内容      */

    for ( i = 0; i < 6; i++ )       /* 建立串列节点的回路 */
        Li.insertNode(llist[i]);    /* 插入节点           */

    cout << "原来的链表: ";
    Li.printLlist();                /* 列印原来串列       */

    cout << "请输入节点内容: ";     /* 输出字串           */
    cin >> temp;                    /* 输入节点资料       */
    /* 搜寻指定的节点资料 */
    if ( Li.search(temp) ) 
       cout << "链表包含节点[" << temp << "]!\n";
    Li.deleteNode(temp);            /* 删除节点           */
    cout << "删除后的链表: ";
    Li.printLlist();                /* 列印删除後串列     */
}
