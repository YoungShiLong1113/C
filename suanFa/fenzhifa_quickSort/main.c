#include <stdio.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 将数组分为两部分，左边的元素小于等于基准元素，右边的元素大于基准元素
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选取最后一个元素作为基准元素
    int i = (low - 1);  // 记录小于等于基准元素的索引

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 4, 6, 2, 5, 8, 4, 5, 6, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("排序后的数组：\n");
    printArray(arr, n);

    return 0;
}