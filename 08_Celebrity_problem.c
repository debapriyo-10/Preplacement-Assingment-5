#include <stdio.h>

#define MAX 100

int M[MAX][MAX];  

int knows(int a, int b, int n) {
    return M[a][b];
}

int findCelebrity(int n) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    // Get potential celebrity
    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(a, b, n)) {
            stack[++top] = b;
        } else {
            stack[++top] = a;
        }
    }

    int candidate = stack[top];

    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(candidate, i, n) || !knows(i, candidate, n))) {
            return -1;
        }
    }
    return candidate;
}

int main() {
    int n = 4;
    int matrix[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0},
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = matrix[i][j];

    int celeb = findCelebrity(n);
    if (celeb == -1)
        printf("No celebrity found\n");
    else
        printf("Celebrity is person %d\n", celeb);
    return 0;
}