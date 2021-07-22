#define MaxSize 10

struct Node
{
    int data;
    int next;
};
typedef struct Node SLinkList[MaxSize];

// 等价于下面

typedef struct Node
{
    int data;
    int next;
} SLinkList[MaxSize]; // 不推荐这个写法

void testSLinkList()
{
    // 第一种声明
    struct Node a[MaxSize];
    // 第二种声明
    SLinkList a;
}

// 初始化
bool InitNode(struct Node a[MaxSize])
{
    a[0].next = -1;
}