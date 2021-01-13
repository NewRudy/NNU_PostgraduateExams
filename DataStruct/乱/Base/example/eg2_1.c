#include <stdio.h>
typedef int elemType;

int main()
{
    //定义顺序表
    typedef struct
    {
        elemType *head; //声明了一个名为head的长度不确定的动态数组
        elemType length;    //记录当前顺序表的长度
        elemType size;  //记录顺序表分配的存储容量

    }Sqlist;
    //初始化
    #define maxsize 5
    Sqlist initSqlist()
    {
        Sqlist list;
        list.head = (Sqlist*)malloc(maxsize*sizeof(Sqlist));
        if(!list.head)
        {
            printf("申请失败！");
            exit(0);
        }
        list.length = 0;
        list.size = maxsize;
        return list;
    }
}

