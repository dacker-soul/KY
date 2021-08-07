#include <stdlib.h>
#include <stdio.h>

#define MaxSize 10
typedef struct{
    char data[MaxSize];
    int top;
}SqStack;

// 初始化栈
void InitStack(SqStack &S)

// 判断栈是否为空
bool StackEmpty(SqStack S)

// 新元素入栈
bool PushS(SqStack &S,char x)

// 栈顶元素出栈，用X返回
bool Pop(SqStack &S，char x)

bool BrackerCheck(char str[],int length){
    SqStack s;
    InitStack(S);//初始化一个栈
    for(int i=0;i<length;i++){
        if (str[i] == '(' || str[i] == '[' ||str[i] =='{'){
            Push(S,str[i]); //扫描左括号，入栈
        }else{
            if (StackEmpty(S)) // 扫描到右括号，且当前栈空
                return false;   // 匹配失败
            char toolElem;
            Pop(S,tooElem);     // 栈顶元素出栈
            if(str[i] == ')' && topElem!='(')
                return false;
            if(str[i] == ']' && topElem!='[')
                return false;
            if(str[i] == '}' && topElem!='{')
                return false;        
        }
    }
    return StackEmpty(S) //检索完全部括号后，栈空说明匹配成功
}