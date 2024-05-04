#include <iostream>
#include <cstdio>
#define MAX 10

using namespace std;

// algo
int find(int a[], int len, int K)
{
    int i = len - 1;
    for (i; i >= 0; --i)
    {
        if (a[i] == K)
        {
            return i;
        }
    }
    return i;
}

int main()
{
    int a[MAX] = {1, 5, 6, 2, 3, 9, 11, 8, 5, 16};
    int len = MAX;
    int K = 2;
    cout << find(a, len, 9) << endl;
    printf("%d \n",find(a,len,9));
    return 0;
}