int* arr = (int*)malloc(sizeof(int)*n);         //动态分配地址，int arr[n]是错误的写法
    memset(arr,-1,(n+1)*sizeof(int));               //memset,快速给数组所有值赋值，头文件memory.h
    // for(int i=0;i<=n;++i)
    //     arr[i] = -1;
    printf("递归结果：%d\n循环结果：%d\n递归优化：%d\n",function1(n),function2(n),function3(n,arr));