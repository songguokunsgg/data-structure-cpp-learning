/*
将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间, 不另外占用其它的存储空间。表中不允许有重复的数据。
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
    list *pa = A, *pb = B,*tp;
    while (pa->next != NULL && pb->next != NULL){
        if (pa->next->val <= pb->next->val){
            pa = pa->next;
        }else{
            tp = pb;
            pb = pb->next;
            pb->next = tp->next;
            pa->next = tp;
            pa->next = tp->next;
        }
    }

    return A;

}

int main(){
    int array[] = {1,2,3,4,5,7,9,11};
    int array2[] = {0,2,4,6,8,10,12,13,14,15};
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