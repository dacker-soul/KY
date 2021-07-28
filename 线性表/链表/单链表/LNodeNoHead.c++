#include <stdlib.h>

typedef struct LLNode
{
    int data;
    struct LLNode *next;
} LNode, *LinkList;

// LinkList L = (LLNode *)malloc(sizeof(LNode));

// 不带头结点的，单链表
bool InitListNoHead(LinkList &L)
{
    L = NULL; //空表，暂时还没有任何结点
    return true;
}
// 判断是否为空
bool Empty(LinkList L)
{
    return L == NULL;
}
