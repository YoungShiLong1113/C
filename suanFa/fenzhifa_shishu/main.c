#include <stdio.h>

void findMinMax(float arr[], int low, int high, float *min, float *max)
{
    float min1, max1, min2, max2, mid;
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
    }
    else if (high - low == 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        }
        else {
            *max = arr[high];
            *min = arr[low];
        }
    }
    else {
        mid = (low + high) / 2;
        findMinMax(arr, low, mid, &min1, &max1);
        findMinMax(arr, mid + 1, high, &min2, &max2);
        if (min1 < min2) {
            *min = min1;
        }
        else {
            *min = min2;
        }
        if (max1 > max2) {
            *max = max1;
        }
        else {
            *max = max2;
        }
    }
}

int main()
{
    float arr[] = { 9,3,6,2,1,8,4,5,7,23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    float min, max;
    findMinMax(arr, 0, n - 1, &min, &max);
    printf("Minimum: %f\n", min);
    printf("Maximum: %f\n", max);
    return 0;
}
