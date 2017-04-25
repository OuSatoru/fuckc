//
// Created by Kasumi on 2017/4/25.
//
#include <stdlib.h>
#include "stdio.h"

void insertion_sort(int *array, int len) {
    int j, temp;
    for (int i = 1; i < len; ++i) {
        temp = array[i];
        for (j = i - 1; j >= 0; j--) {
            if (array[j] > temp) {
                array[j + 1] = array[j];
            } else {
                break;
            }
        }
        array[j + 1] = temp;
    }
}

void merge_array(int *array, int low, int mid, int high) {
    int *temp = malloc((high - low + 1) * sizeof(int));
    int i = low, j = mid + 1, p = 0;
    while (i <= mid && j <= high) {
        temp[p++] = (array[i] < array[j]) ? array[i++] : array[j++];
    }
    while (i <= mid) {
        temp[p++] = array[i++];
    }
    while (j <= high) {
        temp[p++] = array[j++];
    }
    for (p=0, i=low; i <= high; p++, i++) {
        array[i] = temp[p];
    }
}

// high = length - 1
void merge_sort(int *array, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge_array(array, low, mid, high);
    }
}

int main() {
    int array[10] = {456, 62, 756, 1243, 6, 25, 235, 74, 23, 963};
    merge_sort(array, 0, 9);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }
    return 0;
}
