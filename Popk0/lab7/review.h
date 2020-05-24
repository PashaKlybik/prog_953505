#ifndef REVIEW_H_INCLUDED
#define REVIEW_H_INCLUDED

#include "costlist.h"

typedef struct review
{
    char* product;
    char* user;
    List* describe;
} Review;

Review* CreateReview()
{
    Review* temp = (Review*)malloc(sizeof(Review));
    temp->describe = CreateList();
    return temp;
}

void DeleteReview(Review* temp)
{
    DeleteList(temp->describe);
    free(temp->user);
    free(temp->product);
    free(temp);
}

#endif // REVIEW_H_INCLUDED
