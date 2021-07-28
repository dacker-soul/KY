#include <stdlib.h>
// 无头结点链栈
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LNode, *LStack;

// 初始化
bool InitLStack(LStack &s)
{
    s = NULL;
    return true;
}

// 进栈
bool PushStack(LStack &s, int x)
{
    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    tmp->data = x;
    tmp->next = s->next;
    s->next = tmp;
    return true;
}

// 出栈
bool PopStack(LStack &s, int &x)
{
    if (s == NULL)
    {
        return false;
    }
    LNode *tmp = (LNode *)malloc(sizeof(LNode));
    tmp = s;
    x = s->data;
    s = s->next;
    free(tmp);
    return true;
}

// 获取栈顶元素
bool GetStackTop(LStack &s, int &x)
{
    if (s == NULL)
    {
        return false;
    }
    x = s->data;
    return true;
}

// 判断空，满

bool Empty(LStack s)
{
    return s == NULL;
}
