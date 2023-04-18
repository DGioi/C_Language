#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define ITEM_COUNT 4

#define MAX_WEIGHT 60

int weights[ITEM_COUNT] = {10, 20, 30, 40};


bool knapsack(int item_index, int current_weight, int current_value) {
    
    if (item_index == ITEM_COUNT || current_weight > MAX_WEIGHT) {
        return current_value;
    }
    
    int value_without_item = knapsack(item_index + 1, current_weight, current_value);
   
    int value_with_item = knapsack(item_index + 1, current_weight + weights[item_index], current_value + weights[item_index]);
    return max(value_without_item, value_with_item);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    // G?i hàm gi?i bài toán
    int result = knapsack(0, 0, 0);
    // In k?t qu?
    printf("Giá tr? l?n nh?t có th? ð?t ðý?c: %d\n", result);
    return 0;
}

