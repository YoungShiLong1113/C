//1-100
#include<stdio.h>
int main()
{
    int j = 0;
    for (int i = 1; i < 101;i++)
    {
        j += i;
    }
        
    printf("%d", j);
}