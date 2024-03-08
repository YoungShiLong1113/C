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
    printf("insert successful\n");
}

// 删
void deleteSqList(SqList &L, int i)
{ // 删除i处的值
    for (int j = L.initLength; j > i;j--)
    {
        L.data[i] = L.data[i + 1];
    }
    L.initLength--;
    printf("delete successed\n");
}

//改
//TODO:修改值逻辑有误
void updataSqList(SqList &L,int i,int j)//将i处的值改为j
{
    L.data[i] = j;
    printf("updata success\n");
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
    insertSqList(L, 2, 3);
    displaySqList(L);
    deleteSqList(L, 1);
    displaySqList(L);

    return 0;
}