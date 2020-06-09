#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

void PrintMenu()
{
	printf("����:\n");
	printf("1.���� ��������� ������ ������������\n");
	printf("2.���������� ��� ������������ \n");
	printf("3.����� ���������\n");
	printf("4.����� �������\n");
	printf("5.��������� ������� ��������� � ��������� �����������\n");
	printf("6.���������� � ������ � ������ ���������\n");
	printf("7.����� �� ���������\n");
}

int GetChoice()
{
	char ch = getchar();
	while (ch > '7' || ch < '1') {
		printf("����� ����� ���\n");
		ch = getchar();
	}
	getchar();
	return ch - '0';
}

void SetCoords(int coord[][2])
{
	for (int i = 0; i < 3; i++)
	{
		printf("������� x%d ", i + 1);
		scanf_s("%d", &coord[i][0]);
		printf("������� y%d ", i + 1);
		scanf_s("%d", &coord[i][1]);
	}
	getchar();
}

void SetLength(int coord[][2], double length[])
{
	length[0] = sqrt(pow((double)coord[0][0] - (double)coord[1][0], 2) + pow((double)coord[0][1] - (double)coord[1][1], 2));
	length[1] = sqrt(pow((double)coord[0][0] - (double)coord[2][0], 2) + pow((double)coord[0][1] - (double)coord[2][1], 2));
	length[2] = sqrt(pow((double)coord[1][0] - (double)coord[2][0], 2) + pow((double)coord[1][1] - (double)coord[2][1], 2));
}

void GetView(double length[])
{
	if (length[0] == length[1] && length[1] == length[2])
	{
		printf("����������\n");
	}
	else if (length[0] == length[1] || length[0] == length[2] || length[1] == length[2])
	{
		printf("��������������\n");
	}
	double hypotenuse = length[0];
	int index = 0;
	for (int i = 1; i < 3; i++)
	{
		if (length[i] > hypotenuse)
		{
			hypotenuse = length[i];
			index = i;
		}
	}
	double sum = 0;
	for (int i = 0;i < 3; i++)
	{
		if (index != i)
		{
			sum += pow(length[i], 2);
		}
	}
	double square = pow(hypotenuse, 2);
	if (square - sum < 0.000001 || square - sum > -0.000001)
	{
		printf("�������������\n");
	}
}

float GetPerimeter(double length[])
{
	float perimeter = 0;
	for (int i = 0; i < 3; i++)
	{
		perimeter += length[i];
	}
	return perimeter;
}

float GetArea(double length[])
{
	float area = 0;
	float p = GetPerimeter(length) / 2;
	area = sqrt(p * (p - length[0]) * (p - length[1]) * (p - length[2]));
	return area;
}

void PrintRadius(double length[])
{
	double p = (double)GetPerimeter(length) / 2;
	double inTriangle, outTriangle = 1;
	inTriangle = (double)GetArea(length) / p;
	printf("������ ��������� ���������� %lf\n", inTriangle);
	for (int i = 0; i < 3; i++)
	{
		outTriangle *= length[i];
	}
	outTriangle /= (double)4 * (double)GetArea(length);
	printf("������ ��������� ���������� %lf\n", outTriangle);
}

void PrintInfo()
{
	printf("���������� ���������, 953505\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	PrintMenu();
	int choice;
	int coord[3][2] = { 0,0,0,0,0,0 };
	double length[3] = { 0,0,0 };
	while (1)
	{
		choice = GetChoice();
		switch (choice)
		{
		case 1:
		{
			SetCoords(coord);
			SetLength(coord, length);
			break;
		}
		case 2:
		{
			GetView(length);
			break;
		}
		case 3:
		{
			printf("Perimeter %.3f\n", GetPerimeter(length));
			break;
		}
		case 4:
		{
			printf("Area %.3f\n", GetArea(length));
			break;
		}
		case 5:
		{
			PrintRadius(length);
			break;
		}
		case 6:
		{
			PrintInfo();
			break;
		}
		case 7:
		{
			return 0;
		}
		}
	}
}