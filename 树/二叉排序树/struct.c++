#include<stdio.h>
#include<stdlib.h>
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTNode *BST_Search(BSTree T,int key){
    while(T!=NULL&&key!=T->key){
        if(key<T->key) T=T->lchild;
        else T=T->rchild;
    }
    return T;
}

BSTNode *BSTSearch(BSTree T,int key){
    if(T==NULL){
       return NULL;
    }
    if (key ==T->key)
        return T;
    else if(key <T->key)
        return BSTSearch(T->lchild,key);
    else
        return BSTSearch(T->rchild,key);
}//空间复杂度o(h)

int BST_insert(BSTree &T,int key){
    if (T==NULL){
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = key;
        T->lchild = T->rchild = NULL;
        return 1;
    }else if(key==T->key)
        return 0;
    else if(key<T->key)
        return BST_insert(T->lchild,key);
    else
        return BST_insert(T->rchild,key);
}
// 非递归插入

// 构造二叉排序树
void Creat_BST(BSTree &T,int str[],int n){
    T=NULL;
    int i=0;
    while(i<n){
        BST_insert(T,str[i]);
        i++;
    }
}

// 删除操作
// 如果删除的是叶子结点，无所谓直接删除
// 如果删除的结点，只有左子树或者右子树，直接用后继结点覆盖
// 如果删除的结点，有左子树和右子树，可以用左子树的最大结点替换
// 或者右子树的中序遍历的第一个结点替换，然后删除中序遍历的第一个结点


// 查找效率
// 查找长度，在一个查找过程中，需要对比关键字的次数称为查找长度
// 平均查找长度ASL（Average Search Length）
// 一共8个结点
// 第一层1个对比一次，第二层2个，每个对比两次，第三层4个，每个对比三次，第四层1个，每个对比四次
// 查找成功ASL = (1*1+2*2+3*4+4*1)/8=2.625

// 查找失败 51p