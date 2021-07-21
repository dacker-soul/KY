#include <stdio.h>
#define MaxSzie 10

// 静态分配
typedef struct
{
    int data[MaxSzie];
    int length;
} SeqList;

// 第num个位置插入value
bool InsertList(SeqList &L, int num, int value)
{
    if (num < 1 || num > L.length + 1) // num的范围
    {
        return false;
    }
    if (L.length >= MaxSzie)
    {
        return false; // 存满
    }
    for (int j = L.length; j >= num; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[num - 1] = value;
    L.length++;
    return true;
}
// 删除
bool ListDelete(SeqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

// 按位查找，获取表中第i个位置的元素
int GetElem(SeqList L, int i)
{
    return L.data[i - 1];
}

// 按值查找,返回所在第几位置
int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

void InitList(SeqList &L)
{
    L.length = 0;
}
int main()
{
    SeqList L;
    InitList(L);
    // for (int i = 0; i < L.length; i++) 正常应该是使用这个
    for (int i = 0; i < MaxSzie; i++)
    {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
    return 0;
}