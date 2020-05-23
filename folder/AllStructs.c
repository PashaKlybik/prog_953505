#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "AllStructs.h"
#include "work_with_files.h"
#define CurrentMonth May

char* GetMonth(Month month) {
	switch (month)
	{
	case May:return "May";
	case June:return "June";
	case July:return "July";
	case August:return "August";
	case September:return "September";
	case October:return "October";
	case November:return "November";
	case December:return "December";
	default:
		return "";
	}
}
void ClearList(Item* item) {
	if (item == NULL)return;
	ClearList(item->next);
	free(item);
}
Flight CreateFlight(char* flight_number,char destination[],char* type,int hour,int minute,int flight_time,int free_places) {
	Flight* temp = (Flight*)malloc(sizeof(Flight));
	temp->flight_time = flight_time;
	temp->free_places=free_places;
	return *temp;
}
void AddFlight(List* list, Flight* flight) 
{
	Item* p = (Item*)malloc(sizeof(Item));
		p->item = (Flight*)malloc(sizeof(Flight));
		memcpy(p->item, flight, sizeof(Flight));
	//memcpy(,,);
	//p->item = flight;
	p->next = p->prev = NULL;
	if (list->head == NULL)list->head = list->tail = p;
	else {
		list->tail->next = p;
		p->prev = list->tail;
		list->tail = p;
	}
	list->n++;
}
void PrintFlight(Flight flight)
{
	printf("\nFlight number:%s\tType:%s\tDestination:%s\tDate: %s,%d\tDeparture Time:%d:%d\t Flight Time:%d  Free Places:%d",
		flight.flight_number,flight.type,flight.destination,GetMonth(flight.month),flight.day,
		flight.hour,flight.minute,flight.flight_time,flight.free_places);
}
void PrintFlightByIndex(List* list,int index) {
	if (index < 0)return;
	Item* p = (Item*)malloc(sizeof(Item));
	p->item = (Flight*)malloc(sizeof(Flight));
	p = list->head;
	while (p->item->numinlist!=index) {
		if (p->item->numinlist == index) {
			PrintFlight(*p->item);
		}
		p = p->next;
	}
}
void PrintAllFlights(List* list) 
{
	system("cls");
	Item* p = list->head;
	while (p) 
	{
		//место для функции показа билетика XDDD ПАМАГИТЕ МНЕ СТРАШНО ИДТИ НА СЕССИю
		PrintFlight(*p->item);
		p = p->next;
	}	
	getchar();
}
void AddFlightInList(List* list) {
	system("cls");
	Flight* flight = (Flight*)malloc(sizeof(Flight));
	flight->numinlist = list->n;
	printf("Enter destination:");
	scanf("%s", flight->destination);
	printf("Enter flight number:");
	scanf("%s", flight->flight_number);
	printf("Enter type of plane:");
	scanf("%s", flight->type);
	printf("Enter the hour of arrival:");
	scanf("%d", &flight->hour);
	printf("Enter the minute of arrival:");
	scanf("%d", &flight->minute);
	printf("Enter count of free places:");
	scanf("%d", &flight->free_places);
	printf("Enter flight time:");
	scanf("%d", &flight->flight_time);
	printf("Enter month of flight(as digit):");
	scanf("%d", &flight->month);
	flight->month += 5;
	printf("Enter day of flight(as digit):");
	scanf("%d", &flight->day);
	AddFlight(list, flight);
	LoadToFile(flight);
}
void Search(List* list)
{
	char key;
	do
	{
		key = getchar();
		system("cls");
		printf("\t\t\t\t\tBelavia\n\n");
		printf(
			"1.Find appropriate race\n"
			"2.Back\n");
		switch (key)
		{
		case '1': AppropriateRace(list); break;
		default:
			break;
		}
	} while (key != '2');

}
void AppropriateRace(List* list)
{
	int count = 0;
	char destination[15];
	int index = 0;
	Month tempMonth=December;
	int tempDay = 31;
	system("cls");
	printf("Please, enter destination:");
	scanf_s("%s", destination,sizeof(destination));
	//Item* p = (Item*)malloc(sizeof(Item));
	//p=(list)->head;
	Item* p = list->head;
	while (p)
	{
		if (strcmp(p->item->destination,destination)==0) {
			 if ((int)p->item->month == (int)tempMonth) {
				if (p->item->day<tempDay) {
					tempDay = p->item->day;
					tempMonth = p->item->month;
					index = p->item->numinlist;
					count++;
				}
			}else if ((int)p->item->month<(int)tempMonth && (int)p->item->month>(int)CurrentMonth) {
				tempDay = p->item->day;
				tempMonth = p->item->month;
				index = p->item->numinlist;
				count++;
			}
			
		}
		p = p->next;
	}
	if (!count) {
		printf("\nNo results were found for this request.\n");
	}else PrintFlightByIndex(list, index);
	free(p);
	getchar();
}
