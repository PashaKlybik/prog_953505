#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
double height;
double distance;
void Data_about_Programm() {

	printf("Программа разработана Хвитько Сергеем\n");
	printf("Версия программы 1.0");
	_getch();


}
void Data_analysis() {


	if (distance > 4000 || height < 50) {
		printf("Заказ отклонён");
		_getch();
	}
	else {
		printf("Заказ одобрен");
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
	printf("Стоимость заказа %g $", price);
	_getch();

}

void EnterHeight() {

	printf("Введите вес груза\n");
	scanf_s("%g", &height);
	return height;


}
int EnterDistance() {

	printf("Введите расстояние перевозки\n");
	scanf_s("%g", &distance);
	return distance;


}
void PrintMenu() {

	printf("1 - Введите вес груза\n");
	printf("2 - Введите расстояние перевозки\n");
	printf("3 - Анализ данных и вывод решения о принятии заказа\n");
	printf("4 - Расчет и вывод параметров заказа\n");
	printf("5 - Информация о версии и авторе программы\n");
	printf("6 - Выход из программы\n");




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