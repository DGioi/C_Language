#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
/* 
Trong v� du n�y, ch�ng ta dinh nghia cau tr�c Heap l� mot c?u tr�c d? li?u ch?a m?t m?ng c�c s? nguy�n v� k�ch th�?c c?a Heap.
 Ch�ng ta c�i �?t c�c h�m thao t�c c� b?n
  nh� `initialize()` �? kh?i t?o Heap, 
  `insert()` �? th�m m?t gi� tr? v�o Heap,
   `extract_max()` �? l?y ra gi� tr? l?n nh?t trong Heap v� 
   `print_heap()` �? in ra to�n b? Heap.

H�m `heapify_up()` v� `heapify_down()` ��?c s? d?ng �? duy tr? t�nh ch?t c?a Max-Heap khi th�m
 ho?c x�a m?t ph?n t?.
  H�m `heapify_up()` s? ��a ph?n t? v?a ��?c th�m v�o Heap l�n tr�n c�y nh? ph�n n?u n� l?n h�n cha c?a n�, �?n khi n�o kh�ng c?n l?n h�n cha ho?c �? l�n �?n g?c c?a c�y. H�m `heapify_down()` s? ��a ph?n t? v?a ��?c x�a kh?i Heap xu?ng d�?i c�y nh? ph�n n?u n� nh? h�n c�c con c?a n�, �?n khi n�o kh�ng c?n nh? h�n con ho?c �? xu?ng �?n l� c?a c�y.
*/
typedef struct {
    int arr[MAX_SIZE];
    int size;
} Heap;

void initialize(Heap* heap) {
    heap->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(Heap* heap, int index) {
    int parent = index / 2;
    if (parent == 0) {
        return;
    }
    if (heap->arr[parent] < heap->arr[index]) {
        swap(&heap->arr[parent], &heap->arr[index]);
        heapify_up(heap, parent);
    }
}

void heapify_down(Heap* heap, int index) {
    int left_child = index * 2;
    int right_child = index * 2 + 1;
    int max_index = index;
    if (left_child <= heap->size && heap->arr[left_child] > heap->arr[max_index]) {
        max_index = left_child;
    }
    if (right_child <= heap->size && heap->arr[right_child] > heap->arr[max_index]) {
        max_index = right_child;
    }
    if (max_index != index) {
        swap(&heap->arr[max_index], &heap->arr[index]);
        heapify_down(heap, max_index);
    }
}

void insert(Heap* heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }
    heap->size++;
    heap->arr[heap->size] = value;
    heapify_up(heap, heap->size);
}

int extract_max(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap underflow!\n");
        return -1;
    }
    int max_value = heap->arr[1];
    heap->arr[1] = heap->arr[heap->size];
    heap->size--;
    heapify_down(heap, 1);
   
return max_value;
}

void print_heap(Heap* heap) {
printf("Heap: ");
int i; 
for (i = 1; i <= heap->size; i++) {
printf("%d ", heap->arr[i]);
}
printf("\n");
}

int main() {
Heap heap;
initialize(&heap);
insert(&heap, 5);
insert(&heap, 2);
insert(&heap, 8);
insert(&heap, 3);
insert(&heap, 1);
print_heap(&heap);
int max_value = extract_max(&heap);
printf("Max value extracted: %d\n", max_value);
print_heap(&heap);
return 0;
}
