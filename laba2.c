#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
double height;
double distance;
void Data_about_Programm() {

	printf("��������� ����������� ������� �������\n");
	printf("������ ��������� 1.0");
	_getch();


}
void Data_analysis() {


	if (distance > 4000 || height < 50) {
		printf("����� �������");
		_getch();
	}
	else {
		printf("����� �������");
		_getch();
	}

	return;
}
void Order_Calculation() {
	int cars = 15;
	int rate = 2;//$
	double price;
	double insurance = 0.05;
	price = height * rate;
	price = price + (price * insurance);
	printf("��������� ������ %g $", price);
	_getch();

}

void EnterHeight() {

	printf("������� ��� �����\n");
	scanf_s("%g", &height);
	return height;


}
int EnterDistance() {

	printf("������� ���������� ���������\n");
	scanf_s("%g", &distance);
	return distance;


}
void PrintMenu() {

	printf("1 - ������� ��� �����\n");
	printf("2 - ������� ���������� ���������\n");
	printf("3 - ������ ������ � ����� ������� � �������� ������\n");
	printf("4 - ������ � ����� ���������� ������\n");
	printf("5 - ���������� � ������ � ������ ���������\n");
	printf("6 - ����� �� ���������\n");




}
void EnterMenu() {

	int num = 0;
	while (num != 6) {
		PrintMenu();
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:EnterHeight();

			break;
		case 2:EnterDistance();
			break;
		case 3:Data_analysis();
			break;
		case 4:Order_Calculation();
			break;
		case 5:Data_about_Programm();
			break;
		case 6:return;
			break;
		default:printf("Error\a");
			break;
		}


		system("cls");
	}


}
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	EnterMenu();

}