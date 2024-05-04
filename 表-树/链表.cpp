#include <iostream>
using namespace std;

// typedef struct node
// {
//     int key;
//     struct node *next;   /* data */
// }node;

// node* initnode(int key){
//     node* p = calloc(sizeof(int));
//     return p;
// }

typedef struct node
{
public:
    int key;
    struct node *next;

    // 创建一个节点，构造函数
    node(int key, struct node *next)
    {
        this->key = key;
        this->next = next;
    }

    // 插入节点
    void insertnode(int key)
    {
        struct node *q = new struct node(key, NULL);
        //遍历到末尾
        struct node *tmp = this;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = q;
    }

    // 在头节点插入元素(头插法)
    void inserthead(int key)
    {
        struct node *tmp = new struct node(key, NULL);
        tmp->next = this->next;
        this->next = tmp;
    }

    // 删除第loc位置上的节点
    void deletenode(int loc)
    {
        struct node *tmp = this;
        while (--loc)
        {
            tmp = tmp->next;
        }
        struct node *tmp2 = tmp->next;
        tmp->next = tmp2->next;
        delete (tmp2);
    }

    // 查找值为K的节点位置
    int findelem(int K)
    {
        struct node *tmp = this;
        int loc = 0;
        while (tmp != NULL)
        {
            if (tmp->key == K)
            {
                return loc;
            }
            else
            {
                tmp = tmp->next;
                ++loc;
            }
        }
        return -1;
    }

    // 删除所有值为K的元素
    void deleteK(int K)
    {
        struct node *p = this;
        while (p->next != NULL)
        {
            if (p->next->key == K)
            {
                node *tmp = p->next;
                p->next = p->next->next;
                delete (tmp);
            }
            else
            {
                p = p->next;
            }
        }
    }

    //打印节点
    void printnode()
    {
        struct node *p = this;
        while (p != NULL)
        {
            cout << p->key << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
} node;

int main()
{
    // // 头节点
    // node *head = new node(-1, NULL);
    // head->insertnode(10);
    // head->insertnode(15);
    // head->insertnode(56);
    // head->printnode();

    // cout << head->findelem(111) << endl;
    // head->deletenode(2);

    // head->printnode();
    node head(-1, NULL);
    head.inserthead(4);
    head.insertnode(91);
    head.insertnode(91);
    head.inserthead(8);
    // cout << head.findelem(55) << endl;
    head.printnode();
    // head.deletenode(2);
    // head.deleteK(91);
    // head.printnode();

    return 0;
}