/* ======================================== */
/*    程序实例: 12_3.cpp                    */
/*    字符串类实作                          */
/* ======================================== */
#include <cstring>
#include <iostream>
using namespace std;

class String                         /* String类声明 */
{
private:
    char str[81];                    /* 成员资料声明   */
public:
    String(char *ch);                /* 构造函数       */
    int length();                    /* 成员函数       */
    void display() { cout << str << '\n'; }
    int pos(String s);
    int pos(char *s);
    String getSubStr(int index, int count);
};

/* ---------------------------------------- */
/*  构造函数: 建立字符串                      */
/* ---------------------------------------- */
String::String(char *s)
{
    if ( strlen(s) > 80 )
       s[80] = 0;                     /* 字符串是否太长   */
    strcpy(str, s);                   /* 复制字符串       */
}

/* ---------------------------------------- */
/*  成员函数: 计算字符串长度                  */
/* ---------------------------------------- */
int String::length()
{
    return strlen(str);               /* 传回字符串长度   */
}

/* ---------------------------------------- */
/*  成员函数: 找寻指定的子字符串              */
/* ---------------------------------------- */
int String::pos(String s)
{
    int found = 0;                    /* 旗标变数       */
    int i = 0;
    
    /* 是否是空字符串, 是否子字符串比字符串长度为长 */
    if ( (str == "") || (s.length() > length()) )
       return -1;
    /* 查找子字符串的主回路 */
    while ( (!found) && ( i < length() ) )
    {
       /* 比较子字符串 */
       if ( strncmp( &str[i], s.str, s.length()) == 0)
          found = 1;                   /* 找到           */
       else ++i;                       /* 下一个字符     */
    }
    if ( found )                       /* 返回找到的位置 */
       return i+1;
    return -1;
}

/* ---------------------------------------- */
/*  成员函数: 查找指定的子字符串              */
/* ---------------------------------------- */
int String::pos(char *s)
{
    String s1(s);                       /* 建立子串对象   */

    return pos(s1);                     /* 呼叫pos()函数  */
}

/* ---------------------------------------- */
/*  成员函数: 取出子字符串                    */
/* ---------------------------------------- */
String String::getSubStr(int index, int count)
{
   String str1("");                     /* 创建临时保存的字符串 */
   int temp;

   /* 参数是否在范围内 */
   if ( (index <= strlen(str)) && (index > 0) && (count > 0) )
   {
      temp = length() - index + 1;      /* 计算子字符串的长度 */
      if ( count > temp )               /* 是否超过字符串结尾 */
         count = temp;                 
      /* 复制子字符串 */
      strncpy(str1.str, &str[index-1], count);
      str1.str[count] = 0;
   }
   return str1;                          /* 返回子字符串       */
}

/* ---------------------------------------- */
/*  主程序: 测试字符串类的成员函数.         */
/* ---------------------------------------- */
void main()
{
    String s1("数据结构是一门重要的课程");/* 创建字符串对象    */
    String s2("This is a book.");
    String s3("is");
    
    cout << "原始中文字符串: ";             /* 输出原始字符串    */
    s1.display();
    cout << "原始英文字符串: ";             /* 输出原始字符串    */
    s2.display();
    /* 显示字符串的长度 */
    cout << "中文字符串共: " << s1.length() << "字符\n";
    cout << "英文字符串共: " << s2.length() << "字符\n";
    /* 找寻子字符串的位置 */
    cout << "'一门' 子字符串在中文字符串的位置 " << s1.pos("一门") << "\n";
    cout << "'is' 子字符串在英文字符串的位置 " << s2.pos(s3) << "\n";
    cout << "取出中文字符串15开始共6字符: ";  /* 输出取出的子字符串 */
    /* 取出子字符串 */ 
    s3 = s1.getSubStr(15, 6);
    s3.display();
}
