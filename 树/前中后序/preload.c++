#include <stdlib.h>
#include <stdio.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void visit(BiTree T){
    
}
// 先序遍历
void PreOrder(BiTree T){
    if (T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历
void InOrder(BiTree T){
    if (T!=NULL){
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}

// 后序遍历
void PostOrder(BiTree T){
    if (T!=NULL){
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}

// 求树的深度
// 树的深度是=MAX(左子树深度，右子树深度)+1
int treeDepth(BiTree T){
    if (t==NULL){
        return 0;
    }else{
        l = treeDepth(T->lchild);
        r =  treeDepth(T->rchild);
        return l>r? l+1:r+1;
    }

}

