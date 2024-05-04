#include <iostream>
using namespace std;

class node
{
public:
    int key;
    node *next;

    // 创建一个节点，构造函数
    node(int key, node *next)
    {
        this->key = key;
        this->next = next;
    }

    // 析构函数
    ~node(){};

    // 插入节点
    void insertnode(int key)
    {
        node *q = new node(key, NULL);
        //遍历到末尾
        node *tmp = this;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = q;
    }

    bool isaver()
    {
        // 去除头节点
        node *p = this->next;

        if (p->next == NULL)
            return true;

        int val = p->key - p->next->key;
        p = p->next;
        while (p->next != NULL)
        {
            if (p->key - p->next->key != val)
            {
                return false;
            }
            p = p->next;
        }
        return true;
    }

    //打印节点
    void printnode()
    {
        node *p = this;
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
    // 头节点
    node *head = new node(-1, NULL);
    for (int i = 0;i < 100;++i){
    head->insertnode(6*i);
    }
    head->printnode();

cout << head->isaver() <<endl;
    return 0;
}