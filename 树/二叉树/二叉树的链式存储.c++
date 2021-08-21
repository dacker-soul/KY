#include <stdlib.h>
#include <stdio.h>

// 二叉树链式存储
struct ElemType
{
    int value;
};

typedef struct BiTNode
{
   int data;
   struct BiTNode *LChild,*RChild;
}BiTNode,*BiTree;
// 每个节点有两个指针域，n个结点，则有2n个指针域
// 度为n-1，因为根节点头上没有分支
// n个结点共有n+1个空指针（2n-(n-1)）



void main(){
    // 定义一颗空树
    BiTree root = NULL;
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = 1;
    root->LChild = NULL;
    root->RChild = NULL;

    // 插入新节点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data=2;
    p->LChild = NULL;
    p->RChild = NULL;
    root->LChild = p; //作为根节点的做孩子
}

typedef struct BiTNodeThree
{
   int data;
   struct BiTNode *LChild,*RChild;
   struct BiTNode *Parent; //指向父节点  三叉链表
   

}BiTNodeThree,*BiTreeThree;