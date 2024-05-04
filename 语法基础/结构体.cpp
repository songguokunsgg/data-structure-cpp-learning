#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 与c语言不同，c++中的结构体也可以有构造函数和成员函数
// 结构体不能继承,不能使用模板
typedef struct people
{
    string name;
    int age;

    // 最一般的构造函数写法
    // people(string name, int age)
    // {
    //     this->name = name;
    //     this->age = age;
    // }

    // 带点技巧的写法，与上面完全等价
    people(string name, int age) : name(name),age(age){};

    void out()
    {
        cout << this->name << endl;
        cout << this->age << endl;
    }
} people;

typedef struct ball
{
    float r;    // 半径
    float loc[3]; //坐标

    ball(float r, float loc[])
    {
        for (int i = 0; i < 3; ++i)
        {
            this->loc[i] = loc[i];
        }
        this->r = r;
    }

    float getV(){
        float pi = 3.14;
        float V = pi * pow(this->r,2);
        cout <<"体积: " << V <<endl;
        return V;
    }

    void out()
    {
        cout << "半径:" << r << " "
             << "坐标" << *loc << endl;
    }
}ball; 

int main()
{

    // 直接实例化，通过.访问变量和函数
    people yfs("yfs", 6);
    yfs.out();

    // 通过指针实例化
    people *wo = new people("yfs", 6);
    wo->out();

    // 实例化一个球
    float r = 3.0;
    float loc[] = {1,2,3};
    ball bl(r,loc);
    bl.out();
    bl.getV();

    // 通过指针实例化
    ball *bl2 = new ball(r,loc);
    bl2->getV();
    // 什么时候两种方式都可以，什么时候必须使用指针实例化？？？
    return 0;
}