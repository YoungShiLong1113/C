//输入两个整数，求其最大公约数和最小公倍数
#include <stdio.h>

int main()
{
    int x = 0, y = 0;
    printf("请输入两个数字：");
    scanf("%d%d", &x, &y);
    int tmp1 = x < y ? x : y; // 把两个数的最小值赋给tmp
    while (1)
    {
        if (x % tmp1 == 0 && y % tmp1 == 0)
        {
            break; // 找到最大公约数了，跳出四循环
        }
        tmp1--; // 两个数都不能整除，自减1
    }
    printf("最大公约数是：%d", tmp1);

    int tmp2 = x > y ? x : y;
    while (1)
    {
        if (tmp2 % x == 0 && tmp2 % y == 0)
        {
            break; // tmp都能整除两个数，找到最小公倍数了，跳出死循环
        }
        tmp2++; // 不能整除，自加1
    }
    printf("最小公倍数是：%d\n", tmp2);
    return 0;
}
