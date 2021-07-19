前序遍历：根--左--右
中序遍历：左--根--右
后序遍历：左--右--根

题型1：已知前序遍历ABCDEFG，中序遍历为CBDEAGF，则其后序遍历为多少？
前序遍历：ABCDEFG
可知A为二叉树的根

中序遍历：CBDEAGF
可知[CBDE]A[GF]，[CBDE]为左子树，[GF]为右子树
     A
    /  \
[CBDE][GF]

先看[CBDE]
在前序遍历：ABCDEFG中，B先出现，则B为父节点
可以划分为[c]B[DE]
       B
      /  \
     C   [DE] 

再看[DE]
在前序遍历：ABCDEFG中，D先出现，则D为父节点
在中序遍历：CBDEAGF中，D在E前面，则E为右子树
        B
      /   \
     C     D
             \
              E

最后看[GF]
在前序遍历：ABCDEFG中，F先出现，则F为父节点
在中序遍历：CBDEAGF中，G在F前面，则F为左子树
        F
       /   
      G 

链接所有分支
            A
         /    \
        B      F
      /   \   /
     C     D G
             \
              E
后续遍历为：CEDBGFA              