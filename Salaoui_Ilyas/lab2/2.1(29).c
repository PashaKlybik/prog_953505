/*Ремонт. Разработать программу, которая по введенным параметрам
рассчитывает стоимость оклейки обой в комнате. Программа
должна содержать следующее меню:
1 Ввод длины и ширины комнаты (м).
2 Ввод количества окон.
3 Ввод количества дверных проемов.
4 Ввод стоимости обойной трубки ($).
5 Расчет площади оклейки (кв. м).
6 Расчет необходимого количества обойных трубок.
7 Расчет стоимости поклейки (с учетом клея).
8 Выход из программы.*/

//
//  main.c
//  laba 2.1.29
//
//  Created by Ilyass-Emir on 4/23/20.
//  Copyright © 2020 malumba. All rights reserved.
//

#include <stdio.h>


void all(double L,double Wid,int D , int Win, float P)
{
    float area;
    float pipe;
    float price;
    area=((L+Wid)*2*2.6)-(D*0.9*0.25)-(Win*2.15*1.5);
    printf("Area=%f\n",area);
    pipe=area/(0.5*2.6);
    printf("amount of pipes=%f\n",pipe);
    price=0.5*pipe+P*pipe;
    printf("Price=%f$\n",area);
    
    
}



int main(int argc, const char * argv[]) {
    float length,width,price;
    int windows,doors;
    printf("Введите длину команты");
    scanf("%f",&length);
    printf("Введите ширину команты");
    scanf("%f",&width);
    printf("Введите количество дверных проемов");
    scanf("%d",&doors);
    printf("Введите количество окон");
    scanf("%d",&windows);
    printf("Введите цену обойной трубки");
    scanf("%f",&price);
    all(length,width,doors,windows,price);
    
    return 0;
}
/*

░░░░░░░░░░░░░░░░░░░░░░
░░ЗАПУСКАЕМ░░МОЩНОГО░░░
░░░░░░░ГУСЯ-ГИДРУ░░░░░░░
░░░░░▄▀▀▀▄░░░░░░░░ ▄▄░░
▄███▀░◐░▄▀▀▀▄░░░▄▀░░█░
░░▄███▀░◐░░░░▌▄▀░░▄▀░░
░░░░▐░▄▀▀▀▄░░░░░▄▀░░░░
▄███▀░◐░░░░▌░░░░░▀▄░░░
▄▄░▌░░░░░▐▄▄▀▄▄▀▄▀░░░░░░░▄▄
█░░▀▄░░░░▄▀▒▒▀▀▀▀▄░░░░░▄▀░░█
░▀▄░░▀▄░▐▒▒▒▒▒▒▒▒▀▀▄▄▄▄▀░░▄▀
░░░▀▄░░▀▐▄▒▒▒▒▒▒▒▒▒▒▒▒░░▄▀
░░░▄▀░░░░░▀▄▒▒▒▒▒▒▒▒▒▒▒▀▄
░░░▀▄▀▄▄▀▄▄▄█▄▄▄▄▄▄▄▀▄▄▀▄▀
░░░░░░░▌▌░▌▌░▌▌░▌▌░░▌▌░▌▌░
░░░░░░░▌▌░▌▌░▌▌░▌▌░░▌▌░▌▌░
░░░░░▄▄▌▌▄▌▌▄▌▌▄▌▌░▄▌▌▄▌▌░
*/
