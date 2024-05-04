#include <iostream>

using namespace std;

typedef struct list{
    int val;
    struct list *next;

    list(int value, struct list *next) : val(value),next(next){};

    void print(){
        for (struct list *p = this;p != NULL;p=p->next){
            cout << p->val << "->";
        }
        cout << "NULL" << endl;
    }

}list;

list *initList(int array[],int length){
    list *res = new list(-1,NULL);
    list *p = res;
    int i = 0;
    while (i < length){
        p->next = new list(array[i],NULL);
        p = p->next;
        ++i;
    }
    return res;
}

int main(){
    int array[] = {3,2,7,6,5,4,9,8};
    int length = 8;
    list *ls = initList(array,length);
    ls->print();
    (&(*ls))->print();
    return 0;
}