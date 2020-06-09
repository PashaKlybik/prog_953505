#include "Header.h"
#pragma once

struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}


int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}



void enQueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
}
void showArray(struct Queue* queue)
{
    printf("\n Queue:\n");
    for (int k = queue->front; k <= queue->rear; k++)
    {
        printf("%d\t", queue->array[k]);
    }
    printf("\n");
}


int deQueue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return item;
}


int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}