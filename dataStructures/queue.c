#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
struct Queue
{
    int front, rear;
    int capacity;
    int *arr;
};
void startQ(struct Queue *queue, int capacity)
{
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->arr = (int *)malloc(queue->capacity * sizeof(int));
}
int isFull(struct Queue *queue)
{
    return ((queue->rear + 1) % queue->capacity == queue->front);
}
int isEmpty(struct Queue *queue)
{
    return (queue->front == -1);
}
void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("ERROR!,THE QUEUE IS FULL");
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->arr[queue->rear] = item;
        printf("%d enqueued\n", item);
    }
}
void dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("ERROR,THE QUEUE IS EMPTY");
    }
    else
    {
        int removedItem = queue->arr[queue->front];
        if (queue->front == queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % queue->capacity;
        }
        printf("%d dequeued\n", removedItem);
    }
}
void queueSize(struct Queue *queue)
{
    if (isEmpty(queue))
        printf("Queue Size is 0.\n");
    else

        printf("Queue size is %d.\n", (queue->capacity + queue->rear - queue->front) % queue->capacity + 1);
}
void peek(struct Queue *queue)
{
    if (isEmpty(queue))
        printf("Queue is empty\n");
    else
        printf("Front element: %d\n", queue->arr[queue->front]);
}

void front(struct Queue *queue)
{
    printf("Front element: %d\n", queue->arr[queue->front]);
}

void rear(struct Queue *queue)
{
    printf("Rear element: %d\n", queue->arr[queue->rear]);
}
int main()
{
    struct Queue queue;
    startQ(&queue, SIZE);
    int choice, item;
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. isEmpty\n4.isFull\n5. Queue Size\n6. Peek\n7.FRONT\n 8.Rear\n 9.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE ELEMENT TO ENQUEUE");
            scanf("%d", &item);
            enqueue(&queue, item);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            isEmpty(&queue);
            break;
        case 4:
            isFull(&queue);
            break;
        case 5:
            queueSize(&queue);
            break;
        case 6:
            peek(&queue);
            break;
        case 7:
            front(&queue);
            break;
        case 8:
            rear(&queue);
            break;
        default:
            printf("INvaLID OPTION");
            break;
        }
    } while (choice != 9);
    return 0;
}