// 双亲表示法
#define Max_TREE_SIZE 100

typedef struct 
{
    int data;   //数据元素
    int parent; //双亲位置域
}PTNode;
typedef struct 
{
   PTNode nodes[Max_TREE_SIZE]; //双亲表示
   int n;   // 节点数
}PTree;

// 孩子表示法（顺序+链式存储）
struct CTNode
{
    int child; //孩子结点在数组中的位置
    struct CTNode *next; //下一个孩子
};
typedef struct parent
{
    int data;
    struct CTNode *firstChild; //第一个孩子
}CTBox;

typedef struct 
{
    CTBox nodes[Max_TREE_SIZE];
    int n,r; //结点树和根的位置
}CTree;

// 孩子兄弟表示法
typedef struct CSNode
{
    int data;
    struct CSNode *firstChild,*nextsibling; //第一个孩子和右兄弟指针
}CSNode,*CSTree;

