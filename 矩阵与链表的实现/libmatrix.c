/*
实现的功能：
1. 打印矩阵信息
2. 创建0矩阵和1矩阵
3. 矩阵乘以常数，结合1可以创建任意数矩阵
4. 复制矩阵
5. 矩阵转置
6. 矩阵加法
7. 矩阵减法
8. 矩阵乘法
9. 矩阵切片**(难)
10. 矩阵取逆*****(难，搁置)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liblist.h"

// 矩阵结构，封装了行数和列数
typedef struct Matrix
{
    float **array;
    int row;
    int col;
} Matrix;

// 分配矩阵所需空间，但不初始化和赋值
float **_GenerateMatrix(int row, int col)
{
    // 这部分为分配行空间，占用row个float型指针
    float **tmp = (float **)calloc(row, sizeof(float *));
    int i, j;
    for (i = 0; i < row; ++i)
    {
        // 分配列空间，占用row*col个float空间，也是矩阵实际存储所需空间
        tmp[i] = (float *)calloc(col, sizeof(float));
    }
    // 返回指向这个空间的指针
    return tmp;
}

// 打印矩阵行列数和矩阵本身
void Print_Mat(Matrix *mat)
{
    int i, j;
    printf("行数:%d \n", mat->row);
    printf("列数:%d \n", mat->col);
    for (i = 0; i < mat->row; ++i)
    {
        for (j = 0; j < mat->col; ++j)
        {
            printf("%.2f ", *(*(mat->array + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

// 创建1矩阵
Matrix *ones_mat(int row, int col)
{
    float **ze = _GenerateMatrix(row, col);
    int i, j;
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
            *(*(ze + i) + j) = 1;

    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->array = ze;
    mat->row = row;
    mat->col = col;
    return mat;
}

// 创建0矩阵
Matrix *zeros_mat(int row, int col)
{
    float **ze = _GenerateMatrix(row, col);
    int i, j;
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
            *(*(ze + i) + j) = 0;

    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->array = ze;
    mat->row = row;
    mat->col = col;
    return mat;
}

// 矩阵乘以常数
Matrix *times_mat(Matrix *mat, int k)
{
    int i, j;
    for (i = 0; i < mat->row; ++i)
        for (j = 0; j < mat->col; ++j)
            *(*(mat->array + i) + j) *= k;

    return mat;
}

Matrix *copy_mat(Matrix *mat)
{
    // 给新矩阵分配空间
    Matrix *tmp = (Matrix *)malloc(sizeof(Matrix));
    tmp->array = _GenerateMatrix(mat->row, mat->col);
    // 对应元素赋值
    int i, j;
    for (i = 0; i < mat->row; ++i)
        for (j = 0; j < mat->col; ++j)
            *(*(tmp->array + i) + j) = *(*(mat->array + i) + j);
    tmp->row = mat->row;
    tmp->col = mat->col;
    // 返回新矩阵
    return tmp;
}

// 矩阵转置,返回一个新矩阵,原理跟复制矩阵类似
Matrix *transpose_mat(Matrix *mat)
{
    // 给新矩阵分配空间
    Matrix *tmp = (Matrix *)malloc(sizeof(Matrix));
    tmp->array = _GenerateMatrix(mat->col, mat->row);
    // 对应元素赋值
    int i, j;
    for (i = 0; i < mat->col; ++i)
        for (j = 0; j < mat->row; ++j)
            *(*(tmp->array + i) + j) = *(*(mat->array + j) + i);
    tmp->row = mat->col;
    tmp->col = mat->row;
    // 返回新矩阵
    return tmp;
}

// 矩阵减法,返回新矩阵,注意为A-B
Matrix *subtract_mat(Matrix *A, Matrix *B)
{
    //　检查是否满足相加条件，即A,B行列数相等
    if (A->row == B->row && A->col == B->col)
    {
        Matrix *res = (Matrix *)malloc(sizeof(Matrix));
        res->array = _GenerateMatrix(A->col, A->row);
        res->row = A->row;
        res->col = B->col;

        int i, j;
        // 对应元素之和
        for (i = 0; i < A->row; ++i)
            for (j = 0; j < A->col; ++j)
                *(*(res->array + i) + j) =
                    (*(*(A->array + i) + j)) - (*(*(A->array + i) + j));
        return res;
    }
    else
    {
        printf("矩阵行列不想等，无法计算");
        return NULL;
    }
}
// 矩阵加法,返回新矩阵
Matrix *add_mat(Matrix *A, Matrix *B)
{
    //　检查是否满足相加条件，即A,B行列数相等
    if (A->row == B->row && A->col == B->col)
    {
        Matrix *res = (Matrix *)malloc(sizeof(Matrix));
        res->array = _GenerateMatrix(A->col, A->row);
        res->row = A->row;
        res->col = B->col;

        int i, j;
        // 对应元素之和
        for (i = 0; i < A->row; ++i)
            for (j = 0; j < A->col; ++j)
                *(*(res->array + i) + j) =
                    (*(*(A->array + i) + j)) + (*(*(A->array + i) + j));
        return res;
    }
    else
    {
        printf("矩阵行列不想等，无法计算");
        return NULL;
    }
}

// 矩阵乘法
Matrix *multi_mat(Matrix *A, Matrix *B)
{
    // A的列数等于B的行数才可以乘法
    if (A->col != B->row)
    {
        printf("不满足乘法条件");
        return NULL;
    }
    else
    {
        Matrix *res = (Matrix *)malloc(sizeof(Matrix));
        // 最后结果是row(A)*col(B)的矩阵
        res = zeros_mat(A->row, B->col);

        int i, j, k, tmp;
        for (i = 0; i < res->row; ++i)
        {
            for (j = 0; j < res->col; ++j)
            {
                for (k = 0; k < A->col; ++k)
                {
                    // 数组形式为res[i,j] = A[i,k]*B[k,j]
                    *(*(res->array + i) + j) += *(*(A->array + i) + k) * (*(*(B->array + k) + j));
                }
            }
        }
        return res;
    }
}

// 矩阵切片
// rows为包含所需行的数组
// cols为包含所需列的数组
// 此处需要顺序表结构，会更方便，所以先不实现，应先实现顺序表
Matrix *sub_mat(Matrix *mat, int *rows, int *cols)
{
    return mat;
}

//////// 以下为测试代码
void _test()
{
    Matrix *me = ones_mat(4, 7);
    Matrix *you = ones_mat(7, 3);
    int i, j;
    for (i = 0; i < me->row; ++i)
        for (j = 0; j < me->col; ++j)
            *(*(me->array + i) + j) = i * j * i;
    Print_Mat(multi_mat(me, you));
    Print_Mat(multi_mat(me, you));
}

int main()
{
    _test();
    return 0;
}
