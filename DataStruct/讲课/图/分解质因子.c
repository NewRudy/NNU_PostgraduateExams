#include <stdio.h>
#include<math.h>

int main(){
	int n,i;          //输入正整数n
	while(scanf("%d",&n)&&n!=0){
		printf("%d=",n);
		for(i=2;i<=sqrt(n);i++){  //找出n的最小质因数，利用循环，反复求最小质因数
		for(;n!=i;)
        {
			if(n%i==0)
			{
				printf("%d*",i);
				n=n/i;
			}
            if(n%i) 	//
				break;
		}
	}
	printf("%d\n",n);
	}
	return 0;
}