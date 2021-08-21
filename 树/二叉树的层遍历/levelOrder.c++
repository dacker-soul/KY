#include <stdlib.h>
#include <stdio.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct LinkNode
{
    BiTNode * data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;


void visit(BiTree T){
    
}
// 层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q); //初始化链队列
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            EnQueue(Q,p->rchild);
        }
    }
}