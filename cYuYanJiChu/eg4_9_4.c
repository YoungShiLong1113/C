#include<stdio.h>

int main()
{
    int a, b, c;
    printf("putin three num\n");
    scanf("%d %d %d", &a, &b, &c);

    int max = 0;
    if(a>b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    if(max>c)
    {
        printf("max = %d ", max);
    }
    else
    {
        printf("max = %d ", c);
    }
}