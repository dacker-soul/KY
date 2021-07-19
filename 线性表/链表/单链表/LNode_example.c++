#include <stdlib.h>

//  第一种声明
struct LNode
{
    int data;
    struct LNode *next;
};
struct LNode *p = (struct LNode *)malloc(sizeof(struct LNode));
// typedef <数据类型> <别名>
typedef struct LNode LNode;
LNode *p = (LNode *)malloc(sizeof(LNode));

// 第二种简化声明
typedef struct LLNode
{
    int data;
    struct LLNode *next;
} LLNode, *LinkList;

LinkList L = (LLNode *)malloc(sizeof(LLNode));
// LinkList 其实和LLNode * 是一个东西，只是强调不同