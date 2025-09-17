#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

void nextGreaterElement(int arr[], int n, int result[]) {
    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && arr[peek()] <= arr[i]) {
            pop();
        }
        result[i] = (top == -1) ? -1 : arr[peek()];
        push(i);
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[MAX];

    nextGreaterElement(arr, n, result);

    printf("Next Greater Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}