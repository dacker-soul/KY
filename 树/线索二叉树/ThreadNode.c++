
#include <stdlib.h>
#include <stdio.h>
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;  //0表示指向孩子，1表示指向线索
}ThreadNode,*ThreadTree;

// 全局遍历
// 找到中序的前驱
ThreadNode *p;     //p为当前节点
ThreadNode *pre;   //当前访问节点的前驱
ThreadNode *final; //用户记录最终结果

void visit(ThreadNode *q){
    if (q==p){
        final = q;
    }else{
        pre = q;
    }
}