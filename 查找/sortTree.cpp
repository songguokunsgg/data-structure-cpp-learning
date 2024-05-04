#include <iostream>

using namespace std;

typedef struct tree
{
    int key;
    struct tree *lchild;
    struct tree *rchild;

    tree(int key, struct tree *lchild, struct tree *rchild) : key(key), lchild(lchild), rchild(rchild){};

    // 非递归查找值
    bool find(int K)
    {
        struct tree *p = this;
        while (p != NULL)
        {
            if (p->key == K)
            {
                cout << "存在" << endl;
                return true;
            }
            else if (K < p->key)
            {
                p = p->lchild;
            }
            else
            {
                p = p->rchild;
            }
        }
        cout << "不存在" << endl;
        return false;
    }

    // 递归查找值
    bool find_rec(struct tree *t, int K)
    {
        if (t == NULL)
        {
            cout << "不存在" << endl;
            return true;
        }
        else if (t->key == K)
        {
            cout << "存在" << endl;
            return false;
        }
        else if (K < t->key)
        {
            return this->find_rec(t->lchild, K);
        }
        else
        {
            return this->find_rec(t->rchild, K);
        }
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
} tree;

tree *insert_rec(tree *t, int K)
{
    if (t == NULL)
    {
        t = new tree(K, NULL, NULL);
    }
    else
    {
        if (K < t->key)
            t->lchild = insert_rec(t->lchild, K);
        else if (K > t->key)
            t->rchild = insert_rec(t->rchild, K);
    }
    return t;
}
tree *createTree(int array[], int length)
{
    tree *t = NULL;
    for (int i = 0; i < length; ++i)
    {
        t = insert_rec(t, array[i]);
    }
    return t;
}

int main()
{
    // tree *t = new tree(5, new tree(3, new tree(2, NULL, NULL), new tree(4, NULL, NULL)), new tree(9, new tree(7, NULL, NULL), new tree(11, NULL, NULL)));
    // t->printtree(t);
    // cout << endl;

    // t->find(7);
    // t->find_rec(t, 7);
    // t->insert(1);
    // t->printtree(t);
    // cout << endl;

    int array[] = {11, 56, 43, 89, 76, 22, 34, 77, 99};
    int length = 9;
    tree *tr = createTree(array, length);
    tr->printtree(tr);

    return 0;
}