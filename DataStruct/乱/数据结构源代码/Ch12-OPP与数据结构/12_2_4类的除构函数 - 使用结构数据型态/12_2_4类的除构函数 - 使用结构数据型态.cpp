/* ======================================== */
/*   程序实例: 12_2_4.cpp                  */
/*    类的除构函数 - 使用结构数据型态     */
/* ======================================== */
#include <iostream>
using namespace std;

struct dateType                    /* 日期结构声明       */
{
    int day;                       /* 结构数据           */  
    int month;
    int year;
};

class date                         /* date类声明       */
{
private:
    dateType *today;               /* 结构指标           */ 
    int validDate(int d, int m, int y);  /* 成员函数声明 */
public:
    date();                              /* 构造函数声明 */
    ~date();                             /* 除构函数声明 */
    int setDate(int d, int m, int y);    /* 成员函数声明 */
    void printDate();
};

/* ---------------------------------------- */
/*  成员函数: 检查时间参数是否合法          */
/* ---------------------------------------- */
int date::validDate(int d, int m, int y)
{
    /* 检查日期数据是否在范围内 */
    if (d < 1 || d > 31) return 0;
    if (m < 1 || m > 12) return 0;
    if (y < 1900) return 0;           /* 不在范围内           */
    return 1;                         /* 合法日期数据         */
}

/* ---------------------------------------- */
/*  构造函数: 设置成员数据初始值            */
/* ---------------------------------------- */
date::date()
{
    dateType *newDay = new dateType;  /* 分配结构的内存 */
    newDay->day = 1;                  /* 设置日期              */
    newDay->month = 1;                /* 设置月份              */
    newDay->year = 2001;              /* 设置年份              */
    today = newDay;
}

/* ---------------------------------------- */
/*  构造函数: 释放结构的内存              */
/* ---------------------------------------- */
date::~date()
{
    delete today;                    /* 释放分配的内存 */
}

int date::setDate(int d, int m, int y)
{
    if (validDate(d, m, y))    /* 检查时间参数是否合法  */
    {
       today->day = d;         /* 设置日期              */
       today->month = m;       /* 设置月份              */
       today->year = y;        /* 设置年份              */
       return 1;               /* 设置成功              */
    }
    else
    {
       return 0;               /* 设置失败              */
    }
}
void date::printDate()
{
    /* 输出成员数据的月, 日和年 */
    cout << today->month << '-' << today->day << '-' << today->year << '\n';
}

/* ---------------------------------------- */
/*  主程序: 设置和输出date对象              */
/* ---------------------------------------- */
void main()
{
    date birthday;              /* 声明对象               */

    birthday.setDate(3,9,1976); /* 使用成员函数设置初始值 */
    cout << "生日日期 : ";
    birthday.printDate();       /* 使用成员函数输出日期   */
}



