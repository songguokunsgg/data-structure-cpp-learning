#include <iostream>
#include <vector>

using namespace std;

class tree
{
public:
    int key;
    tree *lchild;
    tree *rchild;

    tree(int key, tree *lchild, tree *rchild);
    ~tree(){
        cout << "树已经销毁" << endl;
    };
};

tree::tree(int key, tree *lchild, tree *rchild)
{
    this->key = key;
    this->lchild = lchild;
    this->rchild = rchild;
}

void printtree(tree *t)
{
    if (t != NULL)
    {
        printtree(t->lchild);
        cout << t->key << " ";
        printtree(t->rchild);
    }
}

int main()
{
    tree *t = new tree(5, new tree(6, NULL, NULL), NULL);
    printtree(t);
    delete(t);
    return 0;
}