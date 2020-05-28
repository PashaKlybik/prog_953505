#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//======================= Вариант 25 =======================
float getnumber();
void coutnumber(float x, float y);
void reversenumber(float x, float y);
void shortnumber(float x, float y);
void titers();
void exit1();
int main()
{
    setlocale(LC_ALL, "rus");
   static int z, d;
   static float x, y;
   printf("Welcome!\n");
ln:    printf("Выберите действие(для выбора введите номер пункта)\n1.Ввести числитель и знаменатель рационального числа\n2.Вывести число в трёх форматах\n3.Вывести обратное введённому число\n4.Вывести введённое число в сокращённом формате\n5.Вывести информацию о версии программы и авторе\n6.Выход из программы\n");
    scanf("%d", &z);
    switch (z)
    {
        case 1:
          {
         x=getnumber();
         y=getnumber();
         if (y==0)
         {
             printf("На ноль делить нельзя\n");
             goto ln;
         }
         d=1;
          break;
          }
        case 2:
         {
         if(d==1) coutnumber(x,y);
         else printf("Введите числитель и знаменатель\n");
         break;
         }
         case 3:
         {
         if(d==1) reversenumber(x,y);
         else printf("Введите числитель и знаменатель");
         break;
         }
         case 4:
         {
         if(d==1) shortnumber(x,y);
         else printf("Введите числитель и знаменатель");
         break;
         }
         case 5:
         {
         titers();
         break;
         }
         case 6:
         {
         exit1();
         goto lm;
         break;
         }
         default:
         {
         printf("Неверный ввод\n");
         }
    }
    goto ln;
lm:    return 0;
}
float getnumber()
{
    int x;
    scanf("%d", &x);
    return x;
}
void coutnumber(float x, float y)
{
    float r=x/y;
    printf("Форма числителя и знаменателя:%d/%d\nДесятичная форма:%f\nНаучная форма:%E\n\n", (int)x, (int)y, r, r);
}
void reversenumber(float x, float y)
{
    float r=y/x;
    printf("Форма числителя и знаменателя:%d/%d\nДесятичная форма:%f\nНаучная форма:%E\n\n", (int)y, (int)x, r, r);
}
void shortnumber(float x, float y)
{
    for (int i=1; i<=x&&i<=y; i++)
    {
        if ((int)x%i==0&&(int)y%i==0)
        {
            x=x/i;
            y=y/i;
        }
    }
    float r=x/y;
    printf("Форма числителя и знаменателя:%d/%d\nДесятичная форма:%f\nНаучная форма:%E\n\n", (int)x, (int)y, r, r);
}
void titers()
{
    printf("Версия программы 1.0\nАвтор программы Шмат Илья\n");
}
void exit1()
{
    printf("Выход из программы...\n");
}
