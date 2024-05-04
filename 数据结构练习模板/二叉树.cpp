#include <iostream>

using namespace std;

typedef struct tree{
    int key;
    struct tree *lchild;
    struct tree *rchild;

    tree(int key,struct tree *lchild,struct tree *rchild) : key(key),lchild(lchild),rchild(rchild){};

    void midprint(struct tree *t){
        if (t != NULL){
            midprint(t->lchild);
            cout << t->key << " ";
            midprint(t->rchild);
        }
    }

}tree;

int main(){

    tree *t = new tree(2,new tree(1,NULL,NULL),new tree(3,NULL,NULL));
    t->midprint(t);
    return 0;
}