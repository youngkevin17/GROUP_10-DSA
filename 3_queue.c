#include <stdio.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
int enqueue(Queue *q, int value);
int dequeue(Queue *q, int *value);
int peek(Queue *q, int *value);
void printQueue(Queue *q);

int main(void)
{
    Queue q;
    int value;

    initQueue(&q);

    printf("Enqueue 10:\n");
    enqueue(&q, 10);
    printQueue(&q);

    printf("Enqueue 20:\n");
    enqueue(&q, 20);
    printQueue(&q);

    printf("Enqueue 30:\n");
    enqueue(&q, 30);
    printQueue(&q);

    printf("Peek: ");
    peek(&q, &value);
    printf("%d\n\n", value);

    printf("Dequeue:\n");
    dequeue(&q, &value);
    printf("Dequeued %d\n", value);
    printQueue(&q);

    printf("Enqueue 40:\n");
    enqueue(&q, 40);
    printQueue(&q);

    printf("Dequeue:\n");
    dequeue(&q, &value);
    printf("Dequeued %d\n", value);
    printQueue(&q);

    return 0;
}

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q)
{
    return q->count == 0;
}

int isFull(Queue *q)
{
    return q->count == MAX;
}

/* Enqueue: O(1) - circular buffer, constant-time insert at rear */
int enqueue(Queue *q, int value)
{
    if (isFull(q)) {
        return 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    q->count++;
    return 1;
}

/* Dequeue: O(1) - constant-time remove from front */
int dequeue(Queue *q, int *value)
{
    if (isEmpty(q)) {
        return 0;
    }
    *value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return 1;
}

/* Peek: O(1) */
int peek(Queue *q, int *value)
{
    if (isEmpty(q)) {
        return 0;
    }
    *value = q->items[q->front];
    return 1;
}

void printQueue(Queue *q)
{
    int i;
    int idx;

    if (isEmpty(q)) {
        printf("Queue: [empty]\n\n");
        return;
    }

    printf("Queue: [");
    for (i = 0; i < q->count; i++) {
        idx = (q->front + i) % MAX;
        printf("%d", q->items[idx]);
        if (i < q->count - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}
