#include <stdio.h>

//不带头节点
typedef struct node
{
    int data;
    struct node *next;
}*linkStack;

//初始化
bool initLinkStack(linkStack &S)
{
    S->next = NULL;
}

//进栈
bool push(linkStack &S,int data)
{
    if(S->next==NULL)
        ;
}