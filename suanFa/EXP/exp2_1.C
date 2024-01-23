#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE_TYPE 99999999
#define ZERO_VALUE_OF_TYPE 0

typedef int Type;

struct NODE
{
    int v_num;         // 节点编号
    Type len;          // 边的长度
    struct NODE *next; // 下一个节点的指针
};

Type fgraph(struct NODE node[], int route[], int n)
{
    int i;
    struct NODE *pnode;
    int *path = (int *)malloc(n * sizeof(int));   // 动态分配大小为 n 的整型数组用于存储路径
    Type *cost = (Type *)malloc(n * sizeof(Type)); // 动态分配大小为 n 的 Type 类型数组用于存储最短距离

    // 初始化 cost、path 和 route 数组
    for (i = 0; i < n; i++)
    {
        cost[i] = MAX_VALUE_TYPE;
        path[i] = -1;
        route[i] = 0;
    }

    cost[n - 1] = ZERO_VALUE_OF_TYPE; // 将终点的最短距离设为 0

    // 从倒数第二个节点开始，逐个更新最短距离和路径
    for (i = n - 2; i >= 0; i--)
    {
        pnode = node[i].next;
        while (pnode != NULL)
        {
            if (pnode->len + cost[pnode->v_num] < cost[i])
            {
                cost[i] = pnode->len + cost[pnode->v_num];
                path[i] = pnode->v_num;
            }
            pnode = pnode->next;
        }
    }

    i = 0;
    // 根据路径数组构建完整的路径
    while ((route[i] != n - 1) && (path[i] != -1))
    {
        i++;
        route[i] = path[route[i - 1]];
    }

    Type min_cost = cost[0]; // 最短距离即为 cost 数组中的第一个元素

    free(path); // 释放动态分配的内存
    free(cost);

    return min_cost; // 返回最短距离
}

void addEdge(struct NODE *node, int v_num, Type len)
{
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->v_num = v_num;
    new_node->len = len;
    new_node->next = node->next;
    node->next = new_node;
}

int main()
{
    struct NODE node[7]; // 存储图中的节点
    int route[7];        // 存储从起始节点到每个节点的路径
    int i;

    // 创建图中的节点，并设置节点编号和边的长度
    for (i = 0; i < 7; i++)
    {
        node[i].v_num = i;
        node[i].next = NULL;
    }

    // 添加节点之间的边
    addEdge(&node[0], 1, 4);
    addEdge(&node[0], 3, 8);
    addEdge(&node[0], 2, 5);

    addEdge(&node[1], 3, 6);
    addEdge(&node[1], 4, 6);

    addEdge(&node[2], 3, 5);
    addEdge(&node[2], 5, 7);

    addEdge(&node[3], 4, 8);
    addEdge(&node[3], 5, 9);
    addEdge(&node[3], 6, 9);

    addEdge(&node[4], 6, 5);

    addEdge(&node[5], 6, 4);

    addEdge(&node[6], 6, 0);
    // 调用 fgraph 函数计算最短路径
    Type min_cost = fgraph(node, route, 7);

    printf("最短花费为：%d\n", min_cost);
    printf("最短路径为：");
    for (i = 0; i < 7; i++)
    {
        printf("%d ", route[i]);
    }
    printf("\n");

    return 0;
}
