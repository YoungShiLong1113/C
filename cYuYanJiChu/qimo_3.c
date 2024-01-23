//5-100内能被5或7整除的数
#include<stdio.h>

int main()
{
    for (int i = 5; i < 101;i++)
    {
        if(i%5==0||i%7==0)
        {
            printf("%d\n", i);
        }
    }
}