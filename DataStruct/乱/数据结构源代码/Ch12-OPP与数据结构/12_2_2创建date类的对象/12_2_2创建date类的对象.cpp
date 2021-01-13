/* ======================================== */
/*    程序实例: 12_2_2.cpp                  */
/*    创建date类的对象                    */
/* ======================================== */
#include <iostream>
using namespace std;

class date                         /* date类声明       */
{
private:
    int day;                       /* 成员数据声明       */
    int month;
    int year;
    int validDate(int d, int m, int y);  /* 成员函数声明 */
public:
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
    if (y < 1900) return 0;  /* 不在范围内           */
    return 1;                /* 合法日期数据         */
}

/* ---------------------------------------- */
/*  成员函数: 设置时间的成员数据            */
/* ---------------------------------------- */
int date::setDate(int d, int m, int y)
{
    if (validDate(d, m, y))   /* 检查时间参数是否合法  */
    {
       day = d;               /* 设置日期              */
       month = m;             /* 设置月份              */
       year = y;              /* 设置年份              */
       return 1;              /* 设置成功              */
    }
    else
    {
       return 0;              /* 设置失败              */
    }
}

/* ---------------------------------------- */
/*  成员函数: 输出成员数据                  */
/* ---------------------------------------- */
void date::printDate()
{
    /* 输出成员数据的月, 日和年 */
    cout << month << '-' << day << '-' << year << '\n';
}

/* ---------------------------------------- */
/*  主程式: 设置和输出date对象              */
/* ---------------------------------------- */
void main()
{
    date birthday;              /* 声明对象               */

    birthday.setDate(3,9,1976); /* 使用成员函数设置初始值 */
    cout << "生日日期 : ";
    birthday.printDate();       /* 使用成员函数输出日期   */
}

