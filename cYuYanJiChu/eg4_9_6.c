#include<stdio.h>
int main()
{
    int x = 0;
    printf("putin a num\n");
    scanf("%d", &x);

    int y;
    if(x<1)
    {
        y = x;
    }
    if(x>=1&&x<10)
    {
        y = 2 * x - 1;
    }
    if(x>=10)
    {
        y = 3 * x - 11;
    }
    printf("y=%d", y);

    return 0;
}