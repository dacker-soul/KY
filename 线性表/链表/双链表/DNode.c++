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

// 删除p节点的后继节点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
    {
        return false;
    }
    DNode *q = p->next; // 找到p的后继节点q
    if (q == NULL)
    {
        return false; // p没有后继节点
    }
    p->next = q->next;
    if (q->next != NULL) // q节点不是最后一个节点
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}

// 销毁双链表
void DestoryDLinklist(DLinklist &L)
{
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L);  // 释放头结点
    L = NULL; // 头指针指向NULL
}

// 向后遍历
// while (P!=NULL)
// {
//     p= p->next;
// }
// 向前遍历
// while (P!=NULL)
// {
//     p= p->prior;
// }
// 向前遍历（跳过头结点）
// while (p->prior!=NULL)
// {
//     p= p->prior;
// }

void testDLinklist()
{
    // 初始化双链表
    DLinklist L;
    InitDLinkList(L);
}