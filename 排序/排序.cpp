#include <iostream>
#define MAX 100

using namespace std;

typedef struct list
{
    int R[MAX];
    int length;

    list(int R[], int length)
    {
        for (int i = 0; i < length; ++i)
        {
            this->R[i] = R[i];
        }
        this->length = length;
    }

    void swap(int i, int j)
    {
        int tmp = this->R[i];
        this->R[i] = this->R[j];
        this->R[j] = tmp;
    } // 交换两个位置的元素

    void print()
    {
        for (int i = 0; i < length; ++i)
        {
            cout << this->R[i] << " ";
        }
        cout << endl;
    }

    // 两两比较，如果有逆序，就交换
    int BubbleSort()
    {
        int i = 0, j, count = 0;
        bool flag = 1;
        for (i; i < this->length && flag; ++i)
        {
            flag = 0;
            for (j = i + 1; j < this->length; ++j)
            {
                if (this->R[i] > this->R[j])
                {
                    this->swap(i, j);
                    ++count;
                    flag = 1;
                }
            }
        }
        return count;
    }

    // 选择排序，每次选择一个最小的值，与第i个索引交换
    int SelectSort()
    {
        int i = 0, count = 0;
        for (i; i < this->length; i++)
        {
            int minindex = i;
            // 从剩余的元素中找最小的索引，也可以单独写成一个函数
            for (int j = i; j < this->length; ++j)
            {
                if (this->R[j] < this->R[minindex])
                {
                    minindex = j;
                }
            }
            if (minindex != i)
            {
                this->swap(i, minindex);
                ++count;
            }
        }
        return count;
    }

    void InsertSort()
    {
        int i, j;
        //依次将R[1]~R[n]插入到前面已排序序列，R[0]为默认排好序的序列
        for (i = 1; i < this->length; i++)
        {
            //若R[i]关键码小于其前驱，将A[i]插入有序表
            // 如果不小，则说明已经排好了
            int tmp = this->R[i];
            j = i - 1;
            while ((j >= 0) && (this->R[j] > tmp))
            {
                this->R[j + 1] = this->R[j];
                --j;
            }
            this->R[j + 1] = tmp;
        }
    }

    void binaryInsertSort()
    {
        int i, j;
        for (i = 1; i < this->length; ++i)
        {
            int tmp = this->R[i];
            // 折半查找所要插入的位置
            int low = 0, high = i - 1, mid;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (this->R[mid] <= tmp)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            // high 就是我们所要查找的位置
            for (int j = i - 1; j > high; j--)
            {
                this->R[j + 1] = this->R[j];
            }

            this->R[high + 1] = tmp;
        }
    }

    void ShellSort(int gap)
    {
        int h = 1;
        while (h < this->length / gap)
        {
            h = gap * h + 1;
        }
        while (h >= 1)
        {
            for (int i = h; i < this->length; i++)
            {
                for (int j = i; j >= h && this->R[j] < this->R[j - h]; j -= h)
                {
                    this->swap(j, j - h);
                }
            }
            h = h / gap;
        }
    }

    // 划分函数
    int paritition(int low, int high)
    {
        int pivot = this->R[low];
        while (low < high)
        {
            while (low < high && this->R[high] >= pivot)
            {
                --high;
            }
            this->R[low] = this->R[high];
            while (low < high && this->R[low] <= pivot)
            {
                ++low;
            }
            this->R[high] = this->R[low];
        }
        this->R[low] = pivot;
        return low;
    }

    void QuickSort_rec(int low, int high)
    {
        if (low < high)
        {
            int pivot = this->paritition(low, high);
            QuickSort_rec(low, pivot - 1);
            QuickSort_rec(pivot + 1, high);
        }
    }

    // 归并排序核心代码
    void merge_sort_recursive(int reg[], int start, int end)
    {
        if (start >= end)
            return;
        int len = end - start, mid = (len >> 1) + start;
        int start1 = start, end1 = mid;
        int start2 = mid + 1, end2 = end;
        merge_sort_recursive( reg, start1, end1);
        merge_sort_recursive( reg, start2, end2);
        int k = start;
        while (start1 <= end1 && start2 <= end2)
            reg[k++] = this->R[start1] < this->R[start2] ? this->R[start1++] : this->R[start2++];
        while (start1 <= end1)
            reg[k++] = this->R[start1++];
        while (start2 <= end2)
            reg[k++] = this->R[start2++];
        for (k = start; k <= end; k++)
            this->R[k] = reg[k];
    }

    void merge_sort()
    {
        int reg[this->length];
        merge_sort_recursive(reg, 0, this->length - 1);
    }

} list;

int main()
{
    // 初始化顺序表
    int a[] = {5, 4, 7, 1, 9, 10, 6, 3};
    int length = 8;
    list l(a, length);
    l.print();

    // cout << l.BubbleSort() << endl;
    // l.print();

    // cout << l.SelectSort() << endl;
    // l.print();

    l.merge_sort();
    l.print();
    return 0;
}