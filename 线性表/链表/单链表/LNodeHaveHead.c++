#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList L = (LNode *)malloc(sizeof(LNode));

// 单链表初始化(带头结点)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}
// 判断单链表是否为空(带头结点)
bool Empty(LinkList L)
{
    return L->next == NULL;
}

// 在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p;  //指针p指向当前扫描到的节点
    int j = 0; // 当前p指向第几个节点
    p = L;     // L指向头结点，头结点是第0个节点（不存数据）
    // L -->头-->a1-->a2-->a3-->a4-->NULL
    //      |
    //      p
    //
    // 第一个位置插入e
    //  L -->头-->e-->a1-->a2-->e-->a3-->a4-->NULL
    // 第三个位置插入e
    //  L -->头-->a1-->a2-->e-->a3-->a4-->NULL

    while (p != NULL && j < i - 1) // 循环找到第i-1个节点
    {
        p = p->next;
        j++;
    } //找到i-1个节点，在它的后面插入一个新节点

    return InsertNextNode(p, e);
}

// 在第i个位置插入元素e（不带头结点）
bool ListInsertNoHead(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        return false;
    }
    if (i == 1)
    { // 插入第1个节点的操作与其他操作不同
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s; // 头指针指向新节点
        return true;
    }

    LNode *p;                      //指针p指向当前扫描到的节点
    int j = 1;                     // 当前p指向第1个节点
    p = L;                         // L指向头结点，头结点是第0个节点（不存数据）
    while (p != NULL && j < i - 1) // 循环找到第i-1个节点
    {
        p = p->next;
        j++;
    } //找到i-1个节点，在它的后面插入一个新节点

    return InsertNextNode(p, e);
}

// 后插操作：在p节点之后插入元素e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;                          // i不合法
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 生成一个节点
    s->data = e;
    s->next = p->next;
    p->next = s; //将节点s链接到p之后
    return true;
}

// 前插操作：在p节点之前插入元素e
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

// 按位序删除（带头结点）
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;                      //指针p指向当前扫描到的节点
    int j = 0;                     // 当前p指向第几个节点
    p = L;                         // L指向头结点，头结点是第0个节点（不存数据）
    while (p != NULL && j < i - 1) // 循环找到第i-1个节点
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    if (p->next == NULL) // 第i-1个结点之后已经无其他结点
    {
        return false;
    }
    LNode *q = p->next; // 令q指向被删除结点
    e = p->data;        // 用e返回被删除元素的值
    p->next = q->next;  //将*q结点从链中断开
    free(q);            // 释放结点的存储空间
    return true;        // 删除成功
}

// 删除指定节点p
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next; // 令q指向p的后继结点
    p->data = q->data;
    // p->data = p->next->data 后继结点数据覆盖p结点数据
    p->next = q->next; // q结点断开
    free(q);
    return true;
}

// 按位查找，返回第i个元素（带头结点）
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找，找到数据域==e的结点
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 求表的长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
}