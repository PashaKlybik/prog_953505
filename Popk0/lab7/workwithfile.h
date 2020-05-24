#ifndef WORKWITHFILE_H_INCLUDED
#define WORKWITHFILE_H_INCLUDED

#include "costlist.h"
#include "section.h"
#include "catalog.h"
#include "dlist.h"
#include "costlist.h"
#include "cost.h"
#include "review.h"
#include "reviewlist.h"

void FileReadCatalog(DList* collectionOfItems)
{
    int strSize = 50;
    char* str = (char*)malloc(strSize * sizeof(char));
    FILE* fp = fopen("sections.txt", "r");
    int i = 0;
    Item* forFill;
    List* tempie = CreateList();
    while (!feof(fp))
    {
        fscanf(fp, "%c", &str[i]);
        if (str[i] == '\n' || feof(fp))
        {
            str[i] = '\0';
            if ((strlen(str) == 3 && str[0] == '=' && str[1] == '=' && str[2] == '=') || feof(fp))
            {
                if (feof(fp))
                {
                    ListPushBack(tempie, str);
                }
                forFill = CreateItem();
                forFill->section->product = strdup(ListPeek(tempie));
                ListPop(tempie);
                forFill->section->section = strdup(ListPeek(tempie));
                ListPop(tempie);
                forFill->section->date = strdup(ListPeek(tempie));
                ListPop(tempie);
                forFill->section->equipment = strdup(ListPeek(tempie));
                ListPop(tempie);
                forFill->section->describe = tempie;
                DListPushBack(collectionOfItems, forFill);
                tempie = CreateList();
                str = (char*)malloc(strSize * sizeof(char));
                i = 0;
                continue;
            }
            str = (char*)realloc(str, (i + 1) * sizeof(char));
            ListPushBack(tempie, str);
            str = (char*)malloc(strSize * sizeof(char));
            i = 0;
            continue;
        }
        i++;
        if (i >= strSize)
        {
            strSize *= 2;
            str = (char*)realloc(str, strSize * sizeof(char));
        }
    }
    fclose(fp);
    free(str);
}

void FileReadEquipment(DList* collectionOfItems)
{
    int strSize = 50;
    char* str = (char*)malloc(strSize * sizeof(char));
    FILE* fp = fopen("equipment.txt", "r");
    int i = 0;
    Cost* forFill;
    List* tempie = CreateList();
    while (!feof(fp))
    {
        fscanf(fp, "%c", &str[i]);
        if (str[i] == '\n' || feof(fp))
        {
            str[i] = '\0';
            if ((strlen(str) == 3 && str[0] == '=' && str[1] == '=' && str[2] == '=') || feof(fp))
            {
                if (feof(fp))
                {
                    ListPushBack(tempie, str);
                }
                DListNode* pos = collectionOfItems->head;
                while (pos != NULL)
                {
                    if (strcmp(pos->data->section->product, ListPeek(tempie)) == 0) break;
                    pos = pos->next;
                }
                if (pos != NULL)
                {
                    forFill = CreateCost();
                    forFill->product = strdup(ListPeek(tempie));
                    ListPop(tempie);
                    forFill->equipment = strdup(ListPeek(tempie));
                    ListPop(tempie);
                    forFill->cost = tempie;
                    CodeListPushBack(pos->data->sourceCodes, forFill);
                }
                tempie = CreateList();
                str = (char*)malloc(strSize * sizeof(char));
                i = 0;
                continue;
            }
            str = (char*)realloc(str, (i + 1) * sizeof(char));
            ListPushBack(tempie, str);
            str = (char*)malloc(strSize * sizeof(char));
            i = 0;
            continue;
        }
        i++;
        if (i >= strSize)
        {
            strSize *= 2;
            str = (char*)realloc(str, strSize * sizeof(char));
        }
    }
    fclose(fp);
    free(str);
}

void FileReadReviews(DList* collectionOfItems)
{
    int strSize = 50;
    char* str = (char*)malloc(strSize * sizeof(char));
    FILE* fp = fopen("output.txt", "r");
    int i = 0;
    Review* forFill;
    List* tempie = CreateList();
    while (!feof(fp))
    {
        fscanf(fp, "%c", &str[i]);
        if (str[i] == '\n' || feof(fp))
        {
            str[i] = '\0';
            if ((strlen(str) == 3 && str[0] == '=' && str[1] == '=' && str[2] == '=') || feof(fp))
            {
                if (feof(fp))
                {
                    ListPushBack(tempie, str);
                }
                DListNode* pos = collectionOfItems->head;
                while (pos != NULL)
                {
                    if (strcmp(pos->data->section->product, ListPeek(tempie)) == 0) break;
                    pos = pos->next;
                }
                if (pos != NULL)
                {
                    forFill = CreateReview();
                    forFill->product = strdup(ListPeek(tempie));
                    ListPop(tempie);
                    forFill->user = strdup(ListPeek(tempie));
                    ListPop(tempie);
                    forFill->describe = tempie;
                    ReviewListPushBack(pos->data->comments, forFill);
                }
                tempie = CreateList();
                str = (char*)malloc(strSize * sizeof(char));
                i = 0;
                continue;
            }
            str = (char*)realloc(str, (i + 1) * sizeof(char));
            ListPushBack(tempie, str);
            str = (char*)malloc(strSize * sizeof(char));
            i = 0;
            continue;
        }
        i++;
        if (i >= strSize)
        {
            strSize *= 2;
            str = (char*)realloc(str, strSize * sizeof(char));
        }
    }
    fclose(fp);
    free(str);
}

#endif // WORKWITHFILE_H_INCLUDED
