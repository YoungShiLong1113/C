//输出4*5矩阵
#include<stdio.h>
int main()
{
    int n = 0;

    for (int i = 1; i <= 4; i++)//由于按行输出，第一层循环控制行号，第二层循环再控制列号。
    {
        for (int j = 1; j <= 5;j++,n++)//n用于计输出数字的个数，每5个换行。
        {
            if((n)%5==0)
            {
                printf("\n");
            }
            printf("%d\t", i * j);
        }
    }
}