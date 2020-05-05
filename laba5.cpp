#define maxQueue 5
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
struct Queue
{
	int room1;
	int room2;
	int room3;
	int room4;
	int room5;
};

int GetMinQueue(Queue q)
{
	int minQueue = maxQueue;
	if (minQueue > q.room1)minQueue = q.room1;
	if (minQueue > q.room2)minQueue = q.room2;
	if (minQueue > q.room3)minQueue = q.room3;
	if (minQueue > q.room4)minQueue = q.room4;
	if (minQueue > q.room5)minQueue = q.room5;
	return minQueue;
}


int main()
{
	Queue queue;
	int generalTime = 0, minQueue = maxQueue;
	srand(time(NULL));
	queue.room1 = rand() % maxQueue;
	queue.room2 = rand() % maxQueue;
	queue.room3 = rand() % maxQueue;
	queue.room4 = rand() % maxQueue;
	queue.room5 = rand() % maxQueue;
	minQueue = GetMinQueue(queue);

	if (minQueue = queue.room1)
	{
		generalTime = minQueue * (1 + rand() % 5) + queue.room2 * (1 + rand() % 5) + queue.room3 * (1 + rand() % 5) + queue.room4 * (1 + rand() % 5) + queue.room5 * (1 + rand() % 5);
	}
	else if (minQueue = queue.room2)
	{
		generalTime = minQueue * (1 + rand() % 5) + queue.room1 * (1 + rand() % 5) + queue.room3 * (1 + rand() % 5) + queue.room4 * (1 + rand() % 5) + queue.room5 * (1 + rand() % 5);
	}
	else if (minQueue = queue.room3)
	{
		generalTime = minQueue * (1 + rand() % 5) + queue.room2 * (1 + rand() % 5) + queue.room1 * (1 + rand() % 5) + queue.room4 * (1 + rand() % 5) + queue.room5 * (1 + rand() % 5);
	}
	else if (minQueue = queue.room4)
	{
		generalTime = minQueue * (1 + rand() % 5) + queue.room2 * (1 + rand() % 5) + queue.room3 * (1 + rand() % 5) + queue.room1 * (1 + rand() % 5) + queue.room5 * (1 + rand() % 5);
	}
	else
	{
		generalTime = minQueue * (1 + rand() % 5) + queue.room2 * (1 + rand() % 5) + queue.room3 * (1 + rand() % 5) + queue.room4 * (1 + rand() % 5) + queue.room1 * (1 + rand() % 5);
	}

	generalTime -= 10 * (1 + rand() % 5);//bikoz while on prohodil ostal'niye toje moved

	printf_s("%d", abs(generalTime));
}

