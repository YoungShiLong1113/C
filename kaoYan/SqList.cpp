#include <stdio.h>
#define MaxSize 50

typedef struct
{
    int data[MaxSize];
    int initLength;
}SqList;

// 初始化
void InitSqList(SqList &L)
{

    for (int i = 1; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.initLength = 0;
}

// 增
void insertSqList(SqList &L, int i, int j)
{ // 在i处增加j
    for (int k=L.initLength; k >=i;k--)
    {
        L.data[k+1] = L.data[k];
    }
    L.data[i] = j;
    L.initLength++;
    printf("insert successful");
}

// 删
void deleteSqList(SqList &L, int i)
{ // 删除i处的值
    for (int j = L.initLength; j > i;j--)
    {
        L.data[i] = L.data[i + 1];
    }
    L.initLength--;
}

//改
void updataSqList(SqList &L,int i,int j)//将i处的值改为j
{
    if(i>MaxSize||i<0)
    {
        printf("error");
    }
    else{
        L.data[i] = j;
    }
   
}

//查
void searchSqList(SqList L,int i){
    //查找第i-1个值
    printf("%d\n", L.data[i]);
}

//销


//打印
void displaySqList(SqList L)
{
    for (int i = 0; i < L.initLength;i++)
    {
        printf("%d\n", L.data[i]);
    }
}

int main()
{
    SqList L;

    InitSqList(L);
    insertSqList(L, 1, 2);
    displaySqList(L);

    return 0;
}