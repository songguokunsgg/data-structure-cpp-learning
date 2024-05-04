// 求叶子节点数目
#include <iostream>
using namespace std;

class tree
{
public:
    int key;
    tree *lchild;
    tree *rchild;

    tree(int key, tree *lchild, tree *rchild)
    {
        this->key = key;
        this->lchild = lchild;
        this->rchild = rchild;
    }
    ~tree(){}

    int getnode(tree *node)
    {
        int count = 0;

        if (node == NULL)
        {
            return 0;
        }
        else if (node->lchild == NULL && node->rchild == NULL)
        {
            return 1;
        }
        else
        {
            count = this->getnode(this->lchild) + this->getnode(this->rchild);
        }
        return count;
    }

    // 中序遍历
    void printree(tree *node)
    {
        if (node != NULL)
        {
            node->printree(node->lchild);
            cout << node->key << " ";
            node->printree(node->rchild);
        }
    }
};

int main()
{
    tree *t = new tree(3,
                       new tree(5, new tree(7, NULL, NULL), NULL), new tree(4, NULL, NULL));

    t->printree(t);
    cout << endl;

    cout << t->getnode(t) << endl;
    return 0;
}