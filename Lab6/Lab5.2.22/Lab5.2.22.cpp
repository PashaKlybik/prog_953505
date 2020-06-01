// Lab5.2.22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>



int RandomInt(int a, int b) {
	float k = (float)rand() / (float)(RAND_MAX + 1);
	return a + k * (b - a);
}

struct ListInt {
	struct Item {
		Item* next;
		Item* prev;
		int value;
	};
	Item* head;
	Item* tail;
};




ListInt* CreateListInt() {
	ListInt* list = (ListInt*)malloc(sizeof(ListInt));
	list->head = list->tail = NULL;
	return list;
}



void FreeListInt(ListInt* list) {
	for (ListInt::Item* item = list->head; item;) {
		ListInt::Item* nextitem = item->next;
		free(item);
		item = nextitem;
	}
	free(list);
}

ListInt::Item* GetHeadItem(ListInt* list) {
	return list->head;
}

ListInt::Item* GetNextItem(ListInt::Item* item) {
	return item->next;
}



void AddListBack(ListInt* list, int value) {
	ListInt::Item* newitem = (ListInt::Item*)malloc(sizeof(ListInt::Item));
	newitem->next = newitem->prev = NULL;
	newitem->value = value;
	newitem->prev = list->tail;
	if (list->tail) {
		list->tail->next = newitem;

	}
	else { list->head = newitem; }
	list->tail = newitem;
}


int IsStackEmpty(ListInt* list) {
	return (list->head == NULL && list->tail == NULL) ? 1 : 0;
}

void PushStack(ListInt* list, int value) {
	AddListBack(list, value);
}

int PopStack(ListInt* list) {
	ListInt::Item* tailitem = list->tail;
	int value = list->tail->value;
	list->tail = list->tail->prev;
	if (list->tail) {
		list->tail->next = NULL;
	}
	else {
		list->head = NULL;
	}
	free(tailitem);

	return value;
}

void PrintList(ListInt* list, const char* description) {
	printf(description);
	for (ListInt::Item* item = list->head; item; item = item->next) {
		printf("%d ", item->value);
	}
	printf("\n");
}

int main()
{
	srand(time(0));
	int totalnums;

	printf("Enter the number of elements: ");
	scanf_s("%d", &totalnums);

	ListInt* list = CreateListInt();
	for (int i = 0; i < totalnums; i++) {
		AddListBack(list, RandomInt(0, RAND_MAX));
	}

	ListInt* oddstack = CreateListInt();
	ListInt* evenstack = CreateListInt();
	for (ListInt::Item* item = GetHeadItem(list); item; item = GetNextItem(item))
	{
		if (item->value % 2) {
			PushStack(oddstack, item->value);
		}
		else PushStack(evenstack, item->value);
	}

	PrintList(list, "Source int list: ");
	PrintList(oddstack, "Odd int stack: ");
	PrintList(evenstack, "Even int stack: ");

	FreeListInt(evenstack);
	FreeListInt(oddstack);
	FreeListInt(list);
	return 0;
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
