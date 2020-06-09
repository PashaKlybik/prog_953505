//IDE: Visual Studio
//Task 6.2(25)
/*
Брачное агентство. База потенциальных женихов и невест: регистрационный номер, ФИО,
пол, дата рождения, рост и вес, город, интересы, вредные привычки, информация о себе,
требования к партнеру. Поиск подходящих вариантов по запросу, подготовка 
встреч (формирование приглашения для знакомства). Автоматизированный поиск взаимоприемлемых
вариантов. Перенос в архив пар, решивших свои семейные проблемы, 
удаление клиентов, отказавшихся от услуг.
*/


#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <locale.h>
#include <stdio.h> 
#define N 103

struct Date {
	int day;
	int month;
	int year;
};

struct FIO {
	char last_name[20];
	char name[20];
	char middle_name[20];
	char city[20];
	Date A;
};

struct INFO {
	char interests[20];
	char bad_habits[20];
	char pers_info[20];
	int reqHeight;
	int regWeight;
};
struct ADD {
	int id = 0;
	FIO B;
	int weight;
	int height;
	INFO f;
}; ADD T[N], Q[N];


ADD m, n, q, p;

int hesh(int key) { return key % N; }

void aDD1(ADD g)
{
	int j = 0;
	int i = hesh(g.id);
	while (T[i].id != 0 && j < N)
	{
		i = hesh(i + 1);
		j++;
	}
	T[i] = g;
}

void aDD2(ADD n)
{
	int j = 0;
	int i = hesh(n.id);
	while (Q[i].id != 0 && j < N)
	{
		i = hesh(i + 1);
		j++;
	}
	Q[i] = n;
}

void forms()
{
	FILE* k3;
	k3 = fopen("D:\\1\\k3.txt", "r");
	ADD x;
	while (fscanf(k3, "%d %s %s %s %d %d %d %d %d %s %s %s %s %d %d", x.id, x.B.last_name, x.B.name, x.B.middle_name, x.B.A.day, x.B.A.month, x.B.A.year, x.height,
		x.weight, x.B.city, x.f.interests, x.f.bad_habits, x.f.pers_info, x.f.reqHeight, x.f.regWeight))
		aDD1(x);
	ADD z;
	while (fscanf(k3, "%d %s %s %s %d %d %d %d %d %s %s %s %s %d %d", z.id, z.B.last_name, z.B.name, z.B.middle_name, z.B.A.day, z.B.A.month, z.B.A.year, z.height,
		z.weight, z.B.city, z.f.interests, z.f.bad_habits, z.f.pers_info, z.f.reqHeight, z.f.regWeight))
		aDD2(z);
	fclose(k3);
}

void output()
{
	for (int i = 0; i < N; i++)
	{
		if (T[i].id != 0)
		{
			printf("\nid: %d\nПол: Мужской\nФИО: %s %s %s\n", T[i].id, T[i].B.last_name, T[i].B.name, T[i].B.middle_name);
			printf("Дата рождения: %d.%d.%d\nРост: %d см\nВес: %d кг", T[i].B.A.day, T[i].B.A.month, T[i].B.A.year, T[i].height, T[i].weight);
			printf("\nГород: %s\nИнтересы: %s\nВредные привычки: %s", T[i].B.city, T[i].f.interests, T[i].f.bad_habits);
			printf("\nИнформация о себе: %s\nТребования к партнеру(рост/вес): %d / %d\n\n", T[i].f.pers_info, T[i].f.reqHeight, T[i].f.regWeight);
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (Q[i].id != 0)
		{
			printf("\nid: %d\nПол: Женский\nФИО: %s %s %s\n", Q[i].id, Q[i].B.last_name, Q[i].B.name, Q[i].B.middle_name);
			printf("Дата рождения: %d.%d.%d\nРост: %d см\nВес: %d кг", Q[i].B.A.day, Q[i].B.A.month, Q[i].B.A.year, Q[i].height, Q[i].weight);
			printf("\nГород: %s\nИнтересы: %s\nВредные привычки: %s", Q[i].B.city, Q[i].f.interests, Q[i].f.bad_habits);
			printf("\nИнформация о себе: %s\nТребования к партнеру(рост/вес): %d / %d\n\n", Q[i].f.pers_info, Q[i].f.reqHeight, Q[i].f.regWeight);
		}
	}
}

int searchMen(int p)
{
	int j = 0, i = hesh(p);
	while (j++ < N && T[i].id)
	{
		if (T[i].id == p)
			return i;
		i = hesh(i + 1);
	}
	return -1;
}

int searchWoman(int p)
{
	int j = 0, i = hesh(p);
	while (j++ < N && Q[i].id)
	{
		if (Q[i].id == p)
			return i;
		i = hesh(i + 1);
	}
	return -1;
}

void delp(ADD g)
{
	int i = hesh(g.id);
	if (searchMen)
		T[i].id = NULL;
}

void deld(ADD p)
{
	int i = hesh(p.id);
	if (searchWoman)
		Q[i].id = NULL;
}

void input_men()
{
	printf("\nВведите id: ");
	while (scanf_s("%d", &m.id))
	{
		printf("\nВведите Фамилию: ");
		scanf("%s", &m.B.last_name);
		printf("\nВведите Имя: ");
		scanf("%s", &m.B.name);
		printf("\nВведите Отчество: ");
		scanf("%s", &m.B.middle_name);
		printf("\nВведите дату рождения: \nДень: ");
		scanf("%d", &m.B.A.day);
		printf("\nМесяц: ");
		scanf("%d", &m.B.A.month);
		printf("\nГод: ");
		scanf("%d", &m.B.A.year);
		printf("\nРост(см): ");
		scanf("%d", &m.height);
		printf("\nВес(кг): ");
		scanf("%d", &m.weight);
		printf("\nГород: ");
		scanf("%s", &m.B.city);
		printf("\nИнтересы: ");
		scanf("%s", &m.f.interests);
		printf("\nВредные привычки: ");
		scanf("%s", &m.f.bad_habits);
		printf("\nИнформация о себе: ");
		scanf("%s", &m.f.pers_info);
		printf("\nТребования к партнеру: \nРост - ");
		scanf("%d", &m.f.reqHeight);
		printf("\nВес - ");
		scanf("%d", &m.f.regWeight);
		printf("\n");
		int i = searchMen(m.id);
		if (i == -1)
			T[i] = m;
		aDD1(m);
		break;
	}
}

void input_woman()
{
	printf("\nВведите id: ");
	while (scanf_s("%d", &q.id))
	{
		printf("\nВведите Фамилию: ");
		scanf("%s", &q.B.last_name);
		printf("\nВведите Имя: ");
		scanf("%s", &q.B.name);
		printf("\nВведите Отчество: ");
		scanf("%s", &q.B.middle_name);
		printf("\nВведите дату рождения: \nДень: ");
		scanf("%d", &q.B.A.day);
		printf("\nМесяц: ");
		scanf("%d", &q.B.A.month);
		printf("\nГод: ");
		scanf("%d", &q.B.A.year);
		printf("\nРост(см): ");
		scanf("%d", &q.height);
		printf("\nВес(кг): ");
		scanf("%d", &q.weight);
		printf("\nГород: ");
		scanf("%s", &q.B.city);
		printf("\nИнтересы: ");
		scanf("%s", &q.f.interests);
		printf("\nВредные привычки: ");
		scanf("%s", &q.f.bad_habits);
		printf("\nИнформация о себе: ");
		scanf("%s", &q.f.pers_info);
		printf("\nТребования к партнеру: \nРост - ");
		scanf("%d", &q.f.reqHeight);
		printf("\nВес - ");
		scanf("%d", &q.f.regWeight);
		printf("\n");
		int i = searchWoman(q.id);
		if (i == -1)
			Q[i] = q;
		aDD2(q);
		break;
	}
}

void Fill()
{
	FILE* k3;
	k3 = fopen("D:\\1\\k3.txt", "ab");
	if (m.id != 0)
	{
		fprintf(k3, "\nid: %d\nПол: мужской\nФИО: %s %s %s", m.id, m.B.last_name, m.B.name, m.B.middle_name);
		fprintf(k3, "\nДата рождения: %d.%d.%d\nРост: %dсм\nВес: %dкг", m.B.A.day, m.B.A.month, m.B.A.year, m.height, m.weight);
		fprintf(k3, "\nГород: %s\nИнтересы: %s\nВредные привычки: %s\nИнформация о себе: %s", m.B.city, m.f.interests, m.f.bad_habits, m.f.pers_info);
		fprintf(k3, "\nТребования к партнеру(рост / вес): %d / %d\n", m.f.reqHeight, m.f.regWeight);
	}
	if (q.id != 0)
	{
		fprintf(k3, "\nid: %d\nПол: мужской\nФИО: %s %s %s", q.id, q.B.last_name, q.B.name, q.B.middle_name);
		fprintf(k3, "\nДата рождения: %d.%d.%d\nРост: %dсм\nВес: %dкг", q.B.A.day, q.B.A.month, q.B.A.year, q.height, q.weight);
		fprintf(k3, "\nГород: %s\nИнтересы: %s\nВредные привычки: %s\nИнформация о себе: %s", q.B.city, q.f.interests, q.f.bad_habits, q.f.pers_info);
		fprintf(k3, "\nТребования к партнеру(рост / вес): %d / %d\n", q.f.reqHeight, q.f.regWeight);
	}
	fclose(k3);
}

void FuncSearch()
{
	int z, k, x, f, l;
	printf("\n1.Поиск мужчин\n2.Поиск девушек\nВыберите:");
	scanf_s("%d", &l);
	if (l == 1)
	{
		for (int i = 0; i < 1; i++)
		{
			printf("\nВведите id для поиска: ");
			scanf_s("%d", &z);
			k = searchMen(z);
			if (k == -1)
				printf("Не найден.");
			else
			{
				printf("\nid: %d\nПол: Женский\nФИО: %s %s %s\n", T[k].id, T[k].B.last_name, T[k].B.name, T[k].B.middle_name);
				printf("Дата рождения: %d.%d.%d\nРост: %d см\nВес: %d кг", T[k].B.A.day, T[k].B.A.month, T[k].B.A.year, T[k].height, T[k].weight);
				printf("\nГород: %s\nИнтересы: %s\nВредные привычки: %s", T[k].B.city, T[k].f.interests, T[k].f.bad_habits);
				printf("\nИнформация о себе: %s\nТребования к партнеру(рост/вес): %d / %d\n\n", T[k].f.pers_info, T[k].f.reqHeight, T[k].f.regWeight);

			}
		}
	}
	else if (l == 2)
	{
		for (int i = 0; i < 1; i++)
		{
			printf("\nВведите id для поиска: ");
			scanf_s("%d", &x);
			f = searchWoman(x);
			if (f == -1)
				printf("Не найден.");
			else
			{
				printf("\nid: %d\nПол: Женский\nФИО: %s %s %s\n", Q[f].id, Q[f].B.last_name, Q[f].B.name, Q[f].B.middle_name);
				printf("Дата рождения: %d.%d.%d\nРост: %d см\nВес: %d кг", Q[f].B.A.day, Q[f].B.A.month, Q[f].B.A.year, Q[f].height, Q[f].weight);
				printf("\nГород: %s\nИнтересы: %s\nВредные привычки: %s", Q[f].B.city, Q[f].f.interests, Q[f].f.bad_habits);
				printf("\nИнформация о себе: %s\nТребования к партнеру(рост/вес): %d / %d\n\n", Q[f].f.pers_info, Q[f].f.reqHeight, Q[f].f.regWeight);
			}
		}
	}
}


void FuncSort()
{
	ADD p, q;
	FILE* F;
	F = fopen("D:\\1\\k4.txt", "a");
	int i = hesh(p.id);
	int k = hesh(q.id);
	if (searchMen)
	{
		if (searchWoman)
		{
			if (T[i].height >= Q[k].f.reqHeight - 10 || T[i].height <= Q[k].f.reqHeight + 10 &&
				T[i].B.city == Q[k].B.city && T[i].weight >= Q[k].f.regWeight - 10 || T[i].weight <= Q[k].f.regWeight + 10 &&
				T[i].f.interests == Q[k].f.interests && T[i].weight >= Q[k].f.regWeight - 10 || T[i].weight <= Q[k].f.regWeight + 10 &&
				T[i].f.interests == Q[k].f.interests && T[i].B.A.year >= Q[k].B.A.year - 10 || T[i].B.A.year <= Q[k].B.A.year + 10)
			{
				fprintf(F, "\nДля %s %s %s", T[i].B.last_name, T[i].B.name, T[i].B.middle_name);
				fprintf(F, "идеальная пара с %s %s %s", Q[k].B.last_name, Q[k].B.name, Q[k].B.middle_name);
				printf("\nДля %s %s %s идеальная пара с %s %s %s", T[i].B.last_name, T[i].B.name, T[i].B.middle_name, Q[k].B.last_name, Q[k].B.name, Q[k].B.middle_name);
			}
			else
				printf("Нет подходящих вариантов");
		}
	}
	fclose(F);
}

void FuncDelete()
{
	int a;
	printf("\n1.Удалить данные мужчины\n2.Удалить данные девушки\nВыберите");
	scanf_s("%d", &a);
	if (a == 1)
	{
		for (int i = 0; i < 1; i++)
		{
			printf("\nВведите id для удаления: ");
			scanf_s("%d", &n.id);
			delp(n);
		}
	}
	else if (a == 2)
	{
		for (int i = 0; i < 1; i++)
		{
			printf("\nВведите id для удаления: ");
			scanf_s("%d", &p.id);
			deld(p);
		}
	}
}

void input()
{
	int k;
	printf("1.Мужчина\n2.Девушка\nВыберите: ");
	scanf_s("%d", &k);
	if (k == 1)
	{
		input_men();
		Fill();
	}
	else if (k == 2)
	{
		input_woman();
		Fill();
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	forms();
	output();
	int a;
	bool flag = 0;
	while (flag == 0)
	{
		printf("----//MENU\\----");
		printf("\n1.Добавление данных\n2.Просмотр данных\n3.Поиск\n4.Поиск подходящих по запросу\n5.Удаление данных\n6.Выход\nВыберите: ");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			FuncSearch();
			break;
		case 4:
			FuncSort();
			break;
		case 5:
			FuncDelete();
			break;
		case 6:
			flag = 1;
		}
	}
	return 0;
}
