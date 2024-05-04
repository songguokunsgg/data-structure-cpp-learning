// liblist.c的头文件
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct list{
    float* skp;
    int length;
}list;

// 创建一个长度为n，值为value的顺序表
list* get_list(int len , int value);

// 获取顺序表长度
int length_list(list* lt);

// 复制顺序表
list* copy_list(list* lt);

// 打印顺序表
void Print_List(list* lt);

// 找最大值，返回最大值和对应的下标的数组
// 遇相同值返回第一个
float* findmax_list(list* lt);
// 找最小值，返回最小值和对应的下标的数组
// 遇相同值返回第一个
float* findmin_list(list* lt);
