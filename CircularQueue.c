#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

struct CircularQueue* createQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(struct CircularQueue* queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) ||
           (queue->rear == (queue->front - 1) % (MAX_SIZE - 1));
}

int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}

void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue item.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->items[queue->rear] = item;
    printf("Enqueued: %d\n", item);
}

int dequeue(struct CircularQueue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue item.\n");
        return -1;
    }
    item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue->items[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    struct CircularQueue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    display(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 6);
    enqueue(queue, 7);
    display(queue);

    return 0;
}



