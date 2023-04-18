#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int temp =*a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 2, 3, 4};
    printf("%d  %d \n",&arr[1],&arr[5]);
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    quicksort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
        printf("\n%d  %d \n",&arr[1],&arr[2]);

    return 0;
}

