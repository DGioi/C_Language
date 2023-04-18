#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
/*initialize: khoi tao ngan xep
isEmpty:kiem tra ngan xep co rong hay khong
isFull: kiem tra xem ngan xep da day chua
push: The mot phan tu vao ngan xep
pop: lay ra phan tu tu ngan xep
peek: Lay ra gia tri cua phan tu dau ma khong xoa khoi ngan xep.*/
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("%d\n", pop(&stack)); // Output: 3
    printf("%d\n", pop(&stack)); // Output: 2
    printf("%d\n", peek(&stack)); // Output: 1
    return 0;
}

