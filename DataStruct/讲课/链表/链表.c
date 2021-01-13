#include <stdio.h>
#include <stdlib.h>

typedef struct node{        //结点结构
    int value;
    struct node* next;
}node;

void init(node* p,int* arr,int n){        //将arr数组转为链表的形式,尾插法
    if(!p||!arr)
        return;
    node* temp,*tail = p;   //tail一直指向链表的尾结点
    for(int i=0;i<n;++i){
        temp = (node*)malloc(sizeof(node));
        temp->value = arr[i];       //初始化
        temp->next = 0;
        tail->next = temp;      //尾插法
        tail = temp;
    }
}
void init2(node* p,int* arr,int n){        //将arr数组转为链表的形式,头插法
    if(!p||!arr)
        return;
    node* temp;
    for(int i=0;i<n;++i){
        temp = (node*)malloc(sizeof(node));
        temp->value = arr[i];       //初始化
        temp->next = 0;
        temp->next = p->next;       //头插法
        p->next = temp;
    }
}
 
void delete(node* p,int target){     //删除值为target的结点
    if(!p)      //判断链表是否存在
        return;
    node* prior = p,*later = p->next;
    while(later){       //遍历链表
        if(later->value==target){       //删除等于target的链表
            prior->next = later->next;
            later->next = 0;
            free(later);
            later = prior->next;        
        }
        else{
            later = later->next;
            prior = prior->next;
        }
    }
}

void reverse(node* p){      //翻转链表，头插法
    if(!p||!p->next)        //链表不存在或者没有结点的情况
        return;
    node* first = p->next,*temp = p->next->next;
    while(temp){       //遍历链表
        first->next = temp->next;       //将temp提出来
        temp->next = p->next;      //头插法
        p->next = temp;
        temp = first->next;     //temp 开始指向下一个结点
    }
}

void insert(node* p,int target){        //头插法的方式插入结点
    if(!p)
        return;
    node* temp = (node *)malloc(sizeof(node));
    temp->value = target;
    temp->next = p->next;       //头插法
    p->next = temp;
}
void insert2(node* p,int target){       //插入链表中最后的位置
    if(!p)
        return;
    node* temp = (node*)malloc(sizeof(node));
    temp->value = target;
    temp->next = 0;
    while(p->next)      //p找到最后个结点
        p = p->next;
    p->next = temp;
}
node* search(node* p,int target){       //寻找链表中第一个等于target的值的指针
    if(!p)
        return 0;
    p = p->next;        //从第一个结点开始找
    while(p){
        if(p->value==target)
            return p;
        p = p->next;
    }
    return 0;       //没有target，返回0
}
int num;        //全局变量，用来得到指针的个数
node** search2(node* p,int target){       //寻找链表中所有等于target的值的指针
    if(!p)
        return 0;
    p = p->next;
    node** result = (node**)malloc(sizeof(node*)*10);        //假设不超过10个结点,二重指针
    memset(result,0,sizeof(result));        //result所有元素赋值为0
    num = 0;
    while(p){
        if(p->value==target)
            result[num++] = p;
        p = p->next;
    }
    return result;
}

void output(node* p){       //从第一个结点开始输出链表
    if(!p)
        return;
    p = p->next;
    while (p){       //链表的循环
        printf("%d\t",p->value);
        p = p->next;
    }
    printf("\n");
}
void output2(node* p){      //输出一个结点的值
    if(!p)
        return;
    printf("%d\t",p->value);
}
int main(){
    int n;          //n是链表的大小
    printf("Enter the num of list:\n");
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);     //动态分配数组空间
    printf("Enter arr:\n");
    for(int i=0;i<n;++i)        //初始化arr
        scanf("%d",&arr[i]);
    int judge = 1,target;
    node* p = (node*)malloc(sizeof(node));      //链表头节点
    p->next = 0;
    printf("Enter the judge of init:\n");
    scanf("%d",&judge);
    if(judge==1)        //选择链表初始化的方式
        init(p,arr,n);
    else
        init2(p,arr,n);
    printf("the list:\n");
    output(p);

    printf("Enter judge,0 means quict,1 means delete,2 means reverse,3 means insert,4 means search \n");
    scanf("%d",&judge);
    while(judge){       //循环执行链表的基本操作
        switch (judge)
        {
        case 1:
            printf("Enter target:\n");
            scanf("%d",&target);
            delete(p,target);
            printf("the list after delete:\n");
            output(p);
            break;
        case 2:
            reverse(p);
            printf("the list after reverse:\n");
            output(p);
            break;
        case 3:
            printf("Enter your target:\n");
            scanf("%d",&target);
            printf("inset 1 or insert2?\n");
            scanf("%d",&judge);
            if(judge==1)
                insert(p,target);
            else if(judge==2)
                insert2(p,target);
            printf("The list after insert:\n");
            output(p);
            break;
        case 4:
            printf("Enter your target:\n");
            scanf("%d",&target);
            printf("search 1 or search 2:\n");
            scanf("%d",&judge);
            if(judge==1){
                node* temp = search(p,target);
                if(temp)
                    printf("point:%p\t,value:%d\n",temp,temp->value);
            }
            else if(judge==2){
                node** temp = search2(p,target);
                for(int i=0;i<num;++i)
                    printf("point:%p\t,value:%d\n",temp[i],temp[i]->value);
                printf("\n");
            }
            break;
        default:
            printf("your enter is not right.\n");
            break;
        }
        printf("Enter judge,0 means quict,1 means delete,2 means reverse,3 means insert,4 means search\n");
        scanf("%d",&judge);
    }
}