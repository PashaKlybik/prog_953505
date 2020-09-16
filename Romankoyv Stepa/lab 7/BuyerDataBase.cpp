﻿#define _CRT_SECURE_NO_WARNINGS

#include "BuyerDataBase.h"

BuyerBase* addBuyer(char* n, Contacts c, char* dB, int y, int st, int mP, BuyerBase* head)
{
    system("chcp1251");
    system("cls");
    int i = 0;
    BuyerBase* newItem = (BuyerBase*)calloc(1, sizeof(BuyerBase));
    if (!newItem)
    {
        printf("Îøèáêà âûäåëåíèÿ ïàìÿòè\n");
        return NULL;
    }
    for (i = 0; n[i] != '\0'; i++)
        newItem->name[i] = n[i];
    newItem->contact = c;
    for (i = 0; dB[i] != '\0'; i++)
        newItem->desiredBrand[i] = dB[i];
    newItem->year = y;
    if (st == 1)
        newItem->state = 1;
    else newItem->state = 0;
    newItem->maxPrice = mP;
    if (!head)
    {
        head = newItem;
    }
    else
    {
        BuyerBase* current = head;
        for (i = 1; current->next != NULL; i++)
            current = current->next;
        if (current->next)
        {
            current->next->prev = newItem;
        }
        newItem->next = current->next;
        current->next = newItem;
        newItem->prev = current;
        current = newItem;
    }
    return head;
}

void showBuyer(BuyerBase* head)
{
    if (head)
    {
        printf("%s%s%s", "ÔÈÎ: ", head->name, "\n");
        printf("%s%d%s%s%s", "Òåëåôîí: ", head->contact.number, "\nÏî÷òà: ", head->contact.email, "\n");
        printf("%s%s%s", "Æåëàåìàÿ ìàðêà: ", head->desiredBrand, "\n");
        printf("%s%d%s", "Ãîä: ", head->year, "\n");
        if (head->state == 1)
        {
            printf("Cîñòîÿíèå àâòîìîáèëÿ: íîâûé\n");
        }
        else printf("Cîñòîÿíèå àâòîìîáèëÿ: á/ó\n");
        printf("%s%d%s", "Ôèíàíñîâûå âîçìîæíîñòè: ", head->maxPrice, "\n");
        printf("\n");
        showBuyer(head->next);
    }
    else printf("\n");
}

void delAllBuyer(BuyerBase* head)
{
    if (head) {
        delAllBuyer(head->next);
        free(head);
    }
}