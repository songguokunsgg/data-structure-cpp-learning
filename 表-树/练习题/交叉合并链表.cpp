/*
1．设a＝(a1，a2，…am)和b＝(b1,b2，…，bn)是两个循环链表写出将这两个表合并为循环链表c的算法。(15分)
    (a1，b1，a2，b2，…am，bm，bm+1，…，bn)    m≤n
c=
    (a1，b1，a2，b2，…an，bn，an+1，…，am)     m>n
*/
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

// 复杂度O(min(m,n))
list *merge(list* A,list *B){

    list  *pa = A->next,*pb = B->next, *tp;
    while ( pa != NULL && pb != NULL){
        tp = pb;
        pb = pb->next;
        tp->next = pa->next;
        pa->next = tp;
        pa = tp->next;
    }

    if (pa == NULL){
        tp->next = pb;
    }

    return A;
}

int main(){
    int array[] = {1,3,5,7,9,11};
    int array2[] = {2,4,6,8,10,12};
    int length = 6;
    int length2= 6;
    list *ls1 = initList(array,length);
    ls1->print();
    list *ls2 = initList(array2,length2);
    ls2->print();

    list* L = merge(ls1,ls2);
    L->print();


    return 0;
}