/* ======================================== */
/*   ����ʵ��: 12_2_4.cpp                  */
/*    ��ĳ������� - ʹ�ýṹ������̬     */
/* ======================================== */
#include <iostream>
using namespace std;

struct dateType                    /* ���ڽṹ����       */
{
    int day;                       /* �ṹ����           */  
    int month;
    int year;
};

class date                         /* date������       */
{
private:
    dateType *today;               /* �ṹָ��           */ 
    int validDate(int d, int m, int y);  /* ��Ա�������� */
public:
    date();                              /* ���캯������ */
    ~date();                             /* ������������ */
    int setDate(int d, int m, int y);    /* ��Ա�������� */
    void printDate();
};

/* ---------------------------------------- */
/*  ��Ա����: ���ʱ������Ƿ�Ϸ�          */
/* ---------------------------------------- */
int date::validDate(int d, int m, int y)
{
    /* ������������Ƿ��ڷ�Χ�� */
    if (d < 1 || d > 31) return 0;
    if (m < 1 || m > 12) return 0;
    if (y < 1900) return 0;           /* ���ڷ�Χ��           */
    return 1;                         /* �Ϸ���������         */
}

/* ---------------------------------------- */
/*  ���캯��: ���ó�Ա���ݳ�ʼֵ            */
/* ---------------------------------------- */
date::date()
{
    dateType *newDay = new dateType;  /* ����ṹ���ڴ� */
    newDay->day = 1;                  /* ��������              */
    newDay->month = 1;                /* �����·�              */
    newDay->year = 2001;              /* �������              */
    today = newDay;
}

/* ---------------------------------------- */
/*  ���캯��: �ͷŽṹ���ڴ�              */
/* ---------------------------------------- */
date::~date()
{
    delete today;                    /* �ͷŷ�����ڴ� */
}

int date::setDate(int d, int m, int y)
{
    if (validDate(d, m, y))    /* ���ʱ������Ƿ�Ϸ�  */
    {
       today->day = d;         /* ��������              */
       today->month = m;       /* �����·�              */
       today->year = y;        /* �������              */
       return 1;               /* ���óɹ�              */
    }
    else
    {
       return 0;               /* ����ʧ��              */
    }
}
void date::printDate()
{
    /* �����Ա���ݵ���, �պ��� */
    cout << today->month << '-' << today->day << '-' << today->year << '\n';
}

/* ---------------------------------------- */
/*  ������: ���ú����date����              */
/* ---------------------------------------- */
void main()
{
    date birthday;              /* ��������               */

    birthday.setDate(3,9,1976); /* ʹ�ó�Ա�������ó�ʼֵ */
    cout << "�������� : ";
    birthday.printDate();       /* ʹ�ó�Ա�����������   */
}



