#ifndef REVIEWLIST_H_INCLUDED
#define REVIEWLIST_H_INCLUDED

#include "review.h"

typedef struct reviewlistnode
{
    struct ReviewListNode* next;
    Review* data;
} ReviewListNode;

typedef struct reviewlist
{
    ReviewListNode* head;
    ReviewListNode* tail;
    int size;
} ReviewList;

ReviewList* CreateReviewList()
{
    ReviewList* lst = malloc(sizeof(ReviewList));
    lst->head = lst->tail = NULL;
    lst->size = 0;
    return lst;
}

void ReviewListPop(ReviewList* lst)
{
    if (lst->size == 0) return;
    ReviewListNode* temp = lst->head;
    lst->size--;
    lst->head = temp->next;
    DeleteReview(temp->data);
    free(temp);
    if (lst->size == 0)
    {
        lst->head = lst->tail = NULL;
    }
}

void DeleteReviewList(ReviewList* lst)
{
    while (lst->head != NULL)
    {
        ReviewListPop(lst);
    }
}

void ReviewListPushBack(ReviewList* lst, Review* data)
{
    ReviewListNode* temp = malloc(sizeof(ReviewListNode));
    temp->data = data;
    if (lst->tail != NULL)
    {
        lst->tail->next = temp;
    }
    else
    {
        lst->head = temp;
    }
    lst->tail = temp;
    lst->tail->next = NULL;
    lst->size++;
}

ReviewListNode* ReviewListGetNode(ReviewList* lst, int index)
{
    ReviewListNode* temp;
    int i = 0;
    temp = lst->head;
    while (temp != NULL && i < index)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}

void ReviewListPrint(ReviewList* lst)
{
    ReviewListNode* temp = lst->head;
    int i = 1;
    while (temp != NULL)
    {
        printf("#%d ", i++); fputs(temp->data->user, stdout); puts(":\n");
        ListPrint(temp->data->describe);
        puts("\n");
        temp = temp->next;
    }
}

#endif // REVIEWLIST_H_INCLUDED
