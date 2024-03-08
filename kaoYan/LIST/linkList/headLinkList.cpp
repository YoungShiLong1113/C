#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
    int data;//数据
    struct LNode *next;
}LNode,*linkList;

bool initList(linkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if(L==NULL)
    {
        printf("init false");
        return false;
    }
    L->next = NULL;
    printf("头节点有辣！");
    return true;
}

int main(){
    linkList L;
    initList(L);
    return 0;
}