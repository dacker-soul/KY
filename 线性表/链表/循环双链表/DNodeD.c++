#include <stdlib.h>
#include <stdio.h>

typedef struct DNodeD
{
    int data;
    struct DNodeD *prior, *next;
} DNodeD, *DLinklist;

// 初始化
bool InitDLinkList(DLinklist &L)
{
    L = (DNodeD *)malloc(sizeof(DNodeD));
    if (L == NULL)
    {
        return false;
    }
    L->prior = L;
    L->next = L;
    return true;
}

// 判断循环双链表是否为空
bool Empty(DLinklist L)
{
    return L->next == L;
}

// 判断节点p是否为表尾结点
bool isTail(DLinklist L, DNodeD *p)
{
    return p->next == L;
}

// 在p节点之后插入s节点
bool InsertNextDNodeD(DNodeD *p, DNodeD *s)
{
    s->next = p->next;
    p->next = s;
    p->next->prior = s;
    s->prior = p;
}
// 删除p节点的后继节点
bool DeleteNextDNodeD(DNodeD *p)
{
    DNodeD *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}