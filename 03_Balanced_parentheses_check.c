#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) return; // Stack overflow not handled explicitly
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

bool isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

bool isBalanced(char* exp) {
    top = -1; // Reset stack top
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) return false;
            char popped = pop();
            if (!isMatchingPair(popped, c)) return false;
        }
    }
    return top == -1;
}

int main() {
    char expression[] = "{(a+b)*[c-d]}";
    if (isBalanced(expression))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}