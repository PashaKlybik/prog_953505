#ifndef CATALOG_H_INCLUDED
#define CATALOG_H_INCLUDED

#include "section.h"
#include "costlist.h"
#include "reviewlist.h"

typedef struct item
{
    Section* section;
    CodeList* sourceCodes;
    ReviewList* comments;
} Item;

Item* CreateItem()
{
    Item* temp = (Item*)malloc(sizeof(Item));
    temp->section = (Section*)malloc(sizeof(Section));
    temp->sourceCodes = CreateCodeList();
    temp->comments = CreateReviewList();
    return temp;
}

#endif // CATALOG_H_INCLUDED
