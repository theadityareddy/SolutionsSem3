#include <stdio.h>
#define MAX 7
typedef struct Queue
{
    int data[7];
    int front;
    int rear;
} Queue;

int isfull(Queue *p)
{
    if (p->rear == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(Queue *p)
{
    if (p->front == -1)
        return 1;
    else
        return 0;
}

void insert(Queue *p, int x)
{
    if (!isfull(p))
    {
        if (p->front == -1 && p->rear == -1)
            p->front = p->rear = 0;
        else
            p->rear++;
        p->data[p->rear] = x;
    }
    else
        printf("Queue is full");
}

int delet(Queue *p)
{
    int x = -1;

    if (!isempty(p))
    {
        x = p->data[p->front];
        if (p->front == p->rear)
            p->front = p->rear = -1;
        else
            p->front++;
    }
    else
        printf("Queue is empty");

    return x;
}

int peek(Queue *p)
{
    int x = -1;

    if (!isempty(p))
        x = p->data[p->front];
    else
        printf("Queue is empty");

    return x;
}

void display(Queue *p)
{
    int i;

    if (!isempty(p))
    {
        for (i = p->front; i <= p->rear; i++)
            printf("%d ", p->data[i]);
    }
    else
        printf("Queue is empty");
}

void init(Queue *p)
{
    p->front = p->rear = -1;
}
