#include <iostream>
#define MAX 10
using namespace std;

typedef struct Graph
{
    int **adj;
    int nodenum;

// 分配空间
    int **__generate()
    {
        int **tmp = new int *[MAX];
        for (int i = 0; i < MAX; ++i)
        {
            tmp[i] = new int[MAX];
        }

        return tmp;
    }

    // 构造函数，创建指定图
    Graph(int **adj, int nodenum) : nodenum(nodenum)
    {
        this->adj = this->__generate();
        for (int i = 0; i < nodenum; ++i)
        {
            for (int j = 0; j < nodenum; ++j)
            {
                this->adj[i][j] = adj[i][j];
                *(*(this->adj + i) + j) = *(*(adj + i) + j);
            }
        }
        cout << "已创建图" << endl;
        this->print();
    }

    // 创建默认图，全0
    Graph()
    {
        this->adj = this->__generate();

        for (int i = 0; i < MAX; ++i)
        {
            for (int j = 0; j < MAX; ++j)
            {
                this->adj[i][j]= 0 ;
                // *(*(this->adj + i) + j) = 0;
            }
        }
        this->nodenum = MAX;
        cout << "已创建默认图" << endl;
        this->print();
    }

    // 打印邻接矩阵
    void print()
    {
        for (int i = 0; i < this->nodenum; ++i)
        {
            for (int j = 0; j < this->nodenum; ++j)
            {
                cout << this->adj[i][j] << " ";
                // cout << *(*(this->adj + i) + j) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

} graph;

int main()
{
    int size = 5;
    int **a = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        a[i] = new int(size);
    }

    int m[size][size] = {{1, 5, 4, 6, 7}, {8, 9, 2, 4, 4}, {3, 3, 2, 5, 1}, {7, 7, 6, 1, 1}, {7, 9, 3, 3, 2}};

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; j++)
        {
            a[i][j] = m[i][j];
        }
    }

    cout << sizeof(m) << " " << sizeof(a);
    graph G(a, size);
    // G.print();
}