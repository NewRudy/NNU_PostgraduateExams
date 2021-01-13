typedef struct node{
    char data;
    struct node* lchild,* rchild;
}node;

node* function(char str1[],char str2[],int n){       //
    if(n==0)        //
        return 0;
    node* root = (node*)malloc(sizeof(node));
    root->data = str1[0];
    char c = str1[0];
    int i;
    for(i=0;i<n;++i)        //
        if(str2[i]==c)
            break;
    root->lchild = function(str1+1,str2,i);     //
    root->rchild = function(str1+1+i,str2+1+i,n-i-1);       //
    return root;
}

void fun(char a[],int n,int i){
    if(n==0)
        return;
    a[i] = n%10 +'0';
    fun(a,n/10,i--);    
}
