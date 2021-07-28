#include <stdlib.h>
#include <stdio.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

// 初始化队列（带头结点）
void InitQueue(LinkQueue &Q)
{
    // 初始front,rear都指向头结点
    // 申请一个头结点，头指针和为指针都指向其

    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

// 判断为空（带头结点）
bool IsEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
    // return Q.front->next == NULL
}

// 初始化队列（不带头结点）
void InitQueueNoHead(LinkQueue &Q)
{
    // 初始front,rear都指向NULL
    Q.front->next = NULL;
    Q.front->next = NULL;
}
// 判断为空（带头结点）
bool IsEmptyNoHead(LinkQueue Q)
{
    return Q.front->next == NULL;
    // return Q.rear->next == NULL;
}

// 入队（带头结点）
void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; //新节点插入到rear之后
    Q.rear = s;       // 修改表尾指针
}

// 入队（不带头结点）
void EnQueueNoHead(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if (Q.front == NULL)
    {
        // 空队列插入第一个元素
        Q.front = Q.rear = s;
    }
    else
    {
        Q.rear->next = s;
        Q.rear = s;
    }
}

// 出队列（带头结点）
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == Q.rear)
        return false; //空队列
    LinkNode *p = Q.front->next;
    x = p->data;             // 返回队头元素
    Q.front->next = p->next; //修改头结点的next指针
    if (Q.rear == p)
    {                      // 此次是最后一个结点出队列
        Q.rear == Q.front; //修改rear指针
    }
    free(p);
    return true;
}

// 出队列（不带头结点）
bool DeQueueNoHead(LinkQueue &Q, int &x)
{
    if (Q.front == NULL)
    {
        return false;
    }
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;
    if (Q.rear == p)
    {
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}
