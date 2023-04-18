#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 1000 
#define N 10

int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

void summarize_array(int *array, int n) {
  int i, j;
  for (i = 0; i < n; i = j) {
    for (j = i; j < n - 1 && array[j] + 1 == array[j + 1]; j++);
    if (j > i + 1) {
      printf("%d-%d, ", array[i], array[j]);
    } else {
      printf("%d, ", array[i]);
    }
  }
}

int main(void) {
  int i, array[N];
  time_t t;
  srand((unsigned) time(&t));
  for (i = 0; i < N; i++) {
    array[i] = rand() % M;
  }
  qsort(array, N, sizeof(int), compare);
  summarize_array(array, N);
  return 0;
}

