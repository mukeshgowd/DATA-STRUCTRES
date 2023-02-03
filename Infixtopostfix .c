#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow.\n");
        return '\0';
    }
    return stack[top--];
}

int priority(char symbol) {
    switch (symbol) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

char* infixToPostfix(char* infix) {
    int i, j = 0;
    char item;
    char* postfix = (char*)malloc(strlen(infix) + 1);
    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];
        if (isalnum(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (priority(stack[top]) >= priority(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    char* postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);
    free(postfix);
    return 0;
}
