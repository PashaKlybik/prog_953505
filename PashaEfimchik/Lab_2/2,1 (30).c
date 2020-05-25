//IDE: VisualStudio
//Task 2.1(30)
/*
Натуральное число. 
Разработать программу, меню которой позволяет выполнить следующие функции: 
1. Ввод натурального числа. 
2. Вывод значения числа в десятичной, восьмеричной и шестнадцатеричной форме.  
3. Вывод обратного к нему числа в десятичной форме. 
4. Перевод числа в систему счисления, с основанием n [2..16]. 
5. Информация о версии и авторе программы. 
6. Выход из программы. 
Замечание: для перевода числа в системы с другим основанием разработать собственные функции.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void obratnoe(int f, int* mas, char* base, int s)
{
	int i = 0;
	while (f != 0)
	{
		mas[i] = f % s;
		i++;
		f /= s;
	}
	for (i--; i >= 0; i--)
	{
		s = mas[i];
		printf("%c", base[s]);
	}

}

void add(int f, int* mas, char* base, int s)
{
	int i = 0;
	while (f != 0)
	{
		mas[i] = f % s;
		i++;
		f /= s;
	}
	for (i--; i >= 0; i--)
	{
		s = mas[i];
		printf("%c", base[s]);
	}
}

int main()
{
	char base[] = {
		'0','1','2','3','4','5','6','7','8','9',
		'A','B','C','D','E','F' };
	int mas[64];
	int s = 0, des = 0;
	printf("Enter 10-e chislo: ");
	scanf_s("%d", &des);
	printf("\n10-ya system: %d", des);
	printf("\n8-ya system: ");
	add(des, mas, base, 8);
	printf("\n16-ya system: ");
	add(des, mas, base, 16);
	printf("\n\nSelect number system: ");
	scanf_s("%d", &s);
	printf("\nCalculation system - %d (%d): ", s, des);
	add(des, mas, base, s);
	printf("\nExist obratnoe chislo - (%d) : ", des);
	obratnoe(des, mas, base, s);
	printf("\n\n");

	return 0;
}
