#include <stdlib.h>
#include <stdio.h>

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

// 初始化双链表
bool InitDLinkList(DLinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL; //头结点的prior永远指向NULL
    L->next = NULL;  //头结点之后暂时还没有节点
    return true;
}

// 判断双链表是否为空（带头结点）
bool Empty(DLinklist L)
{
    return L->next == NULL;
}

// 在p节点之后插入s节点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

void testDLinklist()
{
    // 初始化双链表
    DLinklist L;
    InitDLinkList(L);
}