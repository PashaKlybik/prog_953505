//IDE: CodeBlocks
//Task 6.2(6)
/*
    cShop.by. Интернет-магазин занимается реализацией компьютерной
    техники и комплектующих. В каждом разделе существуют
    подразделы и сами товары. Формирование списка товаров по
    запросу пользователя. Доступная информация о товаре: название,
    цена, наличие на складе, описание, гарантия, страна производства и
    т.д. После выбора продукта, он добавляется в корзину и
    вычисляется общая цена покупки. При подтверждении покупки,
    формируется список покупателей: ФИО, контакты, список покупок.    
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include "workwithfile.h"

bool IsNumber(char* txt) //проверка введенного выбора на число
{
    int i;
    if (strlen(txt) == 0) return false;
    for (i = 0; i < strlen(txt); i++)
    {
        if (!isdigit(txt[i])) return false;
    }
    return true;
}

int main()
{
    DList* collectionOfItems = CreateDList(); //создание двусвязного динамического списка
    FileReadCatalog(collectionOfItems);    //чтение из файла
    FileReadEquipment(collectionOfItems);  //каталога, оборудования
    FileReadReviews(collectionOfItems);    // и отзывов о технике и запись их в список
    char choice;
    char* t;
    while (true)
    {
        printf("1. Section selection and editing.\n");
        printf("2. Browse section. \n");
        printf("3. Save and exit");
        choice = getche();
        system("cls");
        if (choice == '1')
        {
            puts("Product list:");
            DListNode* temp = collectionOfItems->head;
            int i = 1;
            while (temp != NULL) //
            {
                printf("%d) ", i);
                puts(temp->data->section->product);
                i++;
                temp = temp->next;
            }
            int num = -1;
            printf("Enter section item number: ");
            while (num<1 || num>(collectionOfItems->size)) // выбор самого товара
            {
                t = (char*)malloc(10);
                fgets(t, 5, stdin);
                t[strlen(t) - 1] = '\0';
                if (IsNumber(t))
                {
                    num = atoi(t);
                    if (num >= 1 && num <= collectionOfItems->size)
                    {
                        free(t);
                        break;
                    }
                }
                printf("\nError input: ");
            }
            free(t);
            system("cls");
            DListPrintItem(DListGetNode(collectionOfItems, num - 1)); //вывод на консоль введенного товара
            puts("1. Add a review");
            puts("2. Edit review");
            char r = getch();
            if (r == '1')
            {
                Review* com = CreateReview();
                printf("Adding new comment...\n");
                com->product = strdup(DListGetNode(collectionOfItems, num - 1)->data->section->product);
                char* string = (char*)malloc(100);
                printf("Enter username: ");
                fgets(string, 100, stdin);
                string[strlen(string) - 1] = '\0';
                com->user = strdup(string); //введенному присваиваем имя пользователя
                printf("Enter review describe: ");
                fgets(string, 100, stdin);
                ListPushBack(com->describe, string);
                ReviewListPushBack(DListGetNode(collectionOfItems, num - 1)->data->comments, com);
            }
            else if (r == '2')
            {
                int k = -1, curr = 0;
                printf("Enter comment №: ");
                scanf("%d", &k);
                ReviewListNode* edit = DListGetNode(collectionOfItems, num - 1)->data->comments->head;
                while (edit != NULL && curr != k)
                {
                    edit = edit->next;
                }

                puts("1. Change nickname");
                puts("2. Change review");
                char w = getch();
                char tempN;
                if (w == '1')
                {
                    scanf("%c", &tempN);
                    char* string = (char*)malloc(100);
                    printf("Enter user nickname: ");
                    fgets(string, 100, stdin);
                    string[strlen(string) - 1] = '\0';
                    puts(string);
                    edit->data->user = strdup(string);
                }
                else if (w == '2')
                {
                    char* string = (char*)malloc(100);
                    char litter = scanf("%c", &litter);
                    printf("Enter review message: ");
                    fgets(string, 100, stdin);
                    string[strlen(string) - 1] = '\0';
                    while (edit->data->describe->head != NULL)
                    {
                        ListPop(edit->data->describe);
                    }
                    ListPushBack(edit->data->describe, string);
                }
                else
                {
                    continue;
                }
            }
            getch();
        }
        else if (choice == '2')
        {
            List* tempie = CreateList(); //создание списка для каталога
            DListNode* temp = collectionOfItems->head;
            while (temp != NULL)
            {
                if (tempie->size == 0) ListPushBack(tempie, strdup(temp->data->section->section));
                int counter = 0;
                ListNode* start = tempie->head;
                while (start != NULL)
                {
                    if (strcmp(temp->data->section->section, start->data) == 0) counter++;
                    start = start->next;
                }
                if (counter == 0) ListPushBack(tempie, strdup(temp->data->section->section));
                temp = temp->next;
            }
            puts("Section list:");
            PrintListWithNum(tempie);
            printf("\nChoose one of product: ");
            int productID = 0;
            while (productID<1 || productID>(tempie->size))
            {
                t = (char*)malloc(10);
                fgets(t, 5, stdin);
                t[strlen(t) - 1] = '\0';
                if (IsNumber(t))
                {
                    productID = atoi(t);
                    if (productID >= 1 && productID <= (tempie->size))
                    {
                        free(t);
                        break;
                    }
                }
                printf("\nError input: ");
            }
            free(t);
            temp = collectionOfItems->head;
            List* productTOP = CreateList();
            while (temp != NULL)
            {
                if (strcmp(temp->data->section->section, ListGetNode(tempie, productID - 1)->data) == 0)
                {
                    ListPushBack(productTOP, temp->data->section->product);
                }
                temp = temp->next;
            }
            puts("\nProduct list:");
            PrintListWithNum(productTOP);
            printf("\nChoose one of them: ");
            int ko = 0;
            while (ko<1 || ko>(productTOP->size))
            {
                t = (char*)malloc(10);
                fgets(t, 5, stdin);
                t[strlen(t) - 1] = '\0';
                if (IsNumber(t))
                {
                    ko = atoi(t);
                    if (ko >= 1 && ko <= (productTOP->size))
                    {
                        free(t);
                        break;
                    }
                }
                printf("\nInput error: ");
            }
            temp = collectionOfItems->head;
            while (temp != NULL)
            {
                if (strcmp(temp->data->section->product, ListGetNode(productTOP, ko - 1)->data) == 0) break;
                temp = temp->next;
            }
            system("cls");
            DListPrintItem(temp);
            getch();
        }
        else if (choice == '3') //конечная запись в файл
        {
            FILE* fp = fopen("comma.txt", "w");
            DListNode* temp = collectionOfItems->head;
            while (temp != NULL)
            {
                ReviewListNode* k = temp->data->comments->head;
                while (k != NULL)
                {
                    fputs(k->data->product, fp); fputs("\n", fp);
                    fputs(k->data->user, fp);  fputs("\n", fp);
                    ListNode* w = k->data->describe->head;
                    while (w != NULL)
                    {
                        fputs(w->data, fp); fputs("\n", fp);
                        w = w->next;
                    }
                    fputs("===\n", fp);
                    k = k->next;
                }
                temp = temp->next;
            }
            DeleteDList(collectionOfItems); //очистка памяти
            break;
        }
        system("cls");
    }
    return 0;
}
