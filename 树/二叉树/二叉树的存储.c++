#include <stdlib.h>
#include <stdio.h>
#define MaxSize 100
struct TreeNode
{
    int value;    
    bool isEmpty; //结点是否为空
};

TreeNode t[MaxSize];

void Init(TreeNode *t){
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;
    }
}
// t[0]空着
// i的左孩子    2i
// i的右孩子    2i+1
// i的父节点    [i/2] 向下取整
// i所在的层次  [log2(n)]+1 向下取整+1

// 若完全二叉树中共有n个结点
// i是否有左孩子        2i<=n
// i是否有右孩子        2i+1<=n
// i是否是叶子/分支结点  i>[n/2] 大于为叶子结点


// 如果不是完全二叉树，不存在的结点也要空着空间


