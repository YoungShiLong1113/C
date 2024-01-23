// 编写程序实现用3种颜色着色问题 ABCDE  相互连接的节点有AB AC BC BD BE CE DE
#include <stdio.h>
#include <stdlib.h>


#define MAX_NODES 6
#define NUM_COLORS 3

int main() {
    int adj_matrix[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1, 0}
    };

    int colors[MAX_NODES] = {0};
    int num_colors = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        if (colors[i] == 0) {
            colors[i] = 1;
            num_colors++;
            for (int j = 0; j < MAX_NODES; j++) {
                if (adj_matrix[i][j] == 1 && colors[j] == 0) {
                    colors[j] = num_colors;
                    num_colors++;
                }
            }
        }
    }

    if (num_colors == NUM_COLORS) {
        printf("Yes, it is possible to color the nodes with 3 different colors.\n");
    } else {
        printf("No, it is not possible to color the nodes with 3 different colors.\n");
    }

 return 0;
}