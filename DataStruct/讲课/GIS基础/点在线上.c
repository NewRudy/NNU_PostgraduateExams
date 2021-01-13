#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{		//点结构，x，y坐标
    double x,y;
}point;
typedef struct{		//线结构，start，end两点
    point start,end;
}line;

double function(point p){		//计算向量的绝对值
	double res = p.x*p.x + p.y*p.y;
    return sqrt(res);
}
int judge(point p,line l){		//判断点p是否在l上
    l.start.x -= p.x;		//p为起点，start和end为终点建立两个向量
    l.start.y -= p.y;
    l.end.x -= p.x;
    l.end.y -= p.y;
    double cos_value;
    cos_value = (l.start.x*l.end.x+l.start.y*l.end.y)/function(l.start)/function(l.end);
    printf("cos_value:%lf\t",cos_value);
    if(cos_value-1 == 0){
        printf("p在l线上，在线两点间");
    	return 1;
    }
    else if(cos_value+1 == 0){
        printf("p在l线上， 在延长线上");
    	return 1;
    }
    else{
        printf("p没有在l线上");
        return 0;
    }
}
int main(){
    point p;
    line l;
    printf("Enter p:\n");
    scanf("%lf%lf",&(p.x),&(p.y));
    printf("Enter l:\n");
    scanf("%ld%ld%ld%ld",&(l.start.x),&(l.start.y),&(l.end.x),&(l.end.y));
    judge(p,l);
}