﻿// 4.1(22).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*Часто встречающиеся ошибки начинающих наборщиков – дважды
записанное слово и слово, записанное со строчной буквы после
точки.Обнаружить и исправить такие ошибки во введенном
многострочном тексте.*/

#include <stdio.h>
#include <string.h>
int your_strcmp(char const* first, char const* second)
{
	for (; *first && *second; ++first, ++second)
	{
		if (*first < *second)
		{
			return -1;
		}
		if (*second < *first)
		{
			return 1;
		}
	}
	if (*first)
	{
		return 1;
	}
	if (*second)
	{
		return -1;
	}
	return 0;
}
int main(void)
{
	char buf[256], result[256], * word1, * word2;
	char balf[24] = { 'A' ,'B', 'C', 'D', 'E', 'F', 'G' ,'H' ,'I' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'V' ,'X' ,'Y' ,'Z' ,'\0' };
	char malf[24] = { 'a' ,'b', 'c', 'd', 'e', 'f', 'g' ,'h' ,'i' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'v' ,'x' ,'y' ,'z' ,'\0' };
	char seps[] = " \t";
	int i = 0;
	printf("Enter your string:\n");
	gets(buf);
	*result = 0;
	word1 = "";
	char* next_word = NULL;
	word2 = strtok_s(buf, seps, &next_word);
	//2 раза записанное слово
	while (word2)
	{
		if (your_strcmp(word1, word2))
		{
			strcat_s(result, 256, word2);
			strcat_s(result, 256, " ");
		}
		word1 = word2;
		word2 = strtok_s(NULL, seps, &next_word);
	}
	//замена строчных букв
	while (result[i] != '\0')
	{
		if (result[i] == '.')
		{
			if (result[i + 1] == ' ')
			{
				while (result[i + 1] == ' ')
				{
					i++;
				}
				for (int j = 0; j < 25; j++)
				{
					if (result[i + 1] == malf[j])
					{
						result[i + 1] = balf[j];
						j = 0;
						break;
					}
				}
			}
			else
			{
				for (int j = 0; j < 25; j++)
				{
					if (result[i + 1] == malf[j])
					{
						result[i + 1] = balf[j];
						j = 0;
						break;
					}
				}
			}
		}
		i++;
	}
	printf("\nYour result:\n%s", result);

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
