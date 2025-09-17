#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

char text[MAX] = "";
char* history[MAX];
int top = -1;

void push(char* s) {
    history[++top] = strdup(s);
}

char* pop() {
    if (top == -1) return NULL;
    char* temp = history[top];
    top--;
    return temp;
}

int main() {
    int Q;
    scanf("%d", &Q);
    push(text);  

    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char appendStr[100001];
            scanf("%s", appendStr);
            strcat(text, appendStr);
            push(text);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            int len = strlen(text);
            text[len - k] = '\0';
            push(text);
        } else if (type == 3) {
            int pos;
            scanf("%d", &pos);
            printf("%c\n", text[pos - 1]);
        } else if (type == 4) {
            char* prev = pop();
            if (prev) {
                strcpy(text, prev);
                free(prev);
            }
        }
    }
    return 0;
}