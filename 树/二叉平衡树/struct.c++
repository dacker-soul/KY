typedef struct AVLNode{
    int key; //数据域
    int balance; //平衡因子
    struct AVLNode *lchild,*rchild;
}AVLNode,*AVLTree;