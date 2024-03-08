#include <stdio.h>

typedef struct LNode
{                       // 定义节点
    int data;           // 数据域
    LNode *next; // 指针域 结构体自身的指针
} LNode, *linkList;

bool initList(linkList &L)
{             // 初始化链表
    L = NULL; // 防止脏数据污染链表
    printf("init true\n");
    return true;
}

bool empty(linkList L)
{ // 判断是否为空
    if (L == NULL)
    {
        printf("empty true");
        return true;
    }

    else
    {
        printf("false");
        return false;
    }
}

int main()
{
    // LNode *L;   // 声明一个指针，强调这是一个节点
    linkList L; // 声明一个指针，强调这是一个链表
    // 上述两种声明方式是相同指针

    initList(L);
    empty(L);
    return 0;
}