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