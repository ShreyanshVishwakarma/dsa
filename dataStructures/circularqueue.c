#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int capacity;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *q)
{
    if ((q->r + 1) % q->capacity == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->capacity;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->capacity;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    printf("enter the capacity of queue \n");
    scanf("%d", &q->capacity);
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->capacity * sizeof(int));
    int p;
    int flag = 1;
    while (flag)
    {
        printf("enter the value of operator\n ");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            printf("check wheter empty\n");
            if (isEmpty(q))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("not empty\n");
            }
            break;
        case 2:
            printf("check full or not \n");

            if (isFull(q))
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("not full \n");
            }
            break;
        case 3:
            printf("now enqueue\n");
            int val;
            printf("enter the value ");
            scanf("%d", &val);
            enqueue(q, val);
            break;
        case 4:
            printf("now the dequeue\n");
            int del = dequeue(q);
            printf("the delected element is  %d \n", del);
            break;
        case 5:
            if (q->f > q->r)
            {
                printf("the size is %d ", (q->capacity - q->f + q->r + 1));
            }
            else
            {
                printf("the size is %d ", (q->r - q->f + 1));
            }
            break;
        default:
            printf("invalid operator \n");
        }
        printf(" type 1 for exist and 0 for out");
        scanf("%d", &flag);
    }
    return 0;
}