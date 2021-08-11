#include <std.io>
#include <stdlib.io>

#define MAXLEN 255
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;

bool SubString(SString &Sub,SString s, int pos,int len){
    // 子串范围的越界
    if(pos+len-1 > S.length)
        return false;
    for(int i=pos;i<pos+len;i++)
        Sub.ch[i-pos+1] = S.ch[i];
    Sub.length = len;
    return true;
}

int StrCompare(SString S,SString T){
    for (int i=1;i<=S.length && i<=T.length;i++){
        if (S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    // 扫描完所有字符都相同，则长度长的串更大
    return S.length-T.length;
}

int Index(SString S,SString T){
    int i=1,n=StrLength(S),m=StrLength(T);
    SString sub; //暂存子串
    while(i<=n-m+1){
        SubString(sub,S,i,m);
        if (StrCompare(sub,T)!=0)
            ++i;
        else{
            return i; 
        }
    }
    return 0; //S中不存在与T相等的子串
}