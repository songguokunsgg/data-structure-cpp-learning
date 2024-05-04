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
        for (int i = 0; i < this->length; ++i)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
        cout << "length:" << this->length << endl;
        cout << endl;
    }

    // 非递归折半查找
    int binary(int k)
    {
        int low = 0, high = this->length - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (this->arr[mid] == k)
            {
                cout << mid << endl;
                return mid;
            }
            else if (this->arr[mid] < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << "没有" << endl;
        return -1;
    }

    // 递归折半查找
    int binary_recursion(int k, int low, int high)
    {
        if (low > high)
        {
            cout << "没有" << endl;
            return -1;
        }
        int mid = (low + high) / 2;

        if (this->arr[mid] == k)
        {
            cout << mid <<endl;
            return mid;
        }
        else if (this->arr[mid] < k)
        {
            return this->binary_recursion(k, mid + 1, high);
        }
        else
        {
            return this->binary_recursion(k, low, mid - 1);
        }
    }

} array;

// 在函数中，以结构体作为参数的算法应该怎么写，请仿照实现
int find(array arr, int k)
{
    return 0;
}

int main()
{
    int arr[12] = {1, 2, 4, 7, 8, 9, 11, 17, 19, 20, 56, 111};
    array ls(arr, 12);
    ls.out();
    // ls.binary(1);
    ls.binary_recursion(56,0,11);
    return 0;
}