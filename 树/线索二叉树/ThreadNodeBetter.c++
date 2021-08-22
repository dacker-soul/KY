
#include <stdlib.h>
#include <stdio.h>
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;  //0表示指向孩子，1表示指向线索
}ThreadNode,*ThreadTree;

// 线索化
// 找到中序的前驱
ThreadNode *p;     //p为当前节点
ThreadNode *pre;   //当前访问节点的前驱
ThreadNode *final; //用户记录最终结果

// 中序遍历二叉树，一边遍历，一遍线索化
void InThread(ThreadTree T){
    if(T!=NULL){
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void visit(ThreadNode *q){
    if (q->lchild==NULL){//左子树为空，建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;
        pre->rtag=1;
    }
    pre=q;
}

// 中序线索化二叉树T
void CreateInThread(ThreadTree T){
    pre =NULL;      //pre初始为NULL
    if(T!=NULL){    //非空二叉树才能线索化
        InThread(T);//中序线索化二叉树
        if(pre->rchild==NULL){
            pre->rtag=1;
        }
    }
}

// ------------------------------------------------
// 先序遍历二叉树一边遍历，一遍线索化
void PreThread(ThreadTree T){
    if(T!=NULL){
        visit(T);
        if(T->ltag==0){
            PreThread(T->lchild);//lchild不是前驱线索
        }
        PreThread(T->rchild);
    }
}

// 后序遍历二叉树一边遍历，一遍线索化
void PostThread(ThreadTree T){
    if(T!=NULL){
        visit(T);
        if(T->ltag==0){
            PostThread(T->lchild);//lchild不是前驱线索
        }
        PostThread(T->rchild);
    }
}
//-------------------------------------------------------
// 中序线索二叉树，找中序后继结点
// 1.p->rtag ==1 ,next=p->rchild
// 2.p->rtag ==0 

// 找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *FirstNode(ThreadNode *P){
    // 循环找到最左下结点（不一定是叶子结点）
    while(p->ltag==0) p=p->lchild;
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *P){
    // 右子树中最左下结点
    if(p->rtag==0) return FirstNode(p->rchild);
    else return p->rchild; //rtag ==1 直接返回后继线索
}

// 对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void InOrder(ThreadNode *T){
    for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p)){
        visit(p);
    }
}

// 中序线索二叉树找中序前驱
// 找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *LastNode(ThreadNode *P){
    // 循环找到最右下结点（不一定是叶子结点）
    while(p->rtag==0) p=p->rchild;
    return p;
}
// 在中序线索二叉树中找到结点p的前驱结点
ThreadNode *PreNode(ThreadNode *P){
    // 左子树中最右下结点
    if(p->ltag==0) return LastNode(p->lchild);
    else return p->lchild; // ltag==1直接返回前驱线索
}

// 对中序线索二叉树进行逆向中序遍历
void RevInOrder(ThreadNode *T){
    for(ThreadNode *P=LastNode(T);p!=NULL;p=PreNode(T)){
        visit(p);
    }
}

// 先序线索二叉树找先序后继
// 若p有左孩子，则先序后继为左孩子
// 若p无左孩子，则先序后继为右孩子

// 在先序线索二叉树中找到结点p的后继结点
ThreadNode *NextNodeInOrder(ThreadNode *P){
    if(p->rtag==0){
        // 如果左孩子存在，返回，不存在返回右孩子
        if(p->lchild!=NULL) return p->lchild;
        else return p->rchild; 
     }else{
         return p->rchild;
     }
}

// 在先序线索二叉树中找到结点p的先序前驱结点

// 如果是三叉链表，则可以
// 1.如果能找到p的父节点，且p是左孩子，p的父节点即为前驱结点
// 2.如果能找到p的父节点，且p是右孩子，左孩子为空，p的父节点即为前驱结点
// 3.如果能找到p的父节点，且p是右孩子，左孩子不为空，p的前驱为左兄弟子树中，最后一个被访问的结点
// 4.p是根节点，就没有前驱
ThreadNode *PreNodeInOrder(ThreadNode *P){
    if(p->rtag==0){
        // 这里找不到（因为只有两个指向孩子结点的指针）
     }else{
         return p->lchild;
     }
}

// 在后序线索二叉树中找到结点p的后序前驱结点
// 1.p->ltag==1,pre=p->lchild
// 2.p->ltag==0,

// 若p有右孩子，则后序前驱为右孩子
// 若p没有右孩子，则后序前驱为左孩子

// 在后序线索二叉树中找到结点p的后序后继结点
// 1.p->rtag==1,pre=p->rchild
// 2.p->rtag==0,
// 左右子树只可能是前驱，所以找不到，只能遍历

// 三叉链表，可找到父节点
// 1.如果能找到p的父节点，且p是右孩子，父节点为后继
// 后续遍历 左 右 根
//         左（左 右 根）根
// 2.如果能找到p的父节点，且p是左孩子，右兄弟结点为空，父节点为后继
// 后续遍历 左 根
//        （左 右 根）根
// 3.如果能找到p的父节点，且p是左孩子，右兄弟结点非空，右兄弟子树中第一个被后续遍历的结点
// 4.p是根节点，就没有前驱

// 总结
//          中序线索二叉树  先序线索二叉树  后序线索二叉树
// 找前驱    可            不可          可 
// 找后继    可            可            不可
// 除非用三叉链表或者，从根开始遍历