
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

void calculateSpan(int price[], int n, int span[]) {
    top = -1;
    push(0);
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        while (top != -1 && price[peek()] <= price[i]) {
            pop();
        }
        span[i] = (top == -1) ? (i + 1) : (i - peek());
        push(i);
    }
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int span[MAX];

    calculateSpan(price, n, span);

    printf("Stock spans: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }
    printf("\n");
    return 0;
}
