#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int minReversals(char* expr) {
    int len = 0;
    while (expr[len] != '\0') len++;

    if (len % 2 != 0) return -1;  // odd length can't be balanced

    top = -1;
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '}' && top != -1 && stack[top] == '{') {
            pop();
        } else {
            push(c);
        }
    }

    int red_len = top + 1;
    int n_open = 0;

    while (top != -1 && stack[top] == '{') {
        pop();
        n_open++;
    }

    return (red_len / 2 + n_open % 2);
}

int main() {
    char expr[] = "}{{}}{{{";
    int result = minReversals(expr);
    if (result == -1)
        printf("Cannot be balanced\n");
    else
        printf("Minimum reversals needed: %d\n", result);
    return 0;
}