#include <iostream>

#define MAX 50

using namespace std;

class stack
{
public:
    int *st;
    int top;

    stack()
    {
        this->st = new int(MAX);
        top = -1;
    }

    // 加入元素
    void push(int key)
    {
        this->st[++this->top] = key;
    }

    // 取出元素
    void pop()
    {
        if (top >= 0)
        {
            this->top--;
        }
        else
        {
            cout << "已经是栈底" << endl;
        }
    }

    // 判空
    bool isempty(){
        if (this->top == -1){
            return true;
        }else{
            return false;
        }
    }

    void makeinit(){
        this->top = -1;
    }

    // 打印栈
    void printstack()
    {
        for (int i = 0; i <= this->top; ++i)
        {
            cout << this->st[i] << "->";
        }
        cout << this->top << endl;
    }
};

class queue
{
public:
    queue(){};
};

int main()
{
    stack *p = new stack();
    p->push(10);
    p->push(11);
    p->push(12);
    p->push(13);
    p->printstack();

    // for (int i = 4; i > 0; --i)
    //     p->pop();
    p->printstack();

    cout << p->isempty() <<endl;

    p->makeinit();
    p->printstack();
    return 0;
}