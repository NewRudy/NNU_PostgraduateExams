/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
///尝试写一下哈希表

//哈希表结构
typedef struct node
{
    int key;
    int data;
    struct node *next;    
}node;
typedef struct hash
{
    node arr[16];     //结点数组
}hash;
//初始化
void init(hash *table)
{
    for(int i=0;i<16;++i)
    {
        table->arr[i].key = i;
        table->arr[i].next = 0;
    }
}
//插入
void insert(hash *table,int num,int n)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->key = n;
    temp->data = num;
    int k = abs(num)%16;
    temp->next = table->arr[k].next;        //头插法
    table->arr[k].next = temp;
}
//查找
int find(hash *table,int num)
{
    int k = abs(num)%16;
    node *temp = table->arr[k].next;
    while(temp)
    {
        if(temp->data == num)
            return temp->key;
        temp = temp->next;
    }
    return -1;
}
//销毁
void destroy(hash *table)
{
    for(int i=0;i<16;++i)
    {
        node *temp = table->arr[i].next;
        while(temp)
        {
            node *now = temp;
            temp = temp->next;
            free(now);
        }
        table->arr[i].next = 0; 
    }
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    if(numsSize<2||!nums)
        return 0;
    static int res[2];
    res[0] = -1;res[1] = -1;
    *returnSize = 2;
    hash table;
    init(&table);
    int i,j;
    for(i=0;i<numsSize;++i)         //逐个插入
        insert(&table,nums[i],i);
    for(i=0;i<numsSize;++i)
    {
        res[0] = i;
        j = find(&table,target-nums[i]);
        if(j>i)
        {
            res[1] = j;
            break;
        }
    }
    destroy(&table);
    return res;
}