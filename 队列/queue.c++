#include <stdlib.h>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int front, rear;
    int size;
    int tag; // 1插入 0删除
} SqQueue;

void testQueue()
{
    SqQueue Q;
}

// 初始化
bool InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}

bool DestoryQueue()
{
}

// 入队列
bool ENQueue(SqQueue &Q, int x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return false;
}

// 出队列
bool DeQueue(SqQueue &Q, int &x)
{
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 获取队头元素
bool GetHead(SqQueue Q, int &x)
{
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    return true;
}

// 队列元素个数
int GetNum(SqQueue Q)
{
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

// 以上都是 队头指针指向0，队尾指针指向 队尾的下一个空位置

// 另一种 队尾指针 指向当前队尾元素
// 入队的时候，先将队尾指针指向下一个位置，再赋值
// Q.rear = (Q.rear+1)%MaxSize;
// Q.data[Q.rear] = x;

// 初始化区别为
// front=0 rear=n-1

// 判断为空
// (Q.rear+1)%MaxSize == Q.front

// 判断为满
// 1.牺牲一个存储单元  (Q.rear+2)%MaxSize == Q.front
// 2.辅助变量