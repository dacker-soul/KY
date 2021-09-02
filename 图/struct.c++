#define MaxVertexNum 100
typedef struct {
    char Vex[MaxVertexNum]; //顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵边表
    int vexnum,arcnum;  // 图的当前顶点数和边数（弧数）
}MGraph;

// 邻接矩阵法存储带权图
#define MaxVertexNum 100        //顶点数目最大值
#define INFINITY 最大值的int值
typedef char VertextType;
typedef int EdgeType;
typedef struct {
    VertextType Vex[MaxVertexNum]; //顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; //边的权
    int vexnum,arcnum;  // 图的当前顶点数和边数（弧数）
}MGraph;