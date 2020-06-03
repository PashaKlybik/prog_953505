/*

IDE: CodeBlocks
6.2(6)

    cShop.by. Интернет-магазин занимается реализацией компьютерной
    техники и комплектующих. В каждом разделе существуют
    подразделы и сами товары. Формирование списка товаров по
    запросу пользователя. Доступная информация о товаре: название,
    цена, наличие на складе, описание, гарантия, страна производства и
    т.д. После выбора продукта, он добавляется в корзину и
    вычисляется общая цена покупки. При подтверждении покупки,
    формируется список покупателей: ФИО, контакты, список покупок.
    Отчеты о продажах, общая сумма выручки, история покупок.

*/

#include "ProductHeader.h"
#include "ClientInformationHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

#define refresh 100

int input_check(int check, int n);

int Input_Check(int check);

void pushBack(BuyerInfo* list);

void PrintAdminInfo(BuyerInfo* Client, ProductList* List);

void PrintProduct(ProductList* list, int id);

void PrintNumber(ProductList* list, int number);

int GetPrice(ProductList* list, int number);

int Entry(BuyerInfo* Client, ProductList* List);

int ProductsInput(ProductList* list, FILE* eShop);

int shop(ProductList* List, BuyerInfo* Client);

void ShowBag(ProductList* list, BuyerInfo* Client, int SizeBag);

int Menu(ProductList* List, BuyerInfo* Client);

void DeleteBagItem(BuyerInfo* Client, int num, int SizeBag);

void MinusAmount(ProductList* List, BuyerInfo* Client, int current);

void InFile(ProductList* List, BuyerInfo* Client, FILE* report);

void Report(ProductList* List, BuyerInfo* Client);


void main()
{

    ProductList* List = CreateProductList();
    FILE* eShop;
    eShop = fopen("eShop.txt", "r");
    if (eShop == NULL)
    {
        printf("Error opening file\n");
        exit(4);
    }
    else
    {
        printf("File is open\n");
        while (ProductsInput(List, eShop));
    }
    BuyerInfo* Client = CreateBuyerInfo();
    while (Menu(List, Client));

}

int input_check(int check, int n)
{
    while (1)
    {
        if ((scanf("%d", &check) != 1) || (check > n))
        {
            printf("Invalid input.Try again.\n");
            scanf("%*[^\n]");
        }
        else break;
    }
    return check;
}

int Input_Check(int check)
{
    while (1)
    {
        if ((scanf("%d", &check) != 1))
        {
            printf("Invalid input. Try again.\n");
            scanf("%*[^\n]");
        }
        else break;
    }
    return check;
}

void pushBack(BuyerInfo* list)
{
    Info* info = (Info*)malloc(sizeof(Info));
    Node* client = (Node*)malloc(sizeof(Node));
    client->value = info;
    client->value->SizeBag = 0;
    client->value->Buy = 0;
    if (client == NULL)
    {
        exit(3);
    }
    system("cls");
    printf("Enter your surname: ");
    scanf("%s", client->value->surname);
    system("cls");
    printf("Enter your name: ");
    scanf("%s", client->value->name);
    system("cls");
    printf("Enter your lastname: ");
    scanf("%s", client->value->lastname);
    system("cls");
    printf("Enter your phonenumber: ");
    scanf("%s", client->value->phonenumber);
    system("cls");
    //printf("\n");
    client->next = NULL;
    client->prev = list->tail;
    if (list->tail) {
        list->tail->next = client;
    }
    list->tail = client;

    if (list->head == NULL)
    {
        list->head = client;
    }
    list->size++;
}

void PrintAdminInfo(BuyerInfo* Client, ProductList* List)
{
    int bill = 0;
    int choice = 1;
    int iterator = 1;
    NoDe* Product = List->head;
    Node* client = Client->head;
    if (Client->head == NULL)
    {
        printf("No information available");
    }
    scanf("Buyer list:\n");
    while (client)
    {
        printf("====================");
        printf("%d)\n", iterator);
        printf("Surname: %s\n", client->value->surname);
        printf("Name: %s\n", client->value->name);
        printf("Lastname: %s\n", client->value->lastname);
        printf("Phonenumber: %s\n\n", client->value->phonenumber);
        /*printf("Products purchased: \n");
        for (int i = 0; i < client->value->SizeBag; i++)
        {
            PrintNumber(List, client->value->Bag[i]);
        }
        for (int i = 0; i < client->value->SizeBag; i++)
        {
            bill += GetPrice(List, client->value->Bag[i]);
        }
        printf("Total price: %d\n\n", bill);*/
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        client = ((Node*)client->next);
        Product = ((NoDe*)Product->next);
        iterator++;
    }
    printf("Press 0 to exit\n");
    while (choice)
    {
        choice = input_check(choice, 0);
    }

}

void PrintProduct(ProductList* list, int id)
{
    system("cls");
    int iterator = 1;
    int comparison = 0;
    NoDe* Product = list->head;
    if (list->head == NULL)
    {
        printf("No information available");
    }
    while (Product)
    {
        comparison = Product->value->identifier;
        if (comparison == id)
        {
            printf("================");
            printf("%d)\n", Product->value->number);
            printf("Title: %s\n", Product->value->Name);
            printf("Price(BYN): %d\n", Product->value->price);
            printf("Amount: %d\n", Product->value->amount);
            printf("Guarantee: %s\n", Product->value->guarantee);
            printf("Country of Origin: %s\n", Product->value->country);
        }
        Product = ((NoDe*)Product->next);
    }

}

void PrintNumber(ProductList* list, int number)
{
    int comparison = 0;
    NoDe* Product = list->head;
    if (list->head == NULL)
    {
        printf("No information available");
    }
    while (Product)
    {
        comparison = Product->value->number;
        if (comparison == number)
        {
            printf("================");
            printf("%d)\n", Product->value->number);
            printf("Title: %s\n", Product->value->Name);
            printf("Price(BYN): %d\n", Product->value->price);
            printf("Amount: %d\n", Product->value->amount);
            printf("Guarantee: %s\n", Product->value->guarantee);
            printf("Country of Origin: %s\n", Product->value->country);
            printf("\n");
            break;
        }
        Product = ((NoDe*)Product->next);
    }
}

int GetPrice(ProductList* list, int number)
{
    NoDe* Product = list->head;
    for (int i = 1; i < number; i++)
    {
        Product = ((NoDe*)Product->next);
    }
    return Product->value->price;
}

int Entry(BuyerInfo* Client, ProductList* List)
{
    system("cls");
    int choice = 100;
    while (choice)
    {
        int password = 0;
        printf("1)Buyer\n");
        printf("2)Administrator\n");
        printf("0)Exit\n");
        choice = input_check(choice, 2);
        if (choice == 1)
        {
            return 1;
        }
        else if (choice == 2)
        {
            system("cls");
            printf("Inter password: ");
            password = Input_Check(password);
            if (password == 167457)
            {
                PrintAdminInfo(Client,List);
            }
            else
            {
                printf("Incorrect password");
            }
        }
        else if (choice == 0)
        {
            return 2;
        }
        else
        {
            printf("Wrong choice, try again");
        }
    }
}
void InFile(ProductList* List, BuyerInfo* Client, FILE* report)
{
    int bill = 0;
    int choice = 1;
    NoDe* Product = List->head;
    Node* client = Client->head;
    if (Client->head == NULL)
    {
        printf("No information available");
    }
    scanf("Buyer list:\n");
    while (client)
    {
        fprintf(report, "%s\n", client->value->surname);
        fprintf(report, "%s\n", client->value->name);
        fprintf(report, "%s\n", client->value->lastname);
        fprintf(report, "%s\n", client->value->phonenumber);
        for (int i = 0; i < client->value->SizeBag; i++)
        {
            int comparison = 0, number = 0;
            number = client->value->SizeBag;
            while (Product)
            {
                comparison = Product->value->number;
                if (comparison == number)
                {
                    fprintf(report, "%d\n", Product->value->number);
                    fprintf(report, "%s\n", Product->value->Name);
                    fprintf(report, "%d\n", Product->value->price);
                    fprintf(report, "%d\n", Product->value->amount);
                    fprintf(report, "%s\n", Product->value->guarantee);
                    fprintf(report, "%s\n", Product->value->country);
                    break;
                }
                Product = ((NoDe*)Product->next);
            }
        }
        for (int i = 0; i < client->value->SizeBag; i++)
        {
            bill += GetPrice(List, client->value->Bag[i]);
        }
        fprintf(report, "Total bill %d: ",bill);
        fprintf(report, "\n---------------------------------------------\n");
        client = ((Node*)client->next);
    }
}
void Report(ProductList* List, BuyerInfo* Client)
{
    FILE* report;
    report = fopen("report.txt", "a");
    if (report == NULL)
    {
        printf("Error opening file\n");
        exit(4);
    }
    else
    {
        InFile(List, Client, report);
    }
}

int ProductsInput(ProductList* list, FILE* eShop)
{
    Product_information* information = (Product_information*)malloc(sizeof(Product_information));
    NoDe* catalog = (NoDe*)malloc(sizeof(NoDe));
    catalog->value = information;
    catalog->value->identifier = 0;
    catalog->value->number = 0;
    catalog->value->price = 0;
    catalog->value->amount = 0;
    if (fscanf(eShop, "%d%d%s%d%d%s%s", &catalog->value->identifier, &catalog->value->number, catalog->value->Name,
        &catalog->value->price, &catalog->value->amount, catalog->value->guarantee, catalog->value->country) != EOF)
    {
        catalog->next = NULL;
        catalog->prev = list->tail;
        if (list->tail) {
            list->tail->next = catalog;
        }
        list->tail = catalog;

        if (list->head == NULL)
        {
            list->head = catalog;
        }
        list->size++;
        return 1;
    }
    else return 0;
}

void MinusAmount(ProductList* List, BuyerInfo* Client,int current)
{
    NoDe* Product = List->head;
    Node* client = Client->tail;
    for (int i = 0; i < current-1; i++)
    {
        Product = ((NoDe*)Product->next);
    }
    Product->value->amount = Product->value->amount - 1;
}

int shop(ProductList* List, BuyerInfo* Client)
{
    system("cls");
    NoDe* Product = List->head;
    Node* client = Client->tail;
    int choice = refresh, choice2 = refresh;
    while (choice)
    {
        system("cls");
        //printf("================");
        //printf("\n");
        printf("1) Computer components\n");
        printf("2) Computer peripherals\n");
        printf("3) Show bag\n");
        printf("0) Exit\n");
        choice = input_check(choice, 3);
        if (choice == 1)
        {
            system("cls");
            printf("1) Processors\n");
            printf("2) Video cards\n");
            printf("3) Motherboards\n");
            printf("0) Back\n");
            choice = input_check(choice, 3);
            if (choice == 1)
            {
                PrintProduct(List, 1);
            }
            else if (choice == 2)
            {
                PrintProduct(List, 2);
            }
            else if (choice == 3)
            {
                PrintProduct(List, 3);
            }
            else if (choice == 0)
            {
                shop(List, Client);
            }
        }
        else if (choice == 2)
        {
            system("cls");
            printf("1) Mouse\n");
            printf("2) Headphones\n");
            printf("3) Keyboards\n");
            printf("0) Back\n");
            choice = input_check(choice, 3);
            if (choice == 1)
            {
                PrintProduct(List, 4);
            }
            else if (choice == 2)
            {
                PrintProduct(List, 5);
            }
            else if (choice == 3)
            {
                PrintProduct(List, 6);
            }
            else if (choice == 0)
            {
                shop(List, Client);
            }
        }
        else if (choice == 3)
        {
            ShowBag(List, Client, client->value->SizeBag);
            continue;
        }
        else if (choice == 0)
        {
            if (client->value->Buy == 0)
            {
                popBack(Client);
            }
            else Report(List,Client);
            return 2;
        }
        printf("Enter the appropriate number to add the product to the shopping cart: \n");
        printf(" or Press 0 to back \n");
        //Product->value->amount -= 1;

        while (choice2)
        {
            choice2 = input_check(choice2,30);

            if (choice2 > 0)
            {
                //deleteOneProductItem(Product, choice2);
                if(Product->value->amount <= 0)
                {
                    break;
                }
                else
                {
                client->value->SizeBag = client->value->SizeBag + 1;
                    for (int i = client->value->SizeBag-1; i < client->value->SizeBag; i++)
                        {
                            client->value->Bag[i] = choice2;
                        }
                }

            }
        }
        choice2 = refresh;
    }
}

void DeleteBagItem(BuyerInfo* Client, int num, int SizeBag)
{
    int* del;
    del = (int*)malloc((SizeBag-1) * sizeof(int));
    Node* client = Client->tail;
    for (int i = 0,j=0; i < SizeBag; i++)
    {
        if (client->value->Bag[i] == num)continue;
        del[j] = client->value->Bag[i];
        j++;
    }
    SizeBag--;
    client->value->SizeBag = client->value->SizeBag - 1;
    for (int i = 0; i < SizeBag; i++)
    {
        client->value->Bag[i] = del[i];
    }
}

void ShowBag(ProductList* list, BuyerInfo* Client, int SizeBag)
{
    int bill = 0, selection = 0, number = 0;
    NoDe* Product = list->head;
    Node* client = Client->tail;
    if (SizeBag > 0)
    {
        system("cls");
        printf(" Products in the bag: \n");
        for (int i = 0; i < SizeBag; i++)
        {
            PrintNumber(list, client->value->Bag[i]);
        }
        printf("Total price: \n");
        for (int i = 0; i < SizeBag; i++)
        {
            bill+=GetPrice(list, client->value->Bag[i]);
        }
        printf("%d \n", bill);
        printf("1) Buy\n");
        printf("2) Delete item\n");
        printf("3) Continue shopping\n");
        selection = input_check(selection, 3);
        if (selection == 1)
        {
            client->value->Buy = 1;
            int sb = SizeBag;
            for (int i = 0; i < sb; i++)
            {
                int current = 0;
                current = client->value->Bag[i];
                MinusAmount(list, Client, current);
                DeleteBagItem(Client, i, SizeBag);
            }
        }
        else if (selection == 2)
        {
            printf("Enter the item number you want to delete:");
            number = Input_Check(number);
            DeleteBagItem(Client, number, SizeBag);
        }
    }
    else
    {
        printf("There are no products in your bag \n");
    }
}

int Menu(ProductList* List, BuyerInfo* Client)
{
    system("cls");
    int check;
    check = Entry(Client,List);
    if (check == 1)
    {
        pushBack(Client);
        if (shop(List, Client) == 2)
        {
            return 1;
        }
    }
    else if (check == 2)
    {
        exit(4);
    }
}