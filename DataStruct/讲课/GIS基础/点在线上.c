#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{		//��ṹ��x��y����
    double x,y;
}point;
typedef struct{		//�߽ṹ��start��end����
    point start,end;
}line;

double function(point p){		//���������ľ���ֵ
	double res = p.x*p.x + p.y*p.y;
    return sqrt(res);
}
int judge(point p,line l){		//�жϵ�p�Ƿ���l��
    l.start.x -= p.x;		//pΪ��㣬start��endΪ�յ㽨����������
    l.start.y -= p.y;
    l.end.x -= p.x;
    l.end.y -= p.y;
    double cos_value;
    cos_value = (l.start.x*l.end.x+l.start.y*l.end.y)/function(l.start)/function(l.end);
    printf("cos_value:%lf\t",cos_value);
    if(cos_value-1 == 0){
        printf("p��l���ϣ����������");
    	return 1;
    }
    else if(cos_value+1 == 0){
        printf("p��l���ϣ� ���ӳ�����");
    	return 1;
    }
    else{
        printf("pû����l����");
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