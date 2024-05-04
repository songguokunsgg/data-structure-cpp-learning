#include <iostream>
#include <string>

using namespace std;

class people
{
public:
    int age;
    string name;

    // 构造函数
    people(int age, string name) : age(age),name(name){};
    
    // 析构函数
    ~people(){
        cout << "这个变量已经没了" << endl;
    }
};

// 类中想要包含自己(结构体同样适用)
class marry
{
public:
    marry *other;
    string name;

    marry(string name, marry *other)
    {
        this->name = name;
        this->other = other;
    }
};

int main()
{
    // 直接实例化
    marry me("yfs",new marry("yyj",&me));
    cout << me.other->name << endl;

    marry* wo = new marry("yfs",new marry("yyj",wo));
    cout << wo->other->name << endl;

    // 下面这样是不行的，会导致循环指向
    cout << wo->other->other->name << endl;
    return 0;
}