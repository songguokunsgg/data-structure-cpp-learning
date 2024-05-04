#include <iostream>
#define MAX 50

using namespace std;

class stack
{
public:
    int st[MAX];
    int top;

    stack()
    {
        for (int i = 0; i < MAX; i++)
        {
            st[i] = 0;
        }
        top = -1;
    }

    ~stack()
    {
        cout << "stack 已经销毁" << endl;
    }

    void print();
    int front(); // 取出一个值
    void pop();  // 弹出一个值
    void push(int key);
    bool isempty();
    void setnull();
};

void stack::print()
{
    for (int i = 0; i <= top; ++i)
    {
        cout << st[i] << "->";
    }
    cout << endl;
    cout << "top=" << top << endl;
}

int stack::front()
{
    if (top < 0)
    {
        cout << "栈空" << endl;
        return -1;
    }
    else
    {
        cout << st[top] << endl;
        return st[top];
    }
}

void stack::pop()
{
    if (top < 0)
    {
        cout << "栈空" << endl;
    }
    else
    {
        --top;
    }
}

void stack::push(int key)
{
    st[++top] = key;
}

bool stack::isempty()
{
    if (top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack::setnull()
{
    top = -1;
}

// 采用循环队列
class queue
{
public:
    int qu[MAX];
    int front;
    int rear;

    queue()
    {
        for (int i = 0; i < MAX; ++i)
        {
            qu[i] = 0;
        }
        front = 0;
        rear = 0;
    };
    ~queue(){
        cout << "队列已销毁" <<endl;
    }

    void pop();
    void push(int key);
    void print();
};

int main()
{
    stack st;
    for (int i = 0; i < 10; ++i)
        st.push(6 * i);
    st.print();
    st.pop();
    st.print();
    st.setnull();
    st.print();
    return 0;
}