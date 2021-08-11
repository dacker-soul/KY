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

// 朴素模式匹配算法
int IndexSpecial(SString S,SString T){
    int k=1;
    int i=k,j=1;
    while(i<=S.length && j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }else{
            k++;
            i=k;
            j=1;
        }
    }
    if (j>T.length)
        return k;
    else
        return 0;
}

// kmp算法
int IndexSpecialKMP(SString S,SString T){
    int i=1,j=1;
    int next[T.length+1];
    get_next(T,next);
    while(i<=S.length && j<=T.length){
        if(j==0||S.ch[i]==T.ch[j]){
            ++i;
            ++j; // 继续比较后续字符
        }else{
            j = next[j]; // 模式串向右移动
        }
    }
    if (j>T.length)
        return i-T.length // 匹配成功
    else{
        return 0;
    }    
}

// kmp 求模式串T的next数组
void get_next(SString T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            ++i;++j;
            // 若pi=pj，则next[j+1]=next[j]+1
            next[i]=j;
        }else{
            // 否则领j=next[j],循环继续
            j=next[j];
        }
    }
}