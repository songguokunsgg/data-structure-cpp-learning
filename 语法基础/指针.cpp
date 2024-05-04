#include <iostream>

#define MAX 10

using namespace std;

int main()
{

    // 内存占用对比
    int a;
    long int b;
    long int *c;
    long int *d;

    cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << " " << sizeof(d) << endl;

    // 创建动态数组
    int *p = new int[MAX]; // 等价于 int *p = (int*)calloc(MAX,sizeof(int))
    // 对数组赋值,* 在这里是什么意思？
    for (int i = 0; i < MAX; ++i)
    {
        *(p + i) = 1 * i;
    }
    // 两种输出值的方法
    for (int i = 0; i < MAX; ++i)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < MAX; ++i)
    {
        cout << *(p + i) << " ";
    }
    cout << endl;
    delete (p);

    return 0;
}