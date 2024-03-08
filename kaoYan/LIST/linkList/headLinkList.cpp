#include <stdio.h>
#include <stdlib.h>
// 带头节点
typedef struct LNode
{
    int data; // 数据
    LNode *next;
} LNode, *linkList;

bool initList(linkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("init false");
        return false;
    }
    L->next = NULL; // 带头节点的L指针初始化为空，即指向空的头节点（数据与为空，但指针域未定），此处的L指针指向头节点，不带头节点的此处为 L=NULL ,是将整个表置空
    printf("头节点有辣！");
    return true;
}

int main()
{
    linkList L;
    initList(L);
    return 0;
}