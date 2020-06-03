#include <stdlib.h>
#include "windows.h"

#define Size 10

typedef struct _Product_information
{
    int identifier;
    int number;
    char Name[Size];
    int price;
    int amount;
    char guarantee[Size];
    char country[Size];
}Product_information;


typedef struct NoDe
{
    Product_information* value;
    void* next;
    void* prev;
}NoDe;

typedef struct _ProductList
{
    size_t size;
    NoDe* head;
    NoDe* tail;
}ProductList;


ProductList* CreateProductList();

void deleteProductList(ProductList* list);
void deleteOneProductItem(ProductList* list, int iD);


