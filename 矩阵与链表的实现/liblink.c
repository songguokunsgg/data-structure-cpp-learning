// 链表库，实现链表功能

#include <stdio.h>
#include <stdlib.h>

#define MLLC (linearList *)malloc(sizeof(linearList))
#define NEXT printf("\n");

typedef struct linearList
{
    int value;
    struct linearList *next;
} linearList; // 单链表实现,不带头结点

linearList *createnode(int value)
{
    linearList *node = MLLC;
    node->value = value;
    node->next = NULL;
    return node;
}

int length(linearList *head)
{
    linearList *p = head;
    int len = 0;
    while (p != NULL)
    {
        ++len;
        p = p->next;
    }
    return len;
}

void push(linearList *head, int value)
{
    //链表添加元素，先遍历到表尾
    linearList *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    linearList *q = MLLC;
    q->next = NULL;
    q->value = value;
    p->next = q;
}

void pop(linearList *head)
{
    // go to the second final
    linearList *p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    linearList *q = p->next;
    p->next = NULL;
    free(q);
}

void PrintList(linearList *head)
{
    linearList *p = head;
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
}

void test()
{
    linearList *head = MLLC;
    head->value = 0;
    head->next = NULL;
    int i = 0;
    for (i = 1; i < 20; i++)
    {
        push(head, i);
    }
    PrintList(head);
    NEXT;
    pop(head);
    PrintList(head);
}

int main()
{
    test();
    return 0;
}
