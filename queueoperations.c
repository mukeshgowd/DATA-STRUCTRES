#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int front, rear;
    int data[MAX];
};

void enqueue(struct Queue* queue, int item) {
    if (queue->rear >= MAX - 1) {
        printf("Queue overflow.\n");
        return;
    }
    queue->data[++queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue underflow.\n");
        return -1;
    }
    return queue->data[queue->front++];
}

void display(struct Queue queue) {
    int i;
    printf("Queue: ");
    for (i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    queue.front = 0;
    queue.rear = -1;

    int choice, item;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                item = dequeue(&queue);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
