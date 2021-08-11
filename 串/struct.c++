#define MAXLEN 255

typedef struct{
    char ch[MAXLEN];// 静态数组实现
    int length;
}SString;


Hstring S;
S.ch = (char *)malloc(MAXLEN*sizeof(char));
S.length = 0;
free(S) // 需要手动释放

typedef struct{
    char *ch;
    int length;
}HString; // 动态数组实现（堆分配存储）


// 链表
typedef struct StringNode{
    char ch; // 每个节点存储一个字符  1个字节
    struct StringNode *next; // 辅助指针需要4个字节，32个比特，一个字节（B）有8个bit
}StringNode,*String;  //存储密度低

// 提高存储密度
typedef struct StringNode{
    char ch[4]; // 每个节点存储多个字节
    struct StringNode *next; 
}StringNode,*String; 