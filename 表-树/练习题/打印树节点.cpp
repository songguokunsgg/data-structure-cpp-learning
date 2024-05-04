// 打印树节点
#include <iostream>
using namespace std;

class tree
{
public:
    char key;
    tree *lchild;
    tree *rchild;

    tree(char key, tree *lchild, tree *rchild)
    {
        this->key = key;
        this->lchild = lchild;
        this->rchild = rchild;
    }
    ~tree() {}

    // 只打印数字
    void excnum(tree *node)
    {
        if (node != NULL)
        {
            node->excnum(node->lchild);
            if (node->key <= '9' && node->key >= '0')
                cout << node->key << " ";
            node->excnum(node->rchild);
        }
    }
};

int main()
{
    tree *t = new tree('3',
                       new tree('c', new tree('f', NULL, NULL), NULL), new tree('9', NULL, NULL));

    t->excnum(t);
    cout << endl;

    return 0;
}