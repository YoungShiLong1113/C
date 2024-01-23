#include<stdio.h>
int main()
{
    //1+2+...+100
    int a = 0;
    for (int i = 1; i < 101;i++)
    {
        a += i;
    }
    printf("%d\n", a);
}