#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top] = item;
    printf("Item %d is pushed to the stack.\n", item);
}

int pop() {
    if (top < 0) {
        printf("Stack underflow.\n");
        return -1;
    }
    int item = stack[top--];
    printf("Item %d is popped from the stack.\n", item);
    return item;
}

int peek() {
    if (top < 0) {
        printf("Stack is empty.\n");
        return -1;
    }
    int item = stack[top];
    printf("Top item is %d.\n", item);
    return item;
}

int main() {
    int choice, item;
    while (1) {
        printf("\nEnter 1 to push an item, 2 to pop an item, 3 to peek, and 4 to exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter an item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}

