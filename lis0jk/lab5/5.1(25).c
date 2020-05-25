//Task 5.1.25
/*Разработать функцию, которая инвертирует заданный стек, т.е.
первый элемент становится последним, второй – предпоследним и
т.д*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int const stackSize = 100;

struct stack
{
    float elem[stackSize];
    int top;
};

void init(struct stack* stk)
{
    stk->top = 0;
}

void push(struct stack* stk, float f)
{
    if (stk->top < stackSize) 
    {
        stk->elem[stk->top] = f;
        stk->top++;
    }
    else printf("Stack is full, quantity of elements is: %d !\n", stk->top);
}

int getcount(struct stack* stk)
{
    return stk->top;
}

void inverce(struct stack* stk, int size)
{
    struct stack* dummyStk;
    dummyStk = (struct stack*)malloc(sizeof(struct stack));
    init(dummyStk);
    for (int i = size - 1, j = 0; i >= 0, j < size; i--, j++)
    {
        if ((stk->top) > 0)
        {
            stk->top--;
            dummyStk->elem[j] = stk->elem[i];
            dummyStk->top++;
        }
    }
    for (int i = size - 1; i >= 0; i--)
    {
        if ((dummyStk->top) > 0)
        {
            dummyStk->top--;
            stk->elem[i] = dummyStk->elem[i];
            stk->top++;
        }
    }
}

int main()
{
    struct stack* stk;
    int i, n;
    float elem;
    stk = (struct stack*)malloc(sizeof(struct stack));
    init(stk);
    do {
        printf("Enter quantity of elements in stack: ");
        scanf_s("%d", &n);
        if (n <= 100 && n > 0)  break;        
        else printf("Wrong value!\n");        
    } while (true);
    for (i = 0; i < n; i++)
    {
        do {
            printf("Enter element number %d:", i);
            scanf_s("%f", &elem);
            if (elem > -2147483647 && elem < 2147483648) break;           
        } while (true);
        push(stk, elem);
    }
    printf("It is %d elements in stack\n\n", getcount(stk));
    int j = stk->top;
    printf("Before inverce: \n");
    {
        do {
            j--;
            printf("%f\n", stk->elem[j]);
        } while (j > 0);
    }
    inverce(stk, n);
    printf("After inverce: \n");
    {
        j = stk->top;
        do {
            j--;
            printf("%f\n", stk->elem[j]);
        } while (j > 0);
    }
    return 0;
}

#include <string.h>
#include <stdio.h>
using namespace std;

struct Stack
{
    static const int MAX = 100;
    char str[MAX];

    void push()
    {
        printf("Inter a string \n");
        gets_s(str);
    }

    void pop()
    {
        int size = strlen(str);
        for (int i = size; i >= 0; i--)
            printf("%c", str[i]);
        printf("\n");
    }
};

int main()
{
    Stack s1;
    s1.push();
    s1.pop();
}
