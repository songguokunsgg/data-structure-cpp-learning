#include <iostream>
#define MAX 100

// 顶点节点
typedef struct Vnode
{
    int data;
    Enode *first;

} Vnode;

// 边链表
typedef struct Enode
{
    int adjvex;
    Enode *next;

} Enode;

typedef struct Agragh
{
    Vnode adjlist[MAX];
    // n：节点数，e：边长
    int n, e;

} graph;

// 熟悉结构为主