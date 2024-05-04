#include <iostream>
#include <string>

using namespace std;

// 避免重复写多个功能类似的函数和类
template <class T>
void Swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template <class T>
class link
{
public:
    T key;
    link *next;

    link(T key, link *next)
    {
        this->key = key;
        this->next = next;
    }

    //打印节点
    void printnode()
    {
        link* p = this;
        while (p != NULL)
        {
            cout << p->key << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    int a = 6, b = 10;
    cout << a << " " << b << endl;
    
    Swap(a,b); //  Swap<int>(a, b); 写不写<int>都可以
    cout << a << " " << b << endl;

    string j = "heheda",k="dadahe";
    Swap(j,k);// Swap<string>(j,k);
    cout << j << " " << k << endl;

    // p和q有什么区别
    link<int> *p = new link<int>(5, new link<int>(6, NULL));
    link<int> q(5, new link<int>(6, NULL));

    link<string> *r = new link<string>("yfs", new link<string>("bwj", new link<string>("zyn", NULL)));
    r->printnode();

    return 0;
}