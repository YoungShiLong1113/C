#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 100

struct item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    struct item *ia = (struct item *)a;
    struct item *ib = (struct item *)b;
    return (ib->value / ib->weight) - (ia->value / ia->weight);
}

int main() {
    struct item items[N] = {{20, 10}, {30, 20}, {66, 30}, {40, 40}, {60, 50}};
    qsort(items, N, sizeof(struct item), compare);
    int i, weight = 0, value = 0;
    for (i = 0; i < N && weight < M; i++) {
        if (items[i].weight + weight <= M) {
            weight += items[i].weight;
            value += items[i].value;
        } else {
            value += (M - weight) * (items[i].value / items[i].weight);
            break;
        }
    }
    printf("Maximum value: %d\n", value);
    return 0;
}
