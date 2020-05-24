#ifndef SECTION_H_INCLUDED
#define SECTION_H_INCLUDED

#include "costlist.h"

typedef struct section
{
    char* product;
    char* section;
    char* date;
    char* equipment;
    List* describe;
} Section;

Section* CreateSection()
{
    Section* temp = (Section*)malloc(sizeof(Section));
    temp->describe = CreateList();
    return temp;
}

void DeleteSection(Section* temp)
{
    DeleteList(temp->describe);
    free(temp->product);
    free(temp->section);
    free(temp->date);
    free(temp->equipment);
}

#endif // SECTION_H_INCLUDED
