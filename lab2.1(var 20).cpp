#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <math.h>
const double pi = 3.14;
void SectorSquare(int R, int a);
void CircleLenght(int R);
void SideOfaSquare(int R);
void ConVolume(int R);
void S(int R);
int main(void)
{
    int R,a;
    printf("Enter R=");
    scanf_s("%d", &R);
l1:
    printf("Enter angle 'a'(degrees)(a<=360)=");
    scanf_s("%d", &a);
    if (a > 360) { printf("Wrong angle"); goto l1; }
    int Menu;
    printf("What do you want?\n");
    printf("1-sector square\n");
    printf("2-circle lenght\n");
    printf("3-side of a square\n");
    printf("4-con volume\n");
    printf("5-Square\n");
    printf("6-info\n");
    printf("7-All info\n");
    l2:
    scanf_s("%d", &Menu);
    switch (Menu)
    {
    case 1: SectorSquare(R, a); break;
    case 2: CircleLenght(R); break;
    case 3: SideOfaSquare(R); break;
    case 4: ConVolume(R); break;
    case 5: S(R); break;
    case 6: printf("\nCreated by Evgeniy"); break;
    case 7:  SectorSquare(R, a); CircleLenght(R); SideOfaSquare(R); ConVolume(R); S(R); printf("\nCreated by Evgeniy"); break;
    default: goto l2;
    }
    return 0;
}
void SectorSquare(int R,int a)
{
    double S;
    S = (pi * pow(R, 2) * a) / 360;
    printf("\nSector square=");
    printf("%f", S);
}
void CircleLenght(int R)
{
    double L;
    L = pi * R * 2;
    printf("\nCircle lenght=");
    printf("%f", L);
}
void SideOfaSquare(int R)
{
    double a;
    a = R * sqrt(2);
    printf("\nSide of a square=");
    printf("%f", a);
}
void ConVolume(int R)
{
    double V;
    V = (pi * pow(R, 2) * R) / 3;
    printf("\nCon volume=");
    printf("%f", V);
}
void S(int R)
{
    double S = pi * pow(R, 2);
    printf("\nS=");
    printf("%f", S);
}