#include <stdlib.h>
#include <stdio.h>

typedef struct LNodeL
{
    int data;
    struct LNodeL *next;
} LNodeL, *LinkList;

// 初始化一个循环单链表
bool InitLinkList(LinkList &L)
{
    L = (LNodeL *)malloc(sizeof(LNodeL));
    if (L == NULL)
    {
        return false;
    }
    L->next == L; // 头结点next指向头结点
    return true;
}

// 判断单链表是否为空
bool Empty(LinkList L)
{
    return L->next == L;
}

// 判断节点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNodeL *p)
{
    return p->next == L;
}