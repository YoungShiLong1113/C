#include<stdio.h>
#include<stdlib.h>
#define initSzie 100
//动态分配内存的顺序表

typedef struct {
    int *data;
    int MaxSzie;
    int Length;
}SqList;

void initSqList(SqList &L)
{
    L.data = (int *)malloc(sizeof(int) * initSzie);
    for (int i = 0; i < L.Length;i++)
    {
        L.data[i] = 0;
    }
    printf("init s\n");
}

int main()
{
    SqList L;
    initSqList(L);
    return 0;
}