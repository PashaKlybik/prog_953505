//Task 5.1.25
/*Разработать функцию, которая инвертирует заданный стек, т.е.
первый элемент становится последним, второй – предпоследним и
т.д.*/

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
