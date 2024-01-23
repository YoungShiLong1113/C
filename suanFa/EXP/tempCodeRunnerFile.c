#include <stdio.h>
#include <stdlib.h>

#define N 4

int count = 0; // 用于计数解法的数量

// 检查在第k行第i列放置皇后是否满足条件
int place(int x[], int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return 0; // 不满足条件，返回0
        }
    }
    return 1; // 满足条件，返回1
}

// 使用回溯法解决N皇后问题
void n_queens(int n, int x[])
{
    int k = 1;
    x[k] = 0;
    while (k > 0)
    {
        x[k] = x[k] + 1;                        // 在当前列加1的位置开始搜索
        while (x[k] <= n && !place(x, k, x[k])) // 当前列位置是否满足条件
            x[k] = x[k] + 1;                    // 不满足条件，继续搜索下一列位置
        if (x[k] <= n)
        { // 存在满足条件的列
            if (k == n)
            {
                count++;
                printf("解法 %d:\n", count);
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        if (x[i] == j)
                        {
                            printf("Q "); // 打印皇后的位置
                        }
                        else
                        {
                            printf(". "); // 打印空白位置
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
            {
                k++; // 处理下一个行皇后
                x[k] = 0;
            }
        }
        else
        {        // 已判断完n列，均没有满足条件
            k--; // 回溯到前一行
        }
    }
}
int main()
{
    int x[N + 1];                        // 存储皇后的位置
    n_queens(N, x);                      // 解决N皇后问题
    printf("总共有 %d 种解法\n", count); // 打印解法的总数量
    return 0;
}