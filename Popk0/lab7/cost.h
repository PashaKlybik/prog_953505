#ifndef COST_H_INCLUDED
#define COST_H_INCLUDED

#include "describelist.h"

typedef struct cost
{
    char* product;
    char* equipment;
    List* cost;
} Cost;

Cost* CreateCost()
{
    Cost* temp = (Cost*)malloc(sizeof(Cost));
    temp->cost = CreateList();
    return temp;
}

void DeleteCost(Cost* temp)
{
    DeleteList(temp->cost);
    free(temp->product);
    free(temp->equipment);
    free(temp);
}

#endif // COST_H_INCLUDED
