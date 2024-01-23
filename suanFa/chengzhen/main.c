#include <stdio.h>
#include <limits.h>

#define MAX_TOWNS 3

// 定义城镇之间的道路费用矩阵
int roadCost[MAX_TOWNS][MAX_TOWNS];

// 定义城镇数量和最小花费
int numTowns, minCost;

// 定义已访问城镇的标志数组
int visited[MAX_TOWNS];

// 递归函数，计算最小花费
void calculateMinCost(int currentTown, int totalCost) {
    // 如果所有城镇都已访问，则更新最小花费
    if (currentTown == numTowns) {
        if (totalCost < minCost)
            minCost = totalCost;
        return;
    }

    // 遍历所有城镇
    for (int i = 0; i < numTowns; i++) {
        // 如果当前城镇未访问，则继续递归
        if (!visited[i]) {
            // 标记当前城镇为已访问
            visited[i] = 1;

            // 计算当前城镇到下一个城镇的道路费用，并递归计算下一个城镇
            calculateMinCost(currentTown + 1, totalCost + roadCost[currentTown][i]);

            // 恢复当前城镇的未访问状态，以便尝试其他路径
            visited[i] = 0;
        }
    }
}

int main() {
    // 输入城镇数量
    printf("请输入城镇数量：");
    scanf("%d", &numTowns);

    // 输入城镇之间的道路费用
    printf("请输入城镇之间的道路费用矩阵：\n");
    for (int i = 0; i < numTowns; i++) {
        for (int j = 0; j < numTowns; j++) {
            scanf("%d", &roadCost[i][j]);
        }
    }

    // 初始化最小花费为最大整数
    minCost = INT_MAX;

    // 初始化已访问城镇的标志数组
    for (int i = 0; i < numTowns; i++) {
        visited[i] = 0;
    }

    // 从第一个城镇开始计算最小花费
    calculateMinCost(0, 0);

    // 输出最小花费
    printf("最小花费为：%d\n", minCost);

    return 0;
}