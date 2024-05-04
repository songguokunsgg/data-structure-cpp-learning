/*
实现功能：
1. 获取长度
2. 某个位置添加元素
3. 某个位置去除元素
4. 找最大最小值
5. 打印顺序表
6. 复制顺序表
6. 创建全为某个值的顺序表
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "liblist.h"

// 创建一个长度为n的顺序表，分配空间，但不赋值
list *_GenerateList(int n)
{
    list *tmp = (list *)malloc(sizeof(list));
    tmp->skp = (float *)calloc(n, sizeof(float));
    tmp->length = n;
    return tmp;
}

// 创建一个长度为n，值为value的顺序表
list *get_list(int len, int value)
{
    list *tmp = _GenerateList(len);
    int i;
    for (i = 0; i < len; ++i)
        *(tmp->skp + i) = value;
    return tmp;
}

// 获取顺序表长度
int length_list(list *lt)
{
    return lt->length;
}

// 复制顺序表
list *copy_list(list *lt)
{
    list *tmp = _GenerateList(lt->length);
    int i;
    for (i = 0; i < lt->length; ++i)
        *(tmp->skp + i) = *(lt->skp + i);
    return tmp;
}

void Print_List(list *lt)
{
    int i;
    printf("顺序表长为:%d\n", lt->length);
    for (i = 0; i < lt->length; ++i)
        printf("%.2f ", *(lt->skp + i));
    printf("\n");
}

// 找最大值，返回最大值和对应的下标的数组
// 遇相同值返回第一个
float *findmax_list(list *lt)
{
    // 分配两个float空间，存放参数
    float *res = (float *)calloc(2, sizeof(float));

    // 初始化为表中第一个值
    *res = *(lt->skp);
    *(res + 1) = 0;
    int i;
    for (i = 1; i < lt->length; ++i)
    {
        if (*(lt->skp + i) > *res)
        {
            *res = *(lt->skp + i);
            *(res + 1) = i;
        }
    }
    return res;
}

// 找最小值，返回最小值和对应的下标的数组
// 遇相同值返回第一个
float *findmin_list(list *lt)
{
    // 分配两个float空间，存放参数
    float *res = (float *)calloc(2, sizeof(float));

    // 初始化为表中第一个值
    *res = *(lt->skp);
    *(res + 1) = 0;
    int i;
    for (i = 1; i < lt->length; ++i)
    {
        if (*(lt->skp + i) < *res)
        {
            *res = *(lt->skp + i);
            *(res + 1) = i;
        }
    }
    return res;
}
///////下面是测试代码
void _test()
{
    list *ts = get_list(9, 4);
    int i;
    for (i = 0; i < ts->length; ++i)
    {
        *(ts->skp + i) = (int)(rand() / 100000);
    }

    float *k = findmin_list(ts);

    printf("%.2f ", *k);
    printf("%.2f \n", *(k + 1));
    Print_List(ts);
    Print_List(copy_list(ts));
}

int main()
{
    _test();
    return 0;
}
