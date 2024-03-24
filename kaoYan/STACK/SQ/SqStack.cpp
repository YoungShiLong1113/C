#include <stdio.h>
#define MaxSize 50

typedef struct
{
    int data[MaxSize]; // 静态数组存放元素
    int top;           // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;//也可以为0
}

// 判断栈空
bool StackEmpty(SqStack S)
{
    if (S.top = -1)
        return true;
    else
        return false;
}

// 进栈
bool push(SqStack &S, int data)
{
    if (S.top == MaxSize - 1)
        return false; // 栈满
    else
    {
        S.top = S.top + 1;    // 指针上移
        S.data[S.top] = data; // 数据插入上移之后的位置
        // S.data[++S.top]=data;
        return true;
    }
}

// 出栈
bool pop(SqStack &S, int &data)
{
    if (S.top == -1)
        return false;
    else
    {
        data = S.data[S.top];
        S.top = S.top - 1;
        // data = S.data[S.top--];
        return true;
    }
}

//读栈顶元素
bool getTop(SqStack S,int &data)//data需要返回，使用引用
{   
    if(S.top==-1)
        return false;//空栈报错
    else
    {
        data = S.data[S.top];
        return true;
    }
}

//销毁
bool stackDestroy(SqStack &S)
{
    S.top = -1;
}

int main()
{
    SqStack S;
    InitStack(S);

    return 0;
}