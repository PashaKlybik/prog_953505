#include <iostream>
#include<locale.h>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>


using namespace std;

struct Info
{
	string regNumber;
	string FIO;
	string male;
	string birthday;
	string height;
	string weight;
	string city;
	string interes;
	string badHabits;
	string personalInfo;
};

Info Func()
{
	system("cls");

	printf_s("\t%s\n", "Регистрационный номер");
	printf_s("\t%s\n", "ФИО:");
	printf_s("\t%s\n", "Пол:");
	printf_s("\t%s\n", "День рождения:");
	printf_s("\t%s\n", "Рост:");
	printf_s("\t%s\n", "Вес:");
	printf_s("\t%s\n", "Город:");
	printf_s("\t%s\n", "Хобби: ");
	printf_s("\t%s\n", "Вредные привычки: ");

	string regNumber;
	string FIO;
	string male;
	string birthday;
	string height;
	string weight;
	string city;
	string interes;
	string badHabits;
	string personalInfo;



	char tmp[101];

	scanf_s("%100s", tmp, 101);
	regNumber = tmp;

	scanf_s("%100s", tmp, 101);
	FIO = tmp;

	scanf_s("%100s", tmp, 101);
	male = tmp;

	scanf_s("%100s", tmp, 101);
	birthday = tmp;

	scanf_s("%100s", tmp, 101);
	height = tmp;

	scanf_s("%100s", tmp, 101);
	weight = tmp;

	scanf_s("%100s", tmp, 101);
	city = tmp;

	scanf_s("%100s", tmp, 101);
	interes = tmp;

	scanf_s("%100s", tmp, 101);
	badHabits = tmp;

	scanf_s("%100s", tmp, 101);
	personalInfo = tmp;

	return { regNumber, FIO, male, birthday, height, weight, city, interes, badHabits };
}

void PrintEntry(Info entry)
{
	printf_s("Регистрационный номер:         %s\n", entry.regNumber.c_str());
	printf_s("ФИО:                           %s\n", entry.FIO.c_str());
	printf_s("Пол:                           %s\n", entry.male.c_str());
	printf_s("День рождения:                 %s\n", entry.birthday.c_str());
	printf_s("Рост:                          %s\n", entry.height.c_str());
	printf_s("Вес:                           %s\n", entry.weight.c_str());
	printf_s("Город:                         %s\n", entry.city.c_str());
	printf_s("Интересы:                      %s\n", entry.interes.c_str());
	printf_s("Вредные привычки:              %s\n", entry.badHabits.c_str());

}

void Print(vector<Info> info)
{
	system("cls");
	if (info.size() > 0)
	{
		for (int i = 0; i < info.size(); i++)
		{

			printf_s("\t\t\tЗапись %d\n", i + 1);
			PrintEntry(info[i]);
		}

	}
	else
	{
		printf_s("Error\a");
	}
	_getch();
}

void Menu()
{
	system("cls");

	printf_s(" 1 Вывести информацию\n");
	printf_s(" 2 Добавить запись\n");
	printf_s(" 3 Найти запись\n");
	printf_s(" 4 Сортировка\n");
	printf_s(" 5 Информация о кандидате\n");
	printf_s(" 6 Выход\n");

}

void Sort(vector<Info>& data)
{
	for (unsigned int i = 0; i < data.size(); i++)
	{
		for (unsigned int j = 0; j < data.size() - i - 1; j++)
		{
			if (data[j].FIO.compare(data[j + 1].FIO) > 0) {
				swap(data[j], data[j + 1]);
			}
		}
	}
}

void Edit(Info& entry)
{
	system("cls");

	string regNumber;
	string FIO;
	string male;
	string hobby;
	string weight;
	string city;
	string personalInfo;
	string badHabits;
	string birthday;
	string height;


	printf_s("%s\n", "Регистрационный номер");
	printf_s("%s\n", "Имя:");
	printf_s("%s\n", "Пол:");
	printf_s("%s\n", "День рождения:");
	printf_s("%s\n", "Рост:");
	printf_s("%s\n", "Вес:");
	printf_s("%s\n", "Город:");
	printf_s("%s\n", "Хобби: ");
	printf_s("%s\n", "Вредные привычки: ");



	char tmp[101];

	scanf_s("%100s", tmp, 101);
	regNumber = tmp;

	scanf_s("%100s", tmp, 101);
	FIO = tmp;

	scanf_s("%100s", tmp, 101);
	male = tmp;

	scanf_s("%100s", tmp, 101);
	birthday = tmp;

	scanf_s("%100s", tmp, 101);
	height = tmp;

	scanf_s("%100s", tmp, 101);
	weight = tmp;

	scanf_s("%100s", tmp, 101);
	city = tmp;

	scanf_s("%100s", tmp, 101);
	hobby = tmp;

	scanf_s("%100s", tmp, 101);
	badHabits = tmp;

	scanf_s("%100s", tmp, 101);
	personalInfo = tmp;

	entry.regNumber = regNumber;
	entry.FIO = FIO;
	entry.male = male;
	entry.birthday = birthday;
	entry.height = height;
	entry.weight = weight;
	entry.city = city;
	entry.interes = hobby;
	entry.badHabits = badHabits;
	entry.personalInfo = personalInfo;
}

void Find(vector<Info>& data)
{
	system("cls");

	char tmp[101];
	string number;
	printf_s(": ");
	scanf_s("%100s", tmp, 101);
	number = tmp;

	system("cls");

	vector<int> indexes = vector<int>();
	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data[i].birthday >= number)
		{
			indexes.push_back(i);
		}
	}

	if (!indexes.empty())
	{
		int x;

		for (unsigned int i = 0; i < indexes.size(); i++)
		{

			printf_s("Запись %d\n", indexes[i] + 1);
			PrintEntry(data[indexes[i]]);
		}


		if (indexes.size() > 1)
		{
			do
			{
				printf_s("?: ");
				scanf_s("%d", &x);
				x--;
			} while (find(indexes.begin(), indexes.end(), x) == indexes.end());

		}
		else
		{
			x = indexes[0];
		}


		printf_s("\t 1 -  Создать запись.\n");
		printf_s("\t 2 -  Удалить запись.\n");
		printf_s("\t 3 -  Выход .\n");
		int value_2;
		bool quit = false;
		scanf_s("%d", &value_2);
		while (!quit)
		{
			switch (value_2)
			{
			case 1:
				Edit(data[x]);
				quit = true;
				break;
			case 2:
				data.erase(data.begin() + x);
				quit = true;
				break;
			case 3:

				quit = true;
				break;
			}

		}
	}
	else
	{
		printf_s("Error\a");
		_getch();
	}
}

void GenderInfoDialog(vector<Info>& data)
{
	system("cls");

	char tmp[101];
	string male;
	printf_s("Введите имя: ");
	scanf_s("%100s", tmp, 101);
	male = tmp;

	system("cls");

	vector<int> indexes = vector<int>();
	auto found = vector<Info>();
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].male == male)
		{
			indexes.push_back(i);
			found.push_back(data[i]);
		}
	}

	if (!indexes.empty())
	{
		for (unsigned int i = 0; i < found.size(); i++)
			for (unsigned int j = 0; j < found.size() - i - 1; j++)
			{
				if (found[j].birthday.compare(found[j + 1].birthday) > 0)
				{
					swap(found[j], found[j + 1]);
					swap(indexes[j], indexes[j + 1]);
				}
			}
		for (unsigned int i = 0; i < indexes.size(); i++)
		{
			printf_s("%s", string(120, '=').c_str());
			printf_s("Запись %d\n", indexes[i] + 1);
			PrintEntry(data[indexes[i]]);
		}
		printf_s("%s", string(120, '=').c_str());

		_getch();
	}
	else
	{
		printf_s("Error\a");
		_getch();
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	ifstream input("input.txt");
	ofstream output("output.txt");
	auto info = vector<Info>();

	while (!input.eof())
	{
		string regNumber;
		string FIO;
		string male;
		string birthday;
		string height;
		string weight;
		string city;
		string interes;
		string badHabits;

		getline(input, regNumber);
		getline(input, FIO);
		getline(input, male);
		getline(input, birthday);
		getline(input, height);
		getline(input, weight);
		getline(input, city);
		getline(input, interes);
		getline(input, badHabits);
		Info entry = { regNumber, FIO, male, birthday, height, weight, city, interes, badHabits };
		info.push_back(entry);
	}
	int value;
	bool num = false;
	while (!num)
	{
		Menu();
		scanf_s("%d", &value);
		switch (value)
		{
		case 1:
			Print(info);
			break;
		case 2:
			info.push_back(Func());
			break;
		case 3:
			Sort(info);
			break;
		case 4:
			GenderInfoDialog(info);
			break;
		case 5:

			Find(info);
			break;
		case 6:
			num = true;
			break;
		}
		system("pause");
	}

	for (unsigned int i = 0; i < info.size(); i++)
	{
		output << info[i].regNumber << endl;
		output << info[i].FIO << endl;
		output << info[i].male << endl;
		output << info[i].birthday << endl;
		output << info[i].height << endl;
		output << info[i].weight << endl;
		output << info[i].city << endl;
		output << info[i].interes << endl;
		output << info[i].badHabits << endl;

		if (i < info.size() - 1)
		{
			output << endl;
		}
	}


	input.close();
	output.close();

	return 0;
}