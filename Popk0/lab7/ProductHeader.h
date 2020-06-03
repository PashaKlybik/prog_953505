#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Product.h"
#include "windows.h"

ProductList* CreateProductList()
{
    ProductList* tmp = (ProductList*)malloc(sizeof(ProductList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void deleteProductList(ProductList* list)
{
    NoDe* tmp = list->head;
    NoDe* next = NULL;
    while (tmp) {
        next = (NoDe*)tmp->next;
        free(tmp);
        tmp = next;
    }
    free(list);
    (list) = NULL;
}

/*void deleteOneProductItem(ProductList* list, int iD)
{
    NoDe* tmp = list->head;
    NoDe* next = NULL;
    bool find = false;
    while (!find)
    {
        next = (NoDe*)tmp->next;
        if(tmp->value->identifier == iD )
        {
            if(next->value->amount <= 0)
            {
                break;
            }
            find = true;
            tmp->value->amount -= 1;
            tmp = next;
            break;
        }
        tmp = next;
    }
}*/
