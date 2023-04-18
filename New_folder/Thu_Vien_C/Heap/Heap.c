#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
/* 
Trong ví du này, chúng ta dinh nghia cau trúc Heap là mot c?u trúc d? li?u ch?a m?t m?ng các s? nguyên và kích thý?c c?a Heap.
 Chúng ta cài ð?t các hàm thao tác cõ b?n
  nhý `initialize()` ð? kh?i t?o Heap, 
  `insert()` ð? thêm m?t giá tr? vào Heap,
   `extract_max()` ð? l?y ra giá tr? l?n nh?t trong Heap và 
   `print_heap()` ð? in ra toàn b? Heap.

Hàm `heapify_up()` và `heapify_down()` ðý?c s? d?ng ð? duy tr? tính ch?t c?a Max-Heap khi thêm
 ho?c xóa m?t ph?n t?.
  Hàm `heapify_up()` s? ðýa ph?n t? v?a ðý?c thêm vào Heap lên trên cây nh? phân n?u nó l?n hõn cha c?a nó, ð?n khi nào không c?n l?n hõn cha ho?c ð? lên ð?n g?c c?a cây. Hàm `heapify_down()` s? ðýa ph?n t? v?a ðý?c xóa kh?i Heap xu?ng dý?i cây nh? phân n?u nó nh? hõn các con c?a nó, ð?n khi nào không c?n nh? hõn con ho?c ð? xu?ng ð?n lá c?a cây.
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
