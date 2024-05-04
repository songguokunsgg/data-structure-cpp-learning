#include <iostream>
#define N 10

using namespace std;

typedef struct list
{
    int array[N]; // 首指针 int array[10]
    int length;   //长度
    // int size;   // 内存占用

    list(int arr[], int len)
    {
        for (int i = 0; i < len; ++i)
        {
            this->array[i] = arr[i];
        }
        this->length = len;
    }

    void print()
    {
        for (int i = 0; i < this->length; ++i)
        {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }

    int find(int K)
    { // 0 为 哨兵
        int i;
        for (i = this->length - 1; this->array[i] != K; --i)
            ;
        return i;
    }

} list;

int main()
{
    int len = 10;
    int a[10] = {0, 16, 2, 5, 7, 3, 9, 8, 2, 18};
    list ls(a, len);
    ls.print();
    cout << ls.find(18) << endl;

    return 0;
}
