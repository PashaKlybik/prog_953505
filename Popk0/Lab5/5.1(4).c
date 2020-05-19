//IDE: CodeBlocks
//Task 5.1(4)
/*
Разработать функцию, переводящую многоразрядное десятичное
число в восьмеричную систему. Для хранения многоразрядного
числа использовать динамический двунаправленный список.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct item
{
	int digit;
	struct item* next;
	struct item* prev;
} Item;

typedef struct mnumber
{
	Item* head;
	Item* tail;
	int n;
} MNumber;

MNumber CreateMNumber(char* initStr);
void AddDigit(MNumber* number, int digit);
void PrintMNumber(MNumber number);
MNumber Base10toBase8(MNumber n1);

void main(void)
{
    printf("Input: ");
    char str[40];
    gets(str);
	MNumber a = CreateMNumber(str);
	MNumber c = Base10toBase8(a);
    PrintMNumber(c);
}

MNumber CreateMNumber(char initStr[])
{
	MNumber number = { NULL, NULL, 0 };
	int n;
	for (n = strlen(initStr) - 1; n >= 0; n--)
		AddDigit(&number, initStr[n] - '0');
	return number;
}

void AddDigit(MNumber* number, int digit)
{
	Item* p = (Item*)malloc(sizeof(Item));
	p->digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL)
		number->head = number->tail = p;
	else
	{
		number->tail->next = p;
		p->prev = number->tail;
		number->tail = p;
	}
	number->n++;
}

int from10to8(int number)
{
	int ost, zeloe, arr[100];
	int i = 0, l = 0;
	while (zeloe != 0)
	{
		zeloe = number/8;
		ost = number%8;
		number = zeloe;
		arr[i] = ost;
		i++, l++;
	}
	number = 0;
	for (int i = l-1; i >= 0; i--)
    {
        number *= 10;
        number += arr[i];
    }
    return number;
}

MNumber Base10toBase8(MNumber n1)
{
	MNumber sum = CreateMNumber("");
	Item* p1 = n1.head;
	int digit, pos = 0, s1, s = 5, i = 0;
    int arr1[s], arr2[s];
	while (p1)
	{
		if (p1) { s1 = p1->digit; p1 = p1->next; }
		else {};
		digit = s1;
		arr1[i] = digit;
		i++;
    }
    int ii = i;
    for (int j = 0; j < ii; j++, i--)
    {
        arr2[j] = arr1[i-1];
    }

    int value = 0;
    for (size_t i = 0; i < ii; ++i)
    {
        value *= 10;
        value += arr2[i];
    }
    printf("Your number in Base10 = %d", value);

    value = from10to8(value);
    AddDigit(&sum, value);
	return sum;
}

void PrintMNumber(MNumber number)
{
	Item* p = number.tail;
	printf("\nYour number in Base8 = ");
	while (p)
	{
		printf("%d", p->digit);
		p = p->prev;
	}
}
