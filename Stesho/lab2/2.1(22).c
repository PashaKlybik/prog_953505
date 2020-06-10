//Task 2.1(22)
/*
Разработать программу, которая позволяет определить
совместимость двух партнеров по гороскопу. Меню программы
должно содержать следующие пункты:
1 Ввод данных первого партнера (число и месяц рождения, пол).
2 Ввод данных второго партнера (число и месяц рождения, пол).
3 Определение знака зодиака каждого партнера.
4 Решение, возможна ли между партнерами дружба.
5 Решение, подходят ли они друг другу в бизнесе.
6 Решение, смогут ли они жить в браке.
7 Информация о версии и авторе программы.
8 Выход из программы.
Справка. Астрологи полагают, что партнеры могут дружить, если
их знаки зодиака принадлежат одной стихии (воздуха, огня, воды
или земли). Партнеры подходят друг для друга в бизнесе, если
имеют один знак зодиака либо смежные знаки. Партнеры имеют
предпосылки для гармоничной семейной жизни, если они разного
пола и их знаки зодиака принадлежат 1) стихиям воздуха и воды
или 2) огня и земли.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <Math.h>
struct Person
{
	int day;
	int month;
	int sign;
	int element;
	char gender;
};
void flush(void);
char InpChar(char str[]);
int InpInt(char str[]);
int YourSign(int day, int month);
int YourElement(int sign);
void Input(struct Person* partner);
int main()
{
	setlocale(LC_ALL, "Rus");
	struct Person partner1, partner2;
	printf("Первый партнер:\n");
	Input(&partner1);
	printf("Day = %d Month = %d Gender = %c Sign = %d Element = %d\n", partner1.day, partner1.month, partner1.gender, partner1.sign, partner1.element);
	printf("\nВторой партнер:\n");
	Input(&partner2);
	printf("Day = %d Month = %d Gender = %c Sign = %d Element = %d\n", partner2.day, partner2.month, partner2.gender, partner2.sign, partner2.element);
	while (1)
	{
		int choice;
		printf("\n1.Ввод данных первого партнера\n2.Ввод данных второго партнера\n3.Совместимость в дружбе\n4.Совместимость в бизнесе\n5.Совместимость в бракe\n6.Информация об авторе\n7.Выход\nВыберите действие:");
		scanf_s("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case 7:
			return 0;
		case 1:
			Input(&partner1);
			break;
		case 2:
			Input(&partner2);
			break;
		case 3:
			if (partner1.element == partner2.element)
				printf("Хорошие друзья\n");
			else
				printf("Плохие друзья\n");
			break;
		case 4:
			if ((partner1.sign == partner2.sign) || (fabs(partner1.sign - partner2.sign) == 1) || (partner1.sign + partner2.sign == 13))
				printf("Отличные партнеры\n");
			else
				printf("Не стоит сотрудничать\n");
			break;
		case 5:
			printf("\nX = %f\n", fabs(partner1.element - partner2.element));
			if ((partner1.gender != partner2.gender) && (fabs(partner1.element - partner2.element) == 1))
				printf("Хороший брак\n");
			else
				printf("Плохой брак\n");
			break;
		case 6:
			printf("Выполнил Стешенко Дмитрий\n");
		}
	}
}

void flush(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

char InpChar(char str[])
{
	char ch;
	do
	{
		printf("%s", str);
		scanf_s("%c", &ch);
		flush();
		if (ch != 'w' && ch != 'm')
		{
			printf("Неверный ввод\n");
		}
		else
			return ch;
	} while (ch != 'w' && ch != 'm');
}

int InpInt(char str[])
{
	int res, x;
	do
	{
		printf("%s", str);
		res = scanf_s("%d", &x);
		flush();
		if (res == 1)
		{
			return x;
		}
		else
		{
			printf("Неверный ввод\n");
		}
	} while (res != 1);
	return 0;
}

int YourSign(int day, int month)
{
	if ((day >= 21 && day <= 31 && month == 1) || (day >= 1 && day <= 19 && month == 2))
	{
		printf("Водолей\n");
		return 1;
	}
	if ((day >= 20 && day <= 31 && month == 2) || (day >= 1 && day <= 20 && month == 3))
	{
		printf("Рыбы\n");
		return 2;
	}
	if ((day >= 21 && day <= 31 && month == 3) || (day >= 1 && day <= 20 && month == 4))
	{
		printf("Овен\n");
		return 3;
	}
	if ((day >= 21 && day <= 31 && month == 4) || (day >= 1 && day <= 21 && month == 5))
	{
		printf("Телец\n");
		return 4;
	}
	if ((day >= 22 && day <= 31 && month == 5) || (day >= 1 && day <= 21 && month == 6))
	{
		printf("Близнецы\n");
		return 5;
	}
	if ((day >= 22 && day <= 31 && month == 6) || (day >= 1 && day <= 22 && month == 7))
	{
		printf("Рак\n");
		return 6;
	}
	if ((day >= 23 && day <= 31 && month == 7) || (day >= 1 && day <= 23 && month == 8))
	{
		printf("Лев\n");
		return 7;
	}
	if ((day >= 24 && day <= 31 && month == 8) || (day >= 1 && day <= 23 && month == 9))
	{
		printf("Дева\n");
		return 8;
	}
	if ((day >= 24 && day <= 31 && month == 9) || (day >= 1 && day <= 23 && month == 10))
	{
		printf("Весы\n");
		return 9;
	}
	if ((day >= 24 && day <= 31 && month == 10) || (day >= 1 && day <= 22 && month == 11))
	{
		printf("Скорпион\n");
		return 10;
	}
	if ((day >= 23 && day <= 31 && month == 11) || (day >= 1 && day <= 22 && month == 12))
	{
		printf("Стрелец\n");
		return 11;
	}
	if ((day >= 23 && day <= 31 && month == 12) || (day >= 1 && day <= 20 && month == 1))
	{
		printf("Козерог\n");
		return 12;
	}
	return 0;
}

int YourElement(int sign)
{
	if (sign == 3 || sign == 7 || sign == 11)
		return 1;
	if (sign == 4 || sign == 8 || sign == 12)
		return 2;
	if (sign == 1 || sign == 5 || sign == 9)
		return 3;
	if (sign == 2 || sign == 6 || sign == 10)
		return 4;
}

void Input(struct Person* partner)
{
	do
	{
		partner->day = InpInt("День рождения = ");
		if (partner->day < 1 || partner->day > 31)
		{
			printf("Неверный ввод\n");
		}
	} while (partner->day < 1 || partner->day > 31);
	do
	{
		partner->month = InpInt("Месяц рождения = ");
		if (partner->month < 1 || partner->month > 12)
		{
			printf("Неверный ввод\n");
		}
	} while (partner->month < 1 || partner->month > 12);
	partner->gender = InpChar("Ваш пол(m/w) = ");
	partner->sign = YourSign(partner->day, partner->month);
	partner->element = YourElement(partner->sign);
}
