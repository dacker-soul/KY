#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct node
{
    DataType data;
    struct node *next;
} ListNode;

typedef ListNode *LinkList;
ListNode *p;
LinkList head;

LinkList CreateList(void) //头插法
{
    char ch; 

    ListNode *s;
    head = NULL;
    ch = getchar();
    while (ch != '\n')
    {
        s = (ListNode *)malloc(sizeof(ListNode));
        s->data = ch;
        s->next = head;
        head = s;

        ch = getchar();
    }
    return head;
}

// LinkList CreatListW(void) //尾插法建立链表
// {
//     char ch;
//     LinkList head;
//     ListNode *s, *r;
//     head = NULL;
//     r = NULL;
//     while ((ch = getchar()) != '\n')
//     {
//         s = (ListNode *)malloc(sizeof(ListNode));
//         s->data = ch;

//         if (head = NULL)
//             head = s;
//         else
//             r->next = s;

//         r = s; //将新的节点给r
//     }
//     if (r != NULL)
//         r->next = NULL;
//     return head;
// }

// LinkList CreatListW1(void) //改进的尾插法
// {
//     char ch;
//     LinkList head = (LinkList)malloc(sizeof(ListNode));
//     ListNode *s, *r;
//     r = head;

//     while ((ch = getchar()) != '\n')
//     {
//         s = (ListNode *)malloc(sizeof(ListNode));
//         s->data = ch;
//         printf("%c  ", s->data);
//         s->next = s;
//         printf("%d\n", s->next);
//         r = s;
//     }
//     r->next = NULL;

//     return head;
// }

int main()
{
    CreateList(); //函数调用
    //CreatListW();
    // CreatListW1();

    return 0;
}