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

	printf_s("\t%s\n", "Reg number");
	printf_s("\t%s\n", "Fio:");
	printf_s("\t%s\n", "Male:");
	printf_s("\t%s\n", "Birhtday:");
	printf_s("\t%s\n", "height:");
	printf_s("\t%s\n", "weight:");
	printf_s("\t%s\n", "city:");
	printf_s("\t%s\n", "interes: ");
	printf_s("\t%s\n", "Bad habbits: ");

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
	printf_s("Reg number:         %s\n", entry.regNumber.c_str());
	printf_s("FIO:                           %s\n", entry.FIO.c_str());
	printf_s("Male:                           %s\n", entry.male.c_str());
	printf_s("Birhday:                 %s\n", entry.birthday.c_str());
	printf_s("Height:                          %s\n", entry.height.c_str());
	printf_s("Weight:                           %s\n", entry.weight.c_str());
	printf_s("City:                         %s\n", entry.city.c_str());
	printf_s("Interes:                      %s\n", entry.interes.c_str());
	printf_s("Bad Habbits:              %s\n", entry.badHabits.c_str());

}

void Print(vector<Info> info)
{
	system("cls");
	if (info.size() > 0)
	{
		for (int i = 0; i < info.size(); i++)
		{

			printf_s("\t\t\tRecord %d\n", i + 1);
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

	printf_s(" 1 Print information\n");
	printf_s(" 2 Add Record\n");
	printf_s(" 3 Find Record\n");
	printf_s(" 4 Sort\n");
	printf_s(" 5 Information\n");
	printf_s(" 6 Exit\n");

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
	string interes;
	string weight;
	string city;
	string badHabits;
	string birthday;
	string height;


	printf_s("\t%s\n", "Reg number");
	printf_s("\t%s\n", "Fio:");
	printf_s("\t%s\n", "Male:");
	printf_s("\t%s\n", "Birhtday:");
	printf_s("\t%s\n", "height:");
	printf_s("\t%s\n", "weight:");
	printf_s("\t%s\n", "city:");
	printf_s("\t%s\n", "interes: ");
	printf_s("\t%s\n", "Bad habbits: ");



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

			printf_s("Record %d\n", indexes[i] + 1);
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


		printf_s("\t 1 -  Edit.\n");
		printf_s("\t 2 -  Delete.\n");
		printf_s("\t 3 -  Exit .\n");
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
	printf_s("Enter name: ");
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
			printf_s("Record %d\n", indexes[i] + 1);
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