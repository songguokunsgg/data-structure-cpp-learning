// 利用栈转置队列

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// typedef struct Stack{
//     int *p;
//     int top;
// }Stack;

// Stack* StackInit(){

// } // 初始化一个栈，并置空

// int pop(Stack *p){} // 弹出栈顶的元素

void reverse(queue<int> &q)
{
    stack<int> tmp;
    while (!q.empty())
    {
        tmp.push(q.front());
        q.pop();
    }

    while (!tmp.empty())
    {
        q.push(tmp.top());
        tmp.pop();
    }
}

int main()
{
    queue<int> q;
    for (int i = 0; i < 100; ++i)
    {
        q.push(i);
    }

    queue<int> temp = q;

    while (!temp.empty())
    {
        cout << temp.front();
        temp.pop();
    }
    cout << endl;
    
    reverse(q);

    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    cout << endl;
}