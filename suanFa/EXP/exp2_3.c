#include <stdio.h>
#include <stdbool.h>

#define MAXN 100

int n=5;             // 顶点个数5
int m=3;              // 最大颜色数3
int x[MAXN];        // 顶点的着色
bool c[MAXN][MAXN]; // 布尔值表示的图的邻接矩阵

bool ok(int x[], int k, bool c[][MAXN], int n)
{
    // 判断顶点着色的有效性
    for (int i = 0; i < k; i++)
    {
        if (c[k][i] && (x[k] == x[i]))
            return false;
    }
    return true;
}

bool m_coloring(int n, int m, int x[], bool c[][MAXN])
{
    // 回溯算法求解图着色问题
    for (int i = 0; i < n; i++)
        x[i] = 0;
    int k = 0;
    while (k >= 0)
    {
        x[k] = x[k] + 1;
        while ((x[k] <= m) && (!ok(x, k, c, n)))
            x[k] = x[k] + 1;
        if (x[k] <= m)
        {
            if (k == n - 1)
                break;
            else
                k = k + 1;
        }
        else
        {
            x[k] = 0;
            k = k - 1;
        }
    }
    if (k == n - 1)
        return true;
    else
        return false;
}

int main()
{

    int J[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = J[i][j];
        }
    }
    if (m_coloring(n, m, x, c))
    {
        printf("找到了一种着色方案：\n");
        for (int i = 0; i < n; i++)
            printf("%d ", x[i]);
        printf("\n");
    }
    else
    {
        printf("无解\n");
    }
    return 0;
}
