#include <stdio.h>

void merge(int arr[], int left[], int leftLen, int right[], int rightLen) {
    int i = 0, j = 0, k = 0;
    
    while (i < leftLen && j < rightLen) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < leftLen) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < rightLen) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int n) {
    if (n < 2) {
        return;
    }
    
    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    int i;
    for ( i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    
    for (i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    
    mergesort(left, mid);
    mergesort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    mergesort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

