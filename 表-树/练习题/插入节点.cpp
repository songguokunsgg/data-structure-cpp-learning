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

    // 比较复杂
    node* getjiao(node *p){
        // 初始化头节点
        node *tmp = new node(-1,NULL);
        //新链表辅助指针
        node *tp = tmp;

        // 遍历辅助指针
        node *t = this->next;
        p = p->next;

        while (p != NULL){
            while (t != NULL){
                if (p->key == t->key){
                    tp->next = new node(t->key,NULL);
                    tp = tp->next;
                }
                t = t->next;
            }
            t = this->next;
            p = p->next;
        }
        return tmp;
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
    node *s1 = new node(-1, NULL);
    node *s2 = new node(-1, NULL);
    for (int i = 0; i < 10; i++)
    {
        s1->insertnode(i*5);
        s2->insertnode(i*10);
    }
    s1->printnode();
    s2->printnode();

    node *s3 = s1->getjiao(s2);
    s3->printnode();

    return 0;
}