// 顺序查找
#include <iostream>
#define MAX 100

using namespace std;

typedef struct array
{
    int arr[MAX];
    int length;

    array(int arr[], int length)
    {
        // 下标从1开始赋值，因为0处需要作为哨兵适用
        for (int i = 0; i < length; ++i)
        {
            this->arr[i] = arr[i];
        }
        this->length = length;
    }
    void out()
    {
        for (int i = 1; i < this->length; ++i)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
        cout << this->length << endl;
        cout << endl;
    }

    int find(int k)
    {
        this->arr[0] = k;
        int i;
        for (i = this->length; this->arr[i] != k; --i);
        cout << i << endl;
        return i;
    }

} array;

typedef struct link{
    int key;
    struct link* next;

    link(int key,struct link* next){
        this->key = key;
        this->next = next;
    }

    void find(int K){
        int t[100] = {}; // int t[100];
        struct link* p = this->next;
        int num = 1,index = 0;

        while (p!=NULL){
            if (p->key == K){
                t[index++] = num; 
            }
            num++;
            p = p->next;
        }
        for (int i = 0;t[i] != 0;++i){
            cout << t[i] << " " ;
        }
        cout << endl;
    }

    void out(){
        struct link* p = this;
        while (p!=NULL){
            cout << p->key <<"->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
} link;

// 在函数中，以结构体作为参数的算法应该怎么写，请仿照实现
int find(array arr, int k)
{
    return 0;
}

int main()
{
    // int arr[8] = {-1, 8, 2, 4, 7, 1, 9, 11};
    // array ls(arr, 8);
    // ls.out();
    // ls.find(222);
    link* head = new link(-1,new link(4,new link(7,new link(8,new link(7,new link(7,new link(2,NULL)))))));
    head->out();
    head->find(7);
    return 0;
}