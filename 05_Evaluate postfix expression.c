#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    int i = 0;
    char c;
    while ((c = exp[i++]) != '\0') {
        if (isdigit(c)) {
            push(c - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default: printf("Invalid operator %c\n", c); return -1;
            }
        }
    }
    return pop();
}

int main() {
    char exp[] = "231*+9-";
    printf("Postfix Evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}