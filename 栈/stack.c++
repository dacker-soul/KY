#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top; //指向数组下标
} SqStack;

// 初始化
void InitStack(SqStack &s)
{
    s.top = -1;
}

// 进栈
bool Push(SqStack &s, int x)
{
    if (s.top == MaxSize - 1)
        return false;
    s.top++;
    s.data[s.top] = x;
    return true;
}

// 出栈
bool Pop(SqStack &s, int &x)
{
    if (s.top == -1)
        return false;
    x = s.data[s.top];
    s.top--;
    return true;
}

void testStack()
{
    SqStack s;
}
