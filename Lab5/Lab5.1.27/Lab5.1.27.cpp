// Lab5.1.27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

struct CommandItem {
	int n;
	char action;
	char symbol;
	CommandItem* next;
	CommandItem* prev;
};

struct QueueItem {
	QueueItem* next;
	char symbol;
};

int RandomInt(int a, int b) {
	float k = (float)rand() / (float)(RAND_MAX + 1);
	return a + k * (b - a);
}

CommandItem* GenerateComandList(int totalqueues, int size) {
	CommandItem* commandhead = NULL;
	CommandItem* commandtail = NULL;
	for (int i = 0; i < size; i++) {
		CommandItem* ci = (CommandItem*)malloc(sizeof(CommandItem));
		ci->n = RandomInt(0, totalqueues);
		ci->action = (RandomInt(0, 2) == 0 ? 'A' : 'D');
		ci->symbol = RandomInt(0, 'z' - 'a' + 1) + 'a';
		ci->next = ci->prev = NULL;
		if (commandhead == NULL) {
			commandhead = ci;
			commandtail = ci;
			continue;
		}
		commandtail->next = ci;
		ci->prev = commandtail;
		commandtail = ci;

	}
	return commandhead;
}

void FreeCommandList(CommandItem* head) {
	CommandItem* curitem = head;
	while (curitem) {
		CommandItem* next = curitem->next;
		free(curitem);
		curitem = next;
	}
	free(head);
}

void AddElemToQueue(int index, QueueItem** queues, char symbol) {
	QueueItem* head = queues[index];
	if (!head) {
		head = (QueueItem*)malloc(sizeof(QueueItem));
		head->next = NULL;
		head->symbol = symbol;
		queues[index] = head;
		return;
	}
	while (head->next) {
		head = head->next;
	}
	QueueItem* newitem = (QueueItem*)malloc(sizeof(QueueItem));
	newitem->next = NULL;
	newitem->symbol = symbol;
	head->next = newitem;
	return;
}

void DeleteElemFromQueue(int index, QueueItem** queues) {
	QueueItem* head = queues[index];
	if (!head) {
		return;
	}
	queues[index] = head->next;
	free(head);
}

void ProcessCommands(CommandItem* ci, QueueItem** queues) {

	while (ci) {
		if (ci->action == 'A') {
			AddElemToQueue(ci->n, queues, ci->symbol);
		}
		else DeleteElemFromQueue(ci->n, queues);
		ci = ci->next;
	}
}

void PrintQueues(const int n, QueueItem** queues) {
	for (int i = 0; i < n; i++) {
		printf("%d queue: ", i);
		QueueItem* curitem = queues[i];
		while (curitem) {
			printf("%c", curitem->symbol);
			curitem = curitem->next;
		}
		printf("\n");
	}
}

void PrintCommands(CommandItem* ci) {
	printf("Commands: ");
	while (ci) {
		printf("[%d%c", ci->n, ci->action);
		if (ci->action == 'A') {
			printf("%c", ci->symbol);
		}
		printf("]");
		ci = ci->next;
	}
	printf("\n");
}



QueueItem** CreateQueues(int n) {
	QueueItem** array = (QueueItem**)malloc(n * sizeof(QueueItem*));
	for (int i = 0; i < n; i++) {
		array[i] = NULL;
	}
	return array;
}

void FreeQueues(const int n, QueueItem** queues) {
	for (int i = 0; i < n; i++) {
		QueueItem* curitem = queues[i];
		queues[i] = NULL;
		while (curitem) {
			QueueItem* next = curitem->next;
			free(curitem);
			curitem = next;
		}
	}
	free(queues);
}

int main()
{
	srand(time(0));
	int queues, commands;

	printf("Enter the tnumber of queues: ");
	scanf_s("%d", &queues);
	printf("Enter the number of commands: ");
	scanf_s("%d", &commands);
	CommandItem* commandhead = GenerateComandList(queues, commands);
	QueueItem** array = CreateQueues(queues);
	ProcessCommands(commandhead, array);
	PrintCommands(commandhead);
	PrintQueues(queues, array);

	FreeQueues(queues, array);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
