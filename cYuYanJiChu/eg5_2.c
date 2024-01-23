//do while 1-100
#include<stdio.h>
int main()
{
    int i = 1;
    int j = 0;
    do
    {
        j += i;
        i++;
    }
    while (i < 101);
    printf("%d", j);
}