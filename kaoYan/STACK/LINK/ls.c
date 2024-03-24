#include<stdio.h>

typedef struct snode
{
    int data;
    struct snode *next;

} lsnode, *linkstack;

void stackinit(linkstack *s)
{
    *s = NULL;
}

int STACKNOTEMPTY(linkstack s)
{
    if(s==NULL)
        return 0;
    else
        return 1;
}

void stackpush(linkstack *s,int x)
{
    lsnode *p;
    p = (lsnode *)malloc(sizeof(lsnode));
    p->data=x;
    p->next = *s;
    *s = p;
}

